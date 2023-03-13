package kr.hs.dgsw.java.dept23.d0421;

public class Polygon {
	public String getType() {
		return "다각형";
	}
	public double getArea() {
		return 0;
	}
	
	public void print() {
		System.out.printf("%s의 면적은 %.2f입니다", getType(),getArea());
	}
}
