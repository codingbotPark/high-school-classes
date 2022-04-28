package kr.hs.dgsw.java.dept23.d0428;

// 추상이란 사물이나 표상(表象)을 어떤 성질·공통성·본질에 착안하여 그것을 추출(抽出)하여 파악하는 것
// 추상 글래스는 abstract를 추가하면 된다
public abstract class Animal {
	public abstract String getName();
	
	// 추상 메소드로 만들어 준다
	public abstract String makeSound();
	// 추상메소드는 이름만 가지고 있다
	// 호출만 해놓고 상속받은 곳에서 구현이 된다
	
	
	public void move() {
		System.out.printf("%s 이(가) %s 소리를 내며 달려갑니다",getName(),makeSound());
	}
	
	public static void main(String[] args) {
		// 추상 클레스는 바로 객체로 만들 수 없다
		// Animal animal = new Animal();
		
		// 대신 추상 클래스를 상속받은 자식으로부터 객체를 만들 수 있다
		Animal animal = new Horse();
		animal.move();
	}
}
