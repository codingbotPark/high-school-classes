package kr.hs.dgsw.java.dept23.d0414;

public class Parent {
	protected String name;
	private int weight;
	public void sayHello() {
		System.out.println("Hello");
	}
	public static void main(String[] args) {
		Parent parent = new Parent();
		parent.sayHello();
		// 부모는 자식을 모른다
		//parent.showAge();
		
		
	}
}
