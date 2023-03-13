package kr.hs.dgsw.java.dept23.d0331;

public class AccessModifierStudy {
	// 자기 자신의 클래스에서는 모든 접근이 가능하다
	private int privateValue;
	
	// 보호받는 이런 뜻,
	// 상속과 관련있다
	protected int protectedValue;
	
	public int publicValue;
	
	int defaultValue;
}


// 전체 클레스에도 public만이 아닌 default등이 가능한데
// default가 되면 다른 패키지에서 사용하지 못하게 된다