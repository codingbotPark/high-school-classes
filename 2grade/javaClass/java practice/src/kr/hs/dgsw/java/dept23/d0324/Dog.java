package kr.hs.dgsw.java.dept23.d0324;

import java.util.Scanner;

public class Dog {
	private final String name;
	// final 을 주면 값이 바뀌지 않도록 한다, 그냥 상수처럼 실행된다
	// 대신 초기값을 넣어야한다 
	// 그래서 초기값은 생성자가 실행될 때만 해야한다
	
	// 우리가 프로그램을 하면서 실수로 값을 바꿀 수 있는 실수를 막음 
	// 컴파일러가 보고 속도가 조금 더 빨라질 수 있음
	private int age; 
	

//	
//	public Dog(int age) {
//		System.out.println("생성자호출");
//		this.name = "몰라";
//		this.age = age;
//	}
////		
//	// 기본 생성자를 사용하면 public Dog() {} 만 있는것과 같다
//	public Dog(String name){// 생성자 만들기
//		// 생성자는 return 타입이 없어야 한다
//		// 생성자 이름은 class 이름과 같아야 한다
//		
//		// class이름과 다르게 하면 일반 메소드인걸로 인식해서
//		// 메소드(라고 인식)인데 리턴 타입이 없기 때문에 에러
//		
//		System.out.println("생성자호출");
//		
//		// 생성자는 가장 먼저 실행되기 때문에 초기화를 생성자에서 진행한다
//		this.name = name;
//	}
	
	// 위의 객체 생성 과정에서 중복을 줄인게 아래이다
	// 함수를 사용하면 된다고 생각할 수 있지만 name 이 final 이고
	// final 은 초기값이 필요하기 때문에 오브젝트 생성 과정에서 초기화를 해줘야 해서
	// 함수를 사용할 수 없다
	
	// 그래서 이 상황에서 this를 사용해 다른 생성자를 호출, 중복을 줄인게 아래이다
	public Dog() {
		this("몰라");
		// this = Dog 인데 Dog생성자에 string을 넣어줬기 때문에 아래의 Dog가 실행된다
		// 이렇게 아래의 Dog가 실행됨으로 "생성자 호출됨" 을 출력하고, name을 지정하는 과정에서 중복을 줄였다
		System.out.println("aaa");
	}
	public Dog(String name) {
//		System.out.println("생성자 호출됨");
		this.name = name;
	}
	
	public void sayHello() {
		System.out.println("Hello "+this.name);
	}
	
	

	
//	public static void main(String[] args) {
		
		// eclipse에서 Run, Debug Configurations, arguments 에서 arg를 줄 수 있다
//		System.out.println("count : "+args.length);
//		
//		for (int i=0;i<args.length;i++) {
//			Dog dog = new Dog(args[i]);
//			dog.sayHello();
//		}
		// args는 입력받기가 불편할 수 있어서 scaner를 사용한다
		
//		Dog puppy = new Dog("퍼피");
//		Dog happy = new Dog("해피");
//		Dog poppy = new Dog("퍼피");
		// 이런식으로 오브젝트를 만들 수 있는 이유는 기본 생성자가 주워지기 때문이다
//	}
}

