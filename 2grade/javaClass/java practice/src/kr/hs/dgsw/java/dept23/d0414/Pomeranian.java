package kr.hs.dgsw.java.dept23.d0414;

public class Pomeranian extends Dog{
	public Pomeranian() {
		super("포메라니안");
	}
	public static void main(String[] args) {
		Animal Pomeranian = new Pomeranian();
		
		Pomeranian.move();
		Pomeranian.eat("개껌");
		Pomeranian.makeSound();
		
		// 클래스중 가장 최상단의 클래스는 Object이다
		Object object = new Object();
		String a = new String();
		Integer b = new Integer(0);
	}
}
