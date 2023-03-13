package kr.hs.dgsw.java.dept23.d0526;

public class Developer implements Job{

	@Override
	public void work() {
		// TODO Auto-generated method stub
		System.out.println("개발자가 일을하고 있습니다");
	}

	@Override
	public int getPrice() {
		// TODO Auto-generated method stub
		return 20000;
	}
	
}
