package kr.hs.dgsw.java.dept23.d0414;

public class Dog extends Animal{
	public Dog(String name) {
		// 부모에 생성자(name)이 있기 때문에
		// super로 만들어 준다
		super(name);
	}
	@Override
	public void makeSound() {
		System.out.printf("멍멍");
	}
	public static void main(String[] args) {
		Animal dog = new Dog("해피");
		dog.move();
		dog.eat("사료");
		dog.makeSound();
	}
}
