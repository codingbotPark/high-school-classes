package kr.hs.dgsw.java.task1;

import java.io.File;
import java.util.Scanner;

public class Command {
	Scanner scan = new Scanner(System.in);
	String commandLine;

	File file;
	
	// 47, 58
	public boolean checkValue(String keyword,int askStart, int askEnd) {
		char keywordFirst = keyword.charAt(0);
		if (keywordFirst > askStart && keywordFirst < askEnd) {
			return true;
		} else {
			return false;
		}
	}

	// 명령어가 인자로 저장된 아스키 값 사이의 값인지 확인
	public boolean checkWordNum(String commandLine,int splitNum) {
		if (commandLine.split(" ").length == splitNum) {
			return true;
		}
		return false;
	}

	public void execute() {

		while (true) {
			System.out.printf(">> ");
			commandLine = scan.nextLine();

			String[] command = commandLine.split(" ");
			
			// split이 잘 됐는지 확인한다
			if (commandLine.startsWith("search") && checkWordNum(commandLine,2)) {
				DoSearch doSearch = new DoSearch(file,commandLine.split(" ",2)[1]);
				// insert 비교 끝내기
			} else if (commandLine.startsWith("insert") && checkWordNum(commandLine,3) &&
					checkValue(command[2],47,58) && checkValue(command[1],128,100000)) {				
					DoInsert doInsert = new DoInsert(file,commandLine.split(" ",2)[1]);
			} else if (commandLine.startsWith("delete") && checkWordNum(commandLine,2)) {
				DoDelete doDelete = new DoDelete(file,commandLine.split(" ",2)[1]);
				
			} else if(commandLine.startsWith("quit") && checkWordNum(commandLine,1)) {
				scan.close();
				System.out.println("**시스템이 종료되었습니다**");
				System.exit(0);
			}
			
			else {
				System.out.println("잘못된 명령어 형식 입니다");
			}

		}
	}

	public Command(File file) {
		// TODO Auto-generated constructor stub
		System.out.println("**전화번호는 붙여서 입력해주세요**");
		System.out.println("검색 = search [이름/전화번호/*]");
		System.out.println("등록 = insert [이름] [전화번호]");
		System.out.println("검색 = delete [이름]");
		System.out.println("종료 = quit");
		System.out.println("**********************");

		this.file = file;
		execute();
	}
}
