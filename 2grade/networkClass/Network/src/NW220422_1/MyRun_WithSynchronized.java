package NW220422_1;

public class MyRun_WithSynchronized implements Runnable {
	private int i=0;
	public void run() {
		while(i<500) {
			show();
		}
	}
	
	public synchronized void show() {

			for(int j=0;j<2000;j++);
			System.out.printf((Thread.currentThread()).getName() + " i = " + i);
			System.out.println();
			i++;

	}
}
