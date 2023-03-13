package kr.hs.dgsw.java.dept23.d0407;
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
	
	public String findStudent(int num) {
		String[] name = {"������","������","����","����","��μ�","������","�ں���","�ڼ���","������","������","�տ�","����","����","������","������", "�̽¹�", "����ȣ","�ֹ���","�ѻ��"};
		if (num > 0 && num < 20) {			
			return name[num - 1];
		} else {
			return "���� ��ȣ�Դϴ�";
		}
		
	}
	
	// static�� Ŭ������ ��� �ְ� �Ѵ�
	public static void main(String[] args) {		
		Task task = new Task();
		task.prepareScanner();
		Scanner scanner = task.getScanner();
		int number = scanner.nextInt();
		
		System.out.printf("��ȣ�� �Է��ϼ��� : ");
		System.out.println(task.findStudent(number));
		task.closeScanner();
	}
}
