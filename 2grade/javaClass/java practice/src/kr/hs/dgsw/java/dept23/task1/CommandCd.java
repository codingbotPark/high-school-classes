package kr.hs.dgsw.java.dept23.task1;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CommandCd extends AbstractCommand {

	public CommandCd(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
	}
	
	public File moveFile(String path) {
		File dir = new File(currentDirectory + "\\" + path);
		// canonicalPath 생성에 실패했을 때를 위해 returnDir 생성을 try 전에 해줌
		File returnDir = currentDirectory;
		try {
			returnDir = new File(dir.getCanonicalPath());
			if (!(returnDir.exists() && dir.isDirectory())) {
				System.out.println("cannot find the path");
				returnDir = currentDirectory;
			} 
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		return returnDir;
	}

	@Override
	public File executeCommand() {
		// 기본적인 return 은 현재
		File returnDir = currentDirectory;

		// cd 다음 명령어가 들어왔는지(cd가 2글자여서 2)
		if (commandLine.indexOf(" ", 2) != -1) {
			// commandLine을 [명령어] [추가정보] 로 나눔
			String[] commandArr = commandLine.split(" ", 2);
			returnDir = moveFile(commandArr[1]);
		}

		// TODO
		return returnDir;

	}

}