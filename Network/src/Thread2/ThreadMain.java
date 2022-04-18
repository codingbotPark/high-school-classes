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
		
		
		// �� try catch �� ���� join�� �ϸ� ����ó���� ���� �ʴ´�
		try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// join�� ������ ���ߴ� ��, �� �����̴�(interrupt)
			// �׷��� EnterruptedException�� �ؼ� ������ ����ó�� ���ش�
			e.printStackTrace();
		}
		
		System.out.printf("�ý��� ����");
	}
}
