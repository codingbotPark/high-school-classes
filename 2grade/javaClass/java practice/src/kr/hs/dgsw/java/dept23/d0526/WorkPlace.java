package kr.hs.dgsw.java.dept23.d0526;

public class WorkPlace {
	public void doWorking(Job job, int hours) {
		for (int i = 0;i<hours;i++) {
			job.work();
		}
		int salary = hours * job.getPrice();
		System.out.printf("급료를 %d원 받았습니다",salary);
	}
	
	public static void main(String[] args) {
		Job developer = new Developer();
		Job son = new Sonheongmin();
		Job student = new Student();
		
		WorkPlace workPlace = new WorkPlace();
		workPlace.doWorking(student, 16);
		workPlace.doWorking(developer, 8);
		workPlace.doWorking(son, 6);
	}
}


 
