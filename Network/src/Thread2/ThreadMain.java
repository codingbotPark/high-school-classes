package Thread2;

public class ThreadMain {
	public static void main(String[] args) {
		
		
		Thread t1 = new Thread(new Runnable() {
			public void run() {
				for(int i = 0;i<500;i++) {
					System.out.printf("t1 Thread : %d \n", i);
				}
			}
		});
		Thread t2 = new Thread(new Runnable() {
			public void run() {
				for (int i = 0;i<500;i++) {
					System.out.printf("t2 Thread : %d \n", i);
				}
			}
		});
		t1.start();
		t2.start();
		for (int i = 0;i< 500;i++) {
			System.out.printf("main Thread : %d \n", i);
		}
		
		
		// 이 try catch 문 없이 join을 하면 예외처리가 되지 않는다
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// join은 강제로 멈추는 것, 즉 오류이다(interrupt)
			// 그래서 EnterruptedException을 해서 오류를 예외처리 해준다
			e.printStackTrace();
		}
		
		System.out.printf("시스템 종료");
	}
}
