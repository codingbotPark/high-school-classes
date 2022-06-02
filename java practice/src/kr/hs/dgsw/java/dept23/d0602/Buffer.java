package kr.hs.dgsw.java.dept23.d0602;

import java.util.LinkedList;
import java.util.Queue;

public class Buffer {
	// 큐가 있음
	private final Queue<Integer> queue = new LinkedList<Integer>();
	
	// queue에 값 추가
	// 값을 넣는 것은 동기화 되어야 한다
	public synchronized void add(int value) {
		queue.add(value);
		
		notify();
		// notify를 하면 신호를 주는 것이다
	}
	
	// 정수형
	public Integer get() {
		return queue.poll();
	}
	
	public static void main(String[] args) {
		Buffer buffer = new Buffer();
		
		Producer producer = new Producer(buffer);
		Thread thread = new Thread(producer);
		thread.start();
		
		Consumer consumer = new Consumer(buffer);
		Thread consumberThread = new Thread(consumer);
		consumberThread.start();
	}
}
