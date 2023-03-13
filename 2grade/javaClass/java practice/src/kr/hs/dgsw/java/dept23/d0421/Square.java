package kr.hs.dgsw.java.dept23.d0421;

public class Square extends Rectangle{
	public Square(int width) {
		super(width,width);
	}
	
	@Override
	public String getType() {
		return "정사각형";
	}
	
	public static void main(String[] args) {
		Square square = new Square(8);
		square.print();
	}
}
