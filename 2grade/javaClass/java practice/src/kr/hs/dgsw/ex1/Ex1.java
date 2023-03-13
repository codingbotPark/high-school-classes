package kr.hs.dgsw.ex1;

public class Ex1 {
	
	
	public static void main(String[] args) {
		People kim = new People();
		kim.name = "kim";
		kim.height = 165;
		kim.weight = 55;
		People kwon = new People();
		kwon.name = "kwon";
		kwon.height = 180;
		kwon.weight = 80;
		
		kim.printBMI(kim.name, kim.height, kim.weight);
		kwon.printBMI(kwon.name, kwon.height, kwon.weight);
	}
}
