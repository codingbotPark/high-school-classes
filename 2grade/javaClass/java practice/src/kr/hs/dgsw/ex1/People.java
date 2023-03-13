package kr.hs.dgsw.ex1;

public class People {
	String name;
	int height;
	int weight;
	
	int BMI(int h,int w) {
		return w / ((h / 100) * (h/100));
//		return w / (h * h);
	}
	
	void printBMI(String name,int h, int w) {
		int BMIvalue = BMI(h,w);
		if (BMIvalue >= 25) {
			System.out.println(name + "의 비만도는 " + BMIvalue + "이고 과체중입니다");
		} else if (BMIvalue >= 20) {
			System.out.println(name + "의 비만도는 " + BMIvalue + "이고 표준체중입니다");
		} else {
			System.out.println(name + "의 비만도는 " + BMIvalue + "이고 저체중입니다");
		}
		
	}
}