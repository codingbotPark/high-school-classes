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
		String[] name = {"Á¤Àº¼­","°­¼ºÈÆ","°í¿ëºó","±âÁØ","±è¹Î¼º","·ùÁöÈÆ","¹Úº´°ü","¹Ú¼ºÇÑ","¹ÚÁö°Ç","¹ÚÇö¿ì","¼Õ¿ø","¾ÈÂù","¿ì»ó¹ü","À±º´ÈÆ","À±¼­ÁØ", "ÀÌ½Â¹Î", "ÀÌÁöÈ£","ÃÖ¹ÎÀç","ÇÑ»óºó"};
		if (num > 0 && num < 20) {			
			return name[num - 1];
		} else {
			return "¾ø´Â ¹øÈ£ÀÔ´Ï´Ù";
		}
		
	}
	
	// staticÀº Å¬·¡½º¿¡ °è¼Ó ÀÖ°Ô ÇÑ´Ù
	public static void main(String[] args) {		
		Task task = new Task();
		task.prepareScanner();
		Scanner scanner = task.getScanner();
		int number = scanner.nextInt();
		
		System.out.printf("¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä : ");
		System.out.println(task.findStudent(number));
		task.closeScanner();
	}
}
