package kr.hs.dgsw.java.dept23.d0331;

// extends는 class를 상속받을 수 있다
public class ChildClass extends AccessModifierStudy{
	public static void main(String[] args) {
		ChildClass study = new ChildClass();
		study.publicValue = 5;
//		study.privateValue = 5;
		
		study.protectedValue = 5;
		study.defaultValue = 5;
		}
}


