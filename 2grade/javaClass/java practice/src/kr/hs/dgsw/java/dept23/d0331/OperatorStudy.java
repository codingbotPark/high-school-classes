package kr.hs.dgsw.java.dept23.d0331;

public class OperatorStudy {
	public void studyArithmeticOperators() {
		int value;
		
		value = 3 + 4;
		value = 3 - 4;
		value = 3 * 4;
		value = 3/ 4;
		value = 3 % 4;
		
		value += 1;
		value -= 4;
		value *= 4;
		value /= 4;
		value %= 4;
		
		int value1 = ++value;
		value1 = value--;
	
	}
	
	// 비교연산자
	public void studyComparisionOperators() {
		boolean flag;
		flag = 3 > 4;
		flag = 3 < 4;
		flag = 3 >= 4;
		flag = 3 <= 4;
		
		flag = 3== 4;
		flag = 3 != 4;
	}
	
	public void studyLogicalOperators() {
		int value;
		value = 3 & 2;
		value = 3 | 2;
		// 2진수로 나타내고, && 와 || 을 수행한다
		
		// xor = ^ 서로 다를 때 참
		value = 3 ^ 2;
		
		// 한 칸을 왼쪽으로 shift하면 X 2가 된다
		value = 1 << 2;
		
		// / 2 한 효과를 가진다
		byte value1 = -128;
		byte result = (byte)((byte) value1 >> 1);
		
		
	}
	
	
	
	
	
}
