package kr.hs.dgsw.java.dept23.d0526;

import java.util.Random;

// 스레드가 흘러갈 때
// 중간에 별도의 스레드를 분기를 시킨다
// 쓰레드를 상속받는다
public class FirstThread extends Thread{
	
	private final String name;
	
	public FirstThread(String name) {
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
		FirstThread nadal= new FirstThread("나달");
		FirstThread son = new FirstThread("손흥민");
		
		//nadal.run();
		//son.run();
		// 새로운 스레드가 만들어지지 않는다
		// run 대신 start를 해준다
		nadal.start();
		son.start();
		
		// 상속은 항상 다중 상속의 문제가 있따
		// 그래서 implement가 필요하다
	}
}
