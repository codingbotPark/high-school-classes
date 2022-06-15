package kr.hs.dgsw.java.task1;

import java.io.File;
import java.util.Scanner;

public class Command {
	Scanner scan = new Scanner(System.in);
	String commandLine;
	
	File file;

	
	public void execute() {
		
		
		while(true) {
			System.out.printf(">> ");
			commandLine = scan.nextLine();
				
			// split이 잘 됐는지 확인한다
			if (commandLine.startsWith("search") && commandLine.split(" ").length == 2) {
				Search search = new Search(file,commandLine.split(" ")[1]);
			} else if (commandLine.startsWith("insert") && commandLine.split(" ").length == 2){
				Insert insert = new Insert(file);
			} else if (commandLine.startsWith("delete") && commandLine.split(" ").length == 2) {
				
			} else {
				System.out.println("잘못된 명령어 입니다");
			}
			
		}
	}
	
	public Command(File file) {
		// TODO Auto-generated constructor stub
		System.out.println("**전화번호는 붙여서 입력해주세요**");
		System.out.println("검색 = search [이름/전화번호]");
		System.out.println("등록 = insert [이름] [전화번호]");
		System.out.println("검색 = delete [이름]");
		
		this.file = file;
		execute();
	}
}
