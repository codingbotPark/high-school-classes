package kr.hs.dgsw.java.dept23.d0414;

public class Pomeranian extends Dog{
	public Pomeranian() {
		super("���޶�Ͼ�");
	}
	public static void main(String[] args) {
		Animal Pomeranian = new Pomeranian();
		
		Pomeranian.move();
		Pomeranian.eat("����");
		Pomeranian.makeSound();
		
		// Ŭ������ ���� �ֻ���� Ŭ������ Object�̴�
		Object object = new Object();
		String a = new String();
		Integer b = new Integer(0);
	}
}
