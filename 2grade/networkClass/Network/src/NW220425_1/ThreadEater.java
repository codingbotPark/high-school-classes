package NW220425_1;

public class ThreadEater extends Thread{
	private CakePlate cake;
	
	public ThreadEater(CakePlate cake) {
		this.cake = cake;
	}
	
	public void run() {
		for (int i = 0;i<50;i++) {
			cake.eatBread();
		}
	}
}
