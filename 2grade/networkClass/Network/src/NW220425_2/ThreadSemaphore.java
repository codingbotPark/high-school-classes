package NW220425_2;

import java.util.concurrent.Semaphore;

// implements Runnable�� Semaphore�� ����Ѵ�
public class ThreadSemaphore implements Runnable{
	
	private int i = 0;
	// sem�� ������ n���� ���μ����� ������ �Ѵ�
	private Semaphore sem = new Semaphore(2);
	
	public void run() {
		while(i < 500) {
			try {
			sem.acquire();
			// �Ӱ豸�� ����
				for (int j =0;j<2000;j++);
				System.out.printf(
						(Thread.currentThread()).getName() + 
						"i = " + i);
				System.out.println();
				i++;
			sem.release(); // �Ӱ豸�� ����
			} catch (InterruptedException e) {}
		}
	}
}
