package kr.hs.dgsw.java.dept23.d0428;

public class Adder extends Calculator{
	// 추상화 메소드가 없어서 Class에 오류가 날 때 
	// Ctrl + 1 을 눌러서 추상화 메소드를 자동을 추가시킬 수 있다
	
	@Override
	public int calculate() {
		// TODO Auto-generated method stub
		return this.value1 + this.value2;
	}

	@Override
	public String getOperator() {
		// TODO Auto-generated method stub
		return "+";
	}
	
	public static void main(String[] args) {
		Calculator adder = new Adder();
		adder.execute();
	}
}
