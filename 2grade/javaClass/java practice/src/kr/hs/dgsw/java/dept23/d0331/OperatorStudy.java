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
	
	// �񱳿�����
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
		// 2������ ��Ÿ����, && �� || �� �����Ѵ�
		
		// xor = ^ ���� �ٸ� �� ��
		value = 3 ^ 2;
		
		// �� ĭ�� �������� shift�ϸ� X 2�� �ȴ�
		value = 1 << 2;
		
		// / 2 �� ȿ���� ������
		byte value1 = -128;
		byte result = (byte)((byte) value1 >> 1);
		
		
	}
	
	
	
	
	
}
