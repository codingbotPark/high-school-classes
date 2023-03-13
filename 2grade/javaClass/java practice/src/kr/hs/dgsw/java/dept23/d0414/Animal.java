package kr.hs.dgsw.java.dept23.d0414;

public class Animal {
	protected final String name;
	
	public Animal(String name) {
		this.name = name;
	}
	public void move() {
		System.out.println(name + "이(가) 뛰어다닙니다.");
	}
	public void eat(String food) {
		System.out.println(name + "이(가)" + food + "을(를)먹습니다.");
	}
	public void makeSound() {
		System.out.println("");
	}
}
