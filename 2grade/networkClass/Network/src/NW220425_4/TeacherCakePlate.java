package NW220425_4;

public class TeacherCakePlate {
	private int breadCount = 0;
	public TeacherCakePlate() {}.
	
	public synchronized void makeBread() {
		if (breadCount >= 10) {
			try {
				System.out.println("»§ÀÌ ³²´Â´Ù");
				wait();
			} catch (InterruptedException ire) {}
		}
		
		breadCount++;
		System.out.println("»§À» 1°³ ´õ ¸¸µê ÃÑ" + breadCount + "°³");
		this.notifyAll();
		
	}
	
	public synchronized void eatBread() {
		if (breadCount < 1 ) {
			try {
				System.out.println("»§ÀÌ ¸ðÀÚ¶ó ±â´Ù¸²");
				wait();
			} catch (InterruptedException ire) {}
		}
		
		breadCount--;
		System.out.println("»§À» 1°³ ¸ÔÀ½ ÃÑ : "+breadCount+"°³");
		this.notifyAll();
	}
}
