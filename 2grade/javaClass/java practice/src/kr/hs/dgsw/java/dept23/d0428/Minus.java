package kr.hs.dgsw.java.dept23.d0428;

public class Minus extends Calculator{

	@Override
	public int calculate() {
		// TODO Auto-generated method stub
		return this.value1 - this.value2;
	}

	@Override
	public String getOperator() {
		// TODO Auto-generated method stub
		return "-";
	}
	
	public static void main(String[] args) {
		Calculator minus = new Minus();
		minus.execute();
	}
}
