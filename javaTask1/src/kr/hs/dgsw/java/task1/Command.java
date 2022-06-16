package kr.hs.dgsw.java.task1;

import java.io.File;
import java.util.Scanner;

public class Command {
	Scanner scan = new Scanner(System.in);
	String commandLine;

	File file;

	public boolean isString(String keyword) {
		char keywordFirst = keyword.charAt(0);
		if (keywordFirst > 47 && keywordFirst < 58) {
			return false;
		} else {
			return true;
		}
	}
	
	public boolean checkCommand(String commandLine,int splitNum,boolean checkType ) {
		if (commandLine.split(" ").length == splitNum) {
			// checkType이 true면 commandLine의 [1] 이 이름인지 확인한다(insert,delete)
			if (checkType) {
				if (isString(commandLine.split(" ")[1])) {
					return true;
				}
			} else {
				return true;
			}
		}
		return false;
	}

	public void execute() {

		while (true) {
			System.out.printf(">> ");
			commandLine = scan.nextLine();

			// split이 잘 됐는지 확인한다
			if (commandLine.startsWith("search") && checkCommand(commandLine,2,false)) {
				DoSearch doSearch = new DoSearch(file, commandLine.split(" ")[1]);
			} else if (commandLine.startsWith("insert") && checkCommand(commandLine,3,true)) {
				DoInsert doInsert = new DoInsert(file,commandLine.split(" ",2)[1]);
			} else if (commandLine.startsWith("delete") && checkCommand(commandLine,2,true)) {
				DoDelete doDelete = new DoDelete(file,commandLine.split(" ",2)[1]);
			} else {
				System.out.println("잘못된 명령어 형식 입니다");
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
