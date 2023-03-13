package NW220425_4;

public class TeacherCakeEater extends Thread{
	private TeacherCakePlate cake;
	
	public TeacherCakeEater(TeacherCakePlate cake) {
		this.cake = cake;
	}
	
	public void run() {
		for (int i = 0;i<50;i++) {
			cake.eatBread();
		}
	}
}
