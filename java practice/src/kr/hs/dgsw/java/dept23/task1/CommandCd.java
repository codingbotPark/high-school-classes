package kr.hs.dgsw.java.dept23.task1;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CommandCd extends AbstractCommand {

	public CommandCd(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
	}
	
	// cd .. 했을 때
	public File goToBack() {
		StringBuffer currentDirectoryPath = new StringBuffer(currentDirectory.getAbsolutePath());
		for (int i = currentDirectoryPath.length()-1;i>0;i--) {
			if(currentDirectoryPath.charAt(i) == '\\') {
				// 안 되면 슬레쉬 없애기
				break;
			} else {
				currentDirectoryPath.deleteCharAt(i);
			}
		}
		
		// StringBuffer를 String으로 바꾸고 File로 변환시켜서 return
		String temp = new String(currentDirectoryPath);
		File dir = new File(temp);
		
		return dir;
	}
	
	// cd로 안으로 갈 때
	public File goToIn(String path) {
		File dir = new File(currentDirectory + "\\" + path);
		if (dir.exists() && dir.isDirectory()) {
			return dir;
		} else {
			System.out.println("cannot find the path");
			// 없는 디렉토리면 현제 디렉토리를 리턴
			return currentDirectory;	
		}
	}


	
	@Override
	public File executeCommand() {
		// 기본적인 return 은 현재
		File returnDir = currentDirectory;
		
		// cd 다음 명령어가 들어왔는지(cd가 2글자여서 2)
		if (commandLine.indexOf(" ",2) != -1) {
			//commandLine을 [명령어] [추가정보] 로 나눔
			String[] commandArr = commandLine.split(" ",2);
			if (commandArr[1].equals("..")) {
				returnDir = goToBack();
			} 
			else{
				returnDir = goToIn(commandArr[1]);
			}
		}
		
		// TODO
		return returnDir;

	}


}