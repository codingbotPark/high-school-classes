package Thread;

// �۾��� ����� ��
//public class MultiThread1 implements Runnable{
public class MultiThread1 extends Thread{
	public void run() {
		for (int i = 0;i<500;i++) {
			System.out.printf("t1 thread : %d \n", i);	
		}
	}
}
