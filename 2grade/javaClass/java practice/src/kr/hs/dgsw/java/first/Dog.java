package kr.hs.dgsw.java.first;

public class Dog {
	String color;
	int countOfLegs;
	String species;
	
	void print() {
		System.out.println(color + " " + countOfLegs + " " + species);
	}
	int getCountOfLegs() {
		return countOfLegs;
	}
	
	public static void main(String[] args) {
		Dog jindo = new Dog();
		jindo.color = "yellow";
		jindo.countOfLegs = 4;
		jindo.species = "������";
		
		Dog bulldog = new Dog();
		bulldog.color = "red";
		bulldog.countOfLegs = 4;
		bulldog.species = "�ҵ�";
		
		jindo.print();
		bulldog.print();
	}
}
