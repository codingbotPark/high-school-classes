package kr.hs.dgsw.java.dept23.d0331;
import java.util.*;

public class Aliquot {
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
	
	public String findAliquots(int value) {
		String result = "";
		for (int i = 1;i<value;i++) {
			if (value % i == 0) {
				result = result+i+", ";
			}
		}
		result=result+" "+value;
		return result;
	}

	
	public static void main(String args[]) {
		long check1 = System.currentTimeMillis();
		
		Aliquot task2 = new Aliquot();
		task2.prepareScanner();
		Scanner scanner = task2.getScanner();
		System.out.printf("약수를 찾을 수를 입력하세요 : ");
		int temp = scanner.nextInt();
		System.out.println(task2.findAliquots(temp));
		
		task2.closeScanner();
		
		long check2 = System.currentTimeMillis();
		System.out.println(check2 - check1);
	}
	
	
}
