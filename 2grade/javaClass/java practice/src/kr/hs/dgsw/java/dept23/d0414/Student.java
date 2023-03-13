package kr.hs.dgsw.java.dept23.d0414;

public class Student extends People{
	public String school;
	public int classNum;
	private int grade;
	// 부모와 나에게 같은 함수가 있따면 내 함수가 실행된다
	public void showInformation() {
		System.out.printf("name : %s, age : %d, grade : %d\n" ,name,age,grade);
	}
	
	public static void main(String[] args) {
		Student student = new Student();
		student.name = "박병관";
		student.age = 20;
		student.grade = 2;
		student.showInformation();
		
		People people1 = new People();
		people1.name = "박병관";
		people1.age = 18;
		People people2 = new Student();
		people2.name = "손원";
		people2.age = 18;
		
		people1.showInformation();
		people2.showInformation();
	}
	// 실행이 되면 people1은 부모의 showInformation 가 실행,
	// people2은 자식의 showInformation 가 실행된다
	// 이러한 것을 다형성 = polymorphism이라 한다
}
