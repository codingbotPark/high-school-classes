package NW220425_2;

import java.util.concurrent.Semaphore;

// implements Runnable로 Semaphore을 사용한다
public class ThreadSemaphore implements Runnable{
	
	private int i = 0;
	// sem에 들어오는 n개의 프로세스가 들어가도록 한다
	private Semaphore sem = new Semaphore(2);
	
	public void run() {
		while(i < 500) {
			try {
			sem.acquire();
			// 임계구역 시작
				for (int j =0;j<2000;j++);
				System.out.printf(
						(Thread.currentThread()).getName() + 
						"i = " + i);
				System.out.println();
				i++;
			sem.release(); // 임계구역 종료
			} catch (InterruptedException e) {}
		}
	}
}
