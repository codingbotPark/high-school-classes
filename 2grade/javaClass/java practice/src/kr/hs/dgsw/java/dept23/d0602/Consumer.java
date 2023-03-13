package kr.hs.dgsw.java.dept23.d0602;

public class Consumer implements Runnable {

	private final Buffer buffer;

	public Consumer(Buffer buffer) {
		// TODO Auto-generated constructor stub
		this.buffer = buffer;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true) {
			// 버퍼가 무언갈 하기를 기다린다
			// 기다리지 않는다면 busy wait를 해야한다
			synchronized (buffer) {
				try {
					buffer.wait();

					// 깨어나면
					int value = buffer.get();
					System.out.println("숫자" + value + "을 처리합니다");

				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();

				}
				// 버퍼가 날 깨워주기를 대기
			}
			
		}
	}
}
