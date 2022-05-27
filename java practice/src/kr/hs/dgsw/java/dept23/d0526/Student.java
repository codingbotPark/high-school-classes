package kr.hs.dgsw.java.dept23.d0526;

// 프로그래밍을 잘하기 위해 디자인 패턴을 공부해야 한다

// 2개의 interface를 받을 수 있다
public class Student implements Job, Export{
	public void work() {
		System.out.println("학생이 공부를 합니다");
	}
	
	public int getPrice() {
		return 0;
	}
	
	public void enjoy() {
		System.out.println("학생이 플라톤의 국가론을 재미삼아 읽습니다");
	}
	
	public static void main(String[] args) {
		// 아래의 방법으로 만들어진 클래스를 사용할 수 있따
		Student student = new Student();
		Job job = (Job)student;
		Export export = (Export)student;
	}
}
