package kr.hs.dgsw.java.dept23.d0602;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class CalculatorMain {
	private final Queue<Integer> queue = new LinkedList<Integer>();
	
	private int counter = 0;
	
	public synchronized void add(int value) {
		counter++;
		queue.add(value);
		
		// 두 수가 들어올 때
		if (counter == 2) {
			counter = 0;
			notify();
			// add가 되면 알려준다	
		}
		
	}
	
	public Integer get() {
		return queue.poll();
	}
	
	public static void main(String[] args) {
		CalculatorMain buffer = new CalculatorMain();
		
		CalculatorScanner scan = new CalculatorScanner(buffer);
		Thread thread = new Thread(scan);
		thread.start();
		
		CalculatorAdder adder = new CalculatorAdder(buffer);
		Thread adderThread = new Thread(adder);
		adderThread.start();
	}
	
	
}
