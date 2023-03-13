package kr.hs.dgsw.java.dept23.d0324;

import java.util.Scanner;

public class Calculator {
	private final String operator;
	private final Scanner scanner;
	
	public Calculator(String operator) {
		this.operator = operator;
		this.scanner = new Scanner(System.in);
	}
	
	public int calculate(int operand1, int operand2) {
		if ("+".equals(operator)) {
			return operand1 + operand2;
		} else if ("-".equals(operator)) {
			return operand1 - operand2;
		} else if ("*".equals(operator)) {
			return operand1 * operand2;
		} else if ("/".equals(operator)) {
			return operand1 / operand2;
		} else if ("%".equals(operator)) {
			return operand1 % operand2;
		} else {
			throw new RuntimeException("Unknown operator");
		}

	}
	
	public void printResult(int operand1, int operand2) {
		int result = calculate(operand1,operand2);
		System.out.printf("%d %s %d = %d\n",operand1,operator,operand2,result);
	}
	
	public void execute() {
		while(true) {
			
			System.out.print("정수를 두 개 입력하세요 : ");
			int operand1 = scanner.nextInt();
			int operand2 = scanner.nextInt();
			if (operand1 == 0 && operand2 == 0) {
				break;
			}
			printResult(operand1,operand2);
			
		}
		scanner.close();
	}
	
	public static void main(String args[]) {
		if (args.length != 1) {
			System.out.println("적용할 연산 기호를 입력하세요");
			throw new RuntimeException();
		}
		Calculator calculator = new Calculator(args[0]);
		calculator.execute();
		
//		System.out.print("연산자를 입력하세요");
	}
}
