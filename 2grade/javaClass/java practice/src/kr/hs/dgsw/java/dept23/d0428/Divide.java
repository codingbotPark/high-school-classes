package kr.hs.dgsw.java.dept23.d0428;

public class Divide extends Calculator{

	@Override
	public int calculate() {
		// TODO Auto-generated method stub
		return this.value1 / this.value2;
	}

	@Override
	public String getOperator() {
		// TODO Auto-generated method stub
		return "/";
	}
	
	@Override
	public boolean isExitCondition() {
		// TODO Auto-generated method stub
		return (value2 == 0);
	}
	
	public static void main(String[] args) {
		Calculator divide = new Divide();
		divide.execute();
	}
	
}
