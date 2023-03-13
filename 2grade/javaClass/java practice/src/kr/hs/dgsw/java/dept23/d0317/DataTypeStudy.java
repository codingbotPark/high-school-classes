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
		// 근사값이 출력되는 것을 확인할 수 있다
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
		
		int h1 = '가';
		System.out.println(h1);
		
		for (int i='가';i<'갸';i++) {
			System.out.printf("%d - %c", (int)i,i);
		}
	}
	
//	public static void main(String[] args) {
//		DataTypeStudy study = new DataTypeStudy();
////		study.studyReal();
//		study.studyChar();
//	}
}

// 자바에서 데이터 타입은 기본/참조 데이터 타입이 있다

// 정수 = int가 기본이기 때문에 30억은 int형이라는걸 모르기 때문에 L을 붙인다
// 실수 = double이 기본이기 때문에 float형이라는걸 알려주기 위해 f를 붙인다

// 인스턴스 = 오브젝트