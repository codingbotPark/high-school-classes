package kr.hs.dgsw.java.dept23.d0324;

import java.util.Scanner;


public class DogNameScanner {
	private Scanner scanner;
	public void prepareScanner() {
		this.scanner = new Scanner(System.in);
	}
	public void closeScanner() {
		this.scanner.close();
	}
	
	// getter
	public Scanner getScanner() {
		return this.scanner;
	}
	
//	public static void main(String args[]) {
//		DogNameScanner scan = new DogNameScanner();
//		scan.prepareScanner();
//		Scanner scanner = scan.getScanner();
//		while (true) {			
//			System.out.print("강아지 이름을 입력하세요 : ");
//			String dogName = scanner.nextLine();
//			Dog dog = new Dog(dogName);
//			if (dogName.equals("quit")) {
//				break;
//			}
//			dog.sayHello();
////			System.out.println(dogName);
//		}
//		System.out.print("프로그램 종료");
//		scan.closeScanner();
//		
//		
//		// 선생님 코드
//		String input = null; 
//		while(true) {
//			System.out.println("강아지 이름을 입력하세요");
//			input = scanner.next();
////			if (input.equals("quit")) {
//			if ("quit".equals(input)) {
//				// 아래의 if문이 input이 null일 때도
//				// 오류없이 작동할 수 있다
//				break;
//			}
//		}
//		
//	}
}
