package Thread;

// 작업을 만드는 것
public class MultiThread2 implements Runnable{
	public void run() {
		for (int i = 0;i<500;i++) {
			System.out.printf("t2 thread : %d \n", i);	
		}
	}
}
