package kr.hs.dgsw.java.dept23.d0512;

import java.io.File;
import java.util.Scanner;

public class ToggleFile {
	String fileName;
	File file;
	
	public void scanName() throws Exception{
		System.out.printf("생성할 파일 이름을 입력하세요 ");
		Scanner scanner = new Scanner(System.in);
		this.fileName = scanner.next();
	}
	
	public void toggleFile() throws Exception {
		this.file = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\"+fileName+".txt");
		boolean created = file.createNewFile();
		
		if (created) {
			System.out.println("파일 생성에 성공함");
		} else {
			System.out.println("이미 있는 파일입니다");
			removeFile();
		}
		
	}

	public void removeFile() throws Exception{
		boolean deleted = file.delete();
		if (deleted) {
			System.out.println("파일 삭제에 성공함");
		} else {
			System.out.println("파일 삭제에 실패함");
		}
	}

	
	public static void main(String[] args) throws Exception {
		ToggleFile start = new ToggleFile();
		start.scanName();
		start.toggleFile();
	}
}
