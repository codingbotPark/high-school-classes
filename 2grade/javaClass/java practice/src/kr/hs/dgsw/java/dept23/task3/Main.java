package kr.hs.dgsw.java.dept23.task3;

import java.util.Random;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		System.out.println("***************");
		System.out.println("quit : 종료");
		System.out.println("reset : 전적리셋");
		System.out.println("***************");
		
		Scanner scan = new Scanner(System.in);
		RPS rps = new RPS();
		
		while(true) {
			System.out.println("\n가위바위보 가운데 하나를 입력하세요");
			System.out.printf(">> ");
			String command = scan.nextLine();
			if (command.equals("quit")) {
				break;
			} else if(command.equals("reset")) {
				RecodingScore recoder = new RecodingScore();
				recoder.writeScore("0 0 0");
			} else {
				rps.doRPS(command);				
			}
			
		}
		
		scan.close();
	}
}
