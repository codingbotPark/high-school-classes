package kr.hs.dgsw.java.dept23.d0331;

public class OtherClass {
	public static void main(String[] args) {
		AccessModifierStudy study = new AccessModifierStudy();
		study.publicValue = 5;
//		study.privateValue = 5;
		
		study.protectedValue = 5;
		study.defaultValue = 5;
		}
}
