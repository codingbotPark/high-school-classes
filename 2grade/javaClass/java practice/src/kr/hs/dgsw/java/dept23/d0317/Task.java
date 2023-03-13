package kr.hs.dgsw.java.dept23.d0317;
import java.util.Scanner;

public class Task {
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
	
	public static void main(String args[]) {
		Task task = new Task();
		task.prepareScanner();
		Scanner scanner = task.getScanner();
		while(true) {
			System.out.printf("숫자 입력");
			int intValue = scanner.nextInt();
			if (intValue == -1) {
				break;
			}
			System.out.printf("%c\n",intValue);
		}
		task.closeScanner();
	}
}
