package kr.hs.dgsw.java.dept23.d0428;

public class Adder extends Calculator{
	// �߻�ȭ �޼ҵ尡 ��� Class�� ������ �� �� 
	// Ctrl + 1 �� ������ �߻�ȭ �޼ҵ带 �ڵ��� �߰���ų �� �ִ�
	
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
