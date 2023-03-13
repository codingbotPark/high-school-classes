package kr.hs.dgsw.java.dept23.d0428;

public class Horse extends Animal{
	// Animal에는 추상 메소드 makeSound가 있기 때문에
	// makeSound가 없다면 에러가 뜬다
	@Override
	public String makeSound() {
		return "히이잉";
	}
	// 이처럼 추상메소드는 자식을 만들 때의 가이드를 만드는 역할을 해줄 수 있다
	
	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return "말";
	}
}
