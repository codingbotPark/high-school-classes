package Thread;

public class MultiThreadMain {
	public static void main(String[] args) {
		MultiThread1 mil = new MultiThread1();
		Thread t1 = new Thread(mil);
		
		MultiThread2 mi2 = new MultiThread2();
		Thread t2 = new Thread(mi2);
		
		t1.start();
		t2.start();
		
		for (int i = 0;i<500;i++) {
			System.out.printf("main Thread : %d \n", i);
		}
		
		// t1, t2, main Thread ���� ������ ������ �����ư��� ��µǴ� ���� Ȯ���� �� �ִ�
	}
}
