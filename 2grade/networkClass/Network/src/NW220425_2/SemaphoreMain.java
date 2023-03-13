package NW220425_2;

public class SemaphoreMain {
	public static void main(String[] args) {
		ThreadSemaphore m1 = new ThreadSemaphore();
		
		Thread t1 = new Thread(m1,"t1");
		Thread t2 = new Thread(m1,"t2");
		Thread t3 = new Thread(m1,"t3");
	}
}
