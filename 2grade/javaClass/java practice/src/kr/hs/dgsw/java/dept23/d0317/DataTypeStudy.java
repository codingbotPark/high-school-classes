package kr.hs.dgsw.java.dept23.d0317;

public class DataTypeStudy {
	public void studyInteger() {
		byte btyeType = 127;
		short shortType = 30000;
		int intType = 2100000000;
		long longType = 3000000000L;
	}
	public void studyReal() {
		double doubleValue = 3.1415926;
		float floatValue = 3.1415926F;
		
//		System.out.println(doubleValue);
//		System.out.println(floatValue);
		// �ٻ簪�� ��µǴ� ���� Ȯ���� �� �ִ�
	}
	public void studyBoolean() {
		boolean bool1 = true;
		boolean bool2 = false;
		
			
		
	}
	public void studyChar() {
		char ch = 'a';
		char ch2 = 65;
		
//		for (char i = 0; i< 256;i++) {
//			System.out.printf("%04X %d - %c \n", (int)i,(int)i,i);
//		}
		
		int h1 = '��';
		System.out.println(h1);
		
		for (int i='��';i<'��';i++) {
			System.out.printf("%d - %c", (int)i,i);
		}
	}
	
//	public static void main(String[] args) {
//		DataTypeStudy study = new DataTypeStudy();
////		study.studyReal();
//		study.studyChar();
//	}
}

// �ڹٿ��� ������ Ÿ���� �⺻/���� ������ Ÿ���� �ִ�

// ���� = int�� �⺻�̱� ������ 30���� int���̶�°� �𸣱� ������ L�� ���δ�
// �Ǽ� = double�� �⺻�̱� ������ float���̶�°� �˷��ֱ� ���� f�� ���δ�

// �ν��Ͻ� = ������Ʈ