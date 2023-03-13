package kr.hs.dgsw.java.dept23.d0526;

import java.util.Scanner;


public class AdderWithOutThread {
	private final Scanner scanner;
	
	public AdderWithOutThread() {
		this.scanner = new Scanner(System.in);
	}
	
	public void execute() {
		while (true) {
			System.out.println("두 정수를 입력하세요");
			int value1 = scanner.nextInt();
			int value2 = scanner.nextInt();
			
			// 둘 다 0일 때 프로그램 종료
			if (value1 == 0 && value2 == 0) {
				break;
			}
			
			calculatAndPrint(value1,value2);
		}
		System.out.println("프로그램 종료");
	}
	
	
	
	private void calculatAndPrint(int value1, int value2) {
		
		try {
			Thread.sleep(15000);
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		
		int result = value1 + value2;
		System.out.printf("%d + %d = %d\n",value1,value2,result);
	}
	
	
	public static void main(String[] args) {
		AdderWithOutThread adder = new AdderWithOutThread();
		adder.execute();
	}
	
	// 4 8,
	// 3 2,
	// 5 5 를 했을 때 최소한 15초를 기다려야 한다
}
