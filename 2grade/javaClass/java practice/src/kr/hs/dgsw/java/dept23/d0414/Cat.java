package kr.hs.dgsw.java.dept23.d0414;

public class Cat extends Animal{
	public Cat(String name) {
		super(name);
	}
	public void makeSound() {
		System.out.println("具克具克");
	}
	public static void main(String[] args) {
		Animal cat = new Cat("唱厚");
		
		cat.move();
		cat.eat("积急");
		cat.makeSound();
	}
	
}
