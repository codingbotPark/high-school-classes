package kr.hs.dgsw.java.dept23.d0324;

import java.util.Scanner;

public class Dog {
	private final String name;
	// final �� �ָ� ���� �ٲ��� �ʵ��� �Ѵ�, �׳� ���ó�� ����ȴ�
	// ��� �ʱⰪ�� �־���Ѵ� 
	// �׷��� �ʱⰪ�� �����ڰ� ����� ���� �ؾ��Ѵ�
	
	// �츮�� ���α׷��� �ϸ鼭 �Ǽ��� ���� �ٲ� �� �ִ� �Ǽ��� ���� 
	// �����Ϸ��� ���� �ӵ��� ���� �� ������ �� ����
	private int age; 
	

//	
//	public Dog(int age) {
//		System.out.println("������ȣ��");
//		this.name = "����";
//		this.age = age;
//	}
////		
//	// �⺻ �����ڸ� ����ϸ� public Dog() {} �� �ִ°Ͱ� ����
//	public Dog(String name){// ������ �����
//		// �����ڴ� return Ÿ���� ����� �Ѵ�
//		// ������ �̸��� class �̸��� ���ƾ� �Ѵ�
//		
//		// class�̸��� �ٸ��� �ϸ� �Ϲ� �޼ҵ��ΰɷ� �ν��ؼ�
//		// �޼ҵ�(��� �ν�)�ε� ���� Ÿ���� ���� ������ ����
//		
//		System.out.println("������ȣ��");
//		
//		// �����ڴ� ���� ���� ����Ǳ� ������ �ʱ�ȭ�� �����ڿ��� �����Ѵ�
//		this.name = name;
//	}
	
	// ���� ��ü ���� �������� �ߺ��� ���ΰ� �Ʒ��̴�
	// �Լ��� ����ϸ� �ȴٰ� ������ �� ������ name �� final �̰�
	// final �� �ʱⰪ�� �ʿ��ϱ� ������ ������Ʈ ���� �������� �ʱ�ȭ�� ����� �ؼ�
	// �Լ��� ����� �� ����
	
	// �׷��� �� ��Ȳ���� this�� ����� �ٸ� �����ڸ� ȣ��, �ߺ��� ���ΰ� �Ʒ��̴�
	public Dog() {
		this("����");
		// this = Dog �ε� Dog�����ڿ� string�� �־���� ������ �Ʒ��� Dog�� ����ȴ�
		// �̷��� �Ʒ��� Dog�� ��������� "������ ȣ���" �� ����ϰ�, name�� �����ϴ� �������� �ߺ��� �ٿ���
		System.out.println("aaa");
	}
	public Dog(String name) {
//		System.out.println("������ ȣ���");
		this.name = name;
	}
	
	public void sayHello() {
		System.out.println("Hello "+this.name);
	}
	
	

	
//	public static void main(String[] args) {
		
		// eclipse���� Run, Debug Configurations, arguments ���� arg�� �� �� �ִ�
//		System.out.println("count : "+args.length);
//		
//		for (int i=0;i<args.length;i++) {
//			Dog dog = new Dog(args[i]);
//			dog.sayHello();
//		}
		// args�� �Է¹ޱⰡ ������ �� �־ scaner�� ����Ѵ�
		
//		Dog puppy = new Dog("����");
//		Dog happy = new Dog("����");
//		Dog poppy = new Dog("����");
		// �̷������� ������Ʈ�� ���� �� �ִ� ������ �⺻ �����ڰ� �ֿ����� �����̴�
//	}
}

