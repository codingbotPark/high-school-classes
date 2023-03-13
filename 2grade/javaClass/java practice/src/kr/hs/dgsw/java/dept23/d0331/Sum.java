package kr.hs.dgsw.java.dept23.d0331;
import java.util.Scanner;
public class Sum {
	private Scanner scanner;
	public void prepareScanner() {
		this.scanner = new Scanner(System.in);
	}
	public void closeScanner() {
		this.scanner.close();
	}
	public Scanner getScanner() {
		return this.scanner;
	}
	
	public int plus1(int num) {
		int result = 0;
		for (int i =1;i<=num;i++) {
			result += i;
		}
		return result;
	}
	public int plus2(int num1, int num2) {
		int result = 0;
		for (int i = num1;i<=num2;i++) {
			result += i;
		}
		return result;
	}
	
	public static void main(String args[]) {
		Sum task1 = new Sum();
		task1.prepareScanner();
		Scanner scanner = task1.getScanner();
		System.out.printf("ù ��° Ŭ������ ���� ���� �Է��ϼ��� : ");
		int temp = scanner.nextInt();
		System.out.printf("ù ��° ����� = %d\n",task1.plus1(temp));
		
		System.out.printf("�� ��° Ŭ������ ���� ���� �Է��ϼ��� : ");
		int temp1 = scanner.nextInt();
		int temp2 = scanner.nextInt();
		System.out.printf("�� ��° ����� = %d", task1.plus2(temp1, temp2));
		
		task1.closeScanner();		
	}
}	
