package kr.hs.dgsw.java.dept23.d0602;

import java.util.Random;

public class Producer implements Runnable{
	private final Buffer buffer;
	
	public Producer(Buffer buffer) {
		// TODO Auto-generated constructor stub
		this.buffer = buffer;
	}
	
	@Override
	public void run() {
		
		Random random = new Random();
		
		// TODO Auto-generated method stub
		while(true) {
			try {
				Thread.sleep(1000 + random.nextInt(2000));
			} catch (InterruptedException e) {
				// TODO: handle exception
				e.printStackTrace();
			}
			// 버퍼에 랜덤한 수를 넣어준다
			int value = random.nextInt();
			buffer.add(value);
		}
		
	}
}
