package kr.hs.dgsw.java.dept23.d0616;

public class Simple<T,Q> {
	// 정수
	// int, byte, short, long
	// 실수
	// float double
	
	// char boolean
	
	// 이렇게 8가지의 타입이 있다
	
	// 제네릭을 사용하기 전에는 모든 타입의 부모인 object타입으로 사용했었는데,
	// 이렇게 object를 사용하면, 컴파일 할 때, 값을 뺄 때 좋지 않았다
	
	private T value;
	
	public T getValue() {
		return value;
	}
	
	public void setValue(T value) {
		this.value = value;
	}
	
	public static void main(String[] args) {
		
		// 이렇게 제네릭에 아무 타입도 주지 않는다면 object타입이 들어간다
//		Simple simple = new Simple();
//		simple.setValue(1311);
		
		Simple<Integer,String> simple = new Simple<Integer,String>();
		simple.setValue(1311);
		
		
		// 널 값이 raw에 들어간다
		Simple raw = new Simple();
		// 널 값이 value에 들어갈 수 없다
		int value = (Integer)raw.getValue();
		
		
		// 같은 타입이여야 한다
//		Simple<String> simple3 = new Simple<Integer>();
		
	}
}
