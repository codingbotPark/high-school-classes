package kr.hs.dgsw.java.dept23.task1;

import java.io.File;
import java.util.Scanner;

public class CommandRm extends AbstractCommand {
	File targetFile;
	

	public CommandRm(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
		targetFile = new File(currentDirectory + "\\" + commandLine.split(" ")[1]);
	}

	@Override
	public File executeCommand() {
		if (targetFile.exists()) { // 파일이 존재할 때 삭제
			if (confirmCommand()) {
				if (!targetFile.delete()) {
					System.out.println("파일 삭제에 실패했습니다");
				}
			}
		} else {
			System.out.println("존재하지 않는 파일입니다");
		}

		// TODO Auto-generated method stub
		return currentDirectory;
	}

	// 정말 삭제할 것인지 물어본다
	public boolean confirmCommand() {
		Scanner scan = new Scanner(System.in);
		System.out.printf("정말 파일을 삭제할 것입니까?(y or Y) : ");
		String answer = scan.nextLine();
		if (answer.equals("Y") || answer.equals("y")) {
			return true;
		} else {
			System.out.println("**y,Y 가 아닌 명령어가 입력되어 파일삭제가 취소되었습니다**");
		}
		return false;
	}
}
