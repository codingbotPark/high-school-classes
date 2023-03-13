package kr.hs.dgsw.java.dept23.task1;

import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;

public class CommandLs extends AbstractCommand {

	public CommandLs(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
	}

	@Override
	public File executeCommand() {
		
//		System.out.println(commandLine);
		File[] files = currentDirectory.listFiles();
		for (File file : files) {
			System.out.printf(time(file));
			printDIR(file);
			printSize(file);
			System.out.println(file.getName());
		}
		// TODO
		return currentDirectory;
	}
	
	
	// 시간 출력
	public String time(File file) {
		long modifiedTime = file.lastModified();
		return formatDate(new Date(modifiedTime));
	}
	public String formatDate(Date date) {
		SimpleDateFormat dateFormat = 
				new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		return dateFormat.format(date);
	}
	
	
	// 디렉터리일 때 디렉터리 출력
	public void printDIR(File file) {
		if (file.isDirectory()) {
			System.out.printf(" <DIR> ");
		} else {
			System.out.printf("       ");
		}
	}
	
	
	// 파일일 때 파일 크기 출력
	public void printSize(File file) {
		if (file.isFile()) {
			
			String[] units = {"","K","M","G","T"};
			long size = file.length();
			int i = 0;
			for (i = 0;size > 1024;i++) {
				size/=1024;
			}
			// size와 단위를 합침
			String finSize = size + units[i];
			System.out.printf(" %5s ",finSize);
		} else {
			System.out.printf("       ");
		}
	}

	
	
}