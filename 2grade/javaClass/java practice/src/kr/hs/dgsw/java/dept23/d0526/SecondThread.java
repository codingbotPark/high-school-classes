package kr.hs.dgsw.java.dept23.d0526;

import java.util.Random;

public class SecondThread implements Runnable{
	
	private final String name;
	
	public SecondThread(String name) {
		// TODO Auto-generated constructor stub
		this.name = name;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0;i<10;i++) {
			System.out.printf("%s : %d\n",name,i);
			try {
				Thread.sleep(new Random().nextInt(1000) + 1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public static void main(String[] args) {
		SecondThread nadal= new SecondThread("나달");
		SecondThread son = new SecondThread("손흥민");
		
		Thread nadalThread = new Thread(nadal);
		nadalThread.start();
		
		new Thread(son).start();
	}
}
