package kr.hs.dgsw.java.dept23.d0414;

public class People {
	protected int age;
	protected int weight;
	protected int height;
	protected String gender;
	protected String name; 
	// protected´Â °°Àº
	public void breathe() {
		System.out.println("I'm live!");
	}
	public void showInformation() {
		System.out.printf("name : %s, age : %d\n" ,name,age);
	}
}
