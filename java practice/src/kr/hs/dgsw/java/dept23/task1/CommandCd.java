package kr.hs.dgsw.java.dept23.task1;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CommandCd extends AbstractCommand {

	public CommandCd(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
	}

	
	@Override
	public File executeCommand() {
		File returnDir = currentDirectory;
		
		// TODO
		String[] commandArr = commandLine.split(" ", 2);
		
		// 이전으로
		if (commandArr[1].equals("..")) {
			
			
			// window는 \\\\ 로 나눠야 한다
			String[] tempLocationArr = String.valueOf(currentDirectory).split("\\\\");
			
			String temp = "";
			// 현재있는 위치의 마지막 위치를 뺀다
			for (int i = 0;i < tempLocationArr.length - 1;i++) {
				temp = temp  + tempLocationArr[i] + "\\";
			}	
			File dir = new File(temp);
			if (dir.exists()) {
				returnDir = dir;	
			} else {
				System.out.println("cannot find the path");
			}
			
		} else { // 안으로
			File dir = new File(currentDirectory + "\\" + commandArr[1]);
			if (dir.exists() && dir.isDirectory()) {
				returnDir = dir;
			} else {
				System.out.println("cannot find the path");
			}
		}

		return returnDir;

	}


}