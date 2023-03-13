package kr.hs.dgsw.java.dept23.d0421;

public class Triangle extends Rectangle{
	public Triangle(int width, int height) {
		super(width,height);
	}
	@Override
	public double getArea() {
//		return (width * height)/2;
		return super.getArea() / 2;
	}
	public String getType() {
		return "»ï°¢Çü";
	}
	public static void main(String[] args) {
//		Triangle triangle = new Rectangle(10,5);
		Triangle triangle = new Triangle(10,5);
		triangle.print();
	}
}
