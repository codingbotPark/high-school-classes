package kr.hs.dgsw.java.dept23.task1;

import java.io.File;

public class CommandExit extends AbstractCommand {

	public CommandExit(File currentDirectory, String commandLine) {
		super(currentDirectory, commandLine);
	}

	@Override
	public File executeCommand() {
		System.out.println("Terminating simple commander");
		return this.currentDirectory;
	}

	@Override
	public boolean isExitCondition() {
		return true;
	}
}
