package kr.hs.dgsw.java.dept23.d0421;

public class Circle extends Square{
	
	public Circle(int radius) {
		super(radius);
	}
	public String getType() {
		return "¿ø";
	}
	@Override
	public double getArea() {
		return super.getArea() * Math.PI;
	}

	
	public static void main(String[] args) {
		Circle circle = new Circle(4);
		circle.print();
	}
}
