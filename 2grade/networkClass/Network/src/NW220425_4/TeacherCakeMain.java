package NW220425_4;

public class TeacherCakeMain {
	public static void main(String[] args) {
		TeacherCakePlate cake = new TeacherCakePlate();
		TeacherCakeEater eater = new TeacherCakeEater(cake);
		TeacherCakeMaker baker = new TeacherCakeMaker(cake);
		
		baker.start();
		eater.start();
	}
}
