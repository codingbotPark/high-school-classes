package kr.hs.dgsw.java.dept23.d0428;

import java.util.Scanner;

public abstract class Calculator {
	// 추상을 사용하여 만들기
	protected final Scanner scanner;
	
	protected int value1;
	
	protected int value2;
	
	public Calculator() {
		this.scanner = new Scanner(System.in);
	}
	
	
	public void execute() {
//		// 두 정수를 입력받는다
//		this.inputValues();
//		
//		// 계산을 수행한다
//		int result = this.calculate();
//		
//		// 결과를 출력한다
//		this.showResult(result);
		while(true) {
			this.inputValues();
			
			// 아래와 같은 코드들은 지저분해진다
//			if (getOperator().equals("/")) {
//				if (value2 == 0) {
//					break;
//				}
//			}
//			if (value1 == 0 && value2 == 0) {
//				break;
//			}
			
			if (isExitCondition()) {
				break;
			}
			
			int result = this.calculate();
			this.showResult(result);
		}
			
			
		this.scanner.close();
		System.out.println("프로그램을 종료합니다");
	}
	
	public void inputValues() {
		System.out.println("두 정수를 입력하세요");
		this.value1 = this.scanner.nextInt();
		this.value2 = this.scanner.nextInt();
	}
	
	public abstract int calculate();
	
	public void showResult(int result) {
		System.out.printf("%d %s %d = %d\n", value1,getOperator(),value2,result);
	}
	
	public abstract String getOperator();
	
	public boolean isExitCondition() {
		return (value1 == 0 && value2 == 0);
	}
}















