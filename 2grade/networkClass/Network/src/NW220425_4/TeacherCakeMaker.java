package NW220425_4;

public class TeacherCakeMaker extends Thread{
	private TeacherCakePlate cake;
	
	public TeacherCakeMaker(TeacherCakePlate cake) {
		this.cake = cake;
	}
	
	public void run() {
		for(int i = 0;i<50;i++) {
			cake.makeBread();
		}
	}
}
