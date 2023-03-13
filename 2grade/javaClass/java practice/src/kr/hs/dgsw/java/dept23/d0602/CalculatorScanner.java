package kr.hs.dgsw.java.dept23.d0602;

import java.util.Scanner;

public class CalculatorScanner implements Runnable{
	
	private final CalculatorMain buffer;
	private int counter = 0;
	
	Scanner scan = new Scanner(System.in);
	
	public CalculatorScanner(CalculatorMain buffer) {
		// TODO Auto-generated constructor stub
		this.buffer = buffer;
	}
		
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true) {
			if (counter == 0) {
				System.out.println("두 정수를 입력하세요");
				counter = -2;
			}
			int value = scan.nextInt();
			buffer.add(value);
			counter++;
		}
	}
	
}
