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
//			System.out.print("������ �̸��� �Է��ϼ��� : ");
//			String dogName = scanner.nextLine();
//			Dog dog = new Dog(dogName);
//			if (dogName.equals("quit")) {
//				break;
//			}
//			dog.sayHello();
////			System.out.println(dogName);
//		}
//		System.out.print("���α׷� ����");
//		scan.closeScanner();
//		
//		
//		// ������ �ڵ�
//		String input = null; 
//		while(true) {
//			System.out.println("������ �̸��� �Է��ϼ���");
//			input = scanner.next();
////			if (input.equals("quit")) {
//			if ("quit".equals(input)) {
//				// �Ʒ��� if���� input�� null�� ����
//				// �������� �۵��� �� �ִ�
//				break;
//			}
//		}
//		
//	}
}
