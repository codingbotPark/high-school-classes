package kr.hs.dgsw.java.dept23.d0519;

public class ExceptionStudy{
	public void method1() throws MyException{
		System.out.println("method1 호출됨");
		
		// 예외를 발생
		MyException exception = new MyException();
		// 예외를 발생시키면 예외를 처리해줘야한다
		throw exception;
		// 예외를 발생시키고 이 메소드를 부른 클래스에서 예외를 처리하도록 한다
		// 선언부에 MyException을 throw해서 호출하는 클래스에서 처리하도록 할 수 있다
	}
	
	public void method2() {
		try {
			method1();
			// MyException으로 예외가 처리되는 것을 확인할 수 있다
		} catch (MyException e) {
			// TODO Auto-generated catch block
			
			// StackTrace
			e.printStackTrace();
		}
	}
	
	public void method3() {
		MyRuntimeException exception = new MyRuntimeException();
		throw exception;
		
		// runTimeException을 상속받아서 커스텀 Exception을 사용하면
	}
	
	public static void main(String[] args) {
		new ExceptionStudy().method2();
	}
}
