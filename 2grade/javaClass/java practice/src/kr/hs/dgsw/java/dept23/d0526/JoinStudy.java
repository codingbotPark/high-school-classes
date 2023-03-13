package kr.hs.dgsw.java.dept23.d0526;

import java.util.Random;

public class JoinStudy implements Runnable{
	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println("자식 스레드가 일을 합니다");
		
		try {
			Thread.sleep(new Random().nextInt(3000) + 1000);
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		
		System.out.println("자식 스레드가 일을 끝마칩니다");
	}
	
	public static void main(String[] args) {
		System.out.println("메인 스레드가 시작합니다");
		
		Thread child = new Thread(new JoinStudy());
		
		child.setDaemon(false);
		// Daemon을 true로 하면 부모가 true가 되면 자식도 종료가 된다
		// 일반적으로 thread에 아무 것도 안 주면 부모가 끝나건 안 끝나건 따로 일을 한다
	
		
		child.start();
		
//		
//		try {
//			// join은 join 한 스레드가 끝날 때 까지 join에서 기다리는 것이다
//			child.join();
//		} catch (InterruptedException e) {
//			// TODO: handle exception
//		}
//		
		System.out.println("메인 스레드가 종료됩니다");
		
	}
}
