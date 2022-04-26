package NW220425_3;
import java.util.concurrent.Semaphore;


public class DiningPhilosopherMain{
	static final int num = 5;
	public static void main(String[] args) {
		int i;

		Semaphore[] stick = new Semaphore[num];
		
		for (i=0; i<num; i++)
			stick[i] = new Semaphore(1);


		ThreadDiningPhilosopher[] phil = new ThreadDiningPhilosopher[num];
		
		for (i=0; i<num; i++) {
			if(i%2==0) {
				phil[i] = new ThreadDiningPhilosopher(i, stick[i], stick[(i+1)%num]);
			} else {
				phil[i] = new ThreadDiningPhilosopher(i, stick[(i+1)%num], stick[i]);
			}
		}


		for (i=0; i<num; i++)
			phil[i].start();
	}

}
