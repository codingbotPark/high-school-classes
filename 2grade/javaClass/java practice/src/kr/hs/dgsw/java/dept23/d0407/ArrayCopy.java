package kr.hs.dgsw.java.dept23.d0407;

public class ArrayCopy {
	// 주어진 src배열을 복사해서 리턴
	public String[] copy(String[] src) {
		String[] result = new String[src.length];
		for (int i = 0;i<src.length;i++) {
			result[i] = src[i];
		}
		return result;
	}
	
	// int를 복사해주는 메서드
	public int[] copy(int[] src) {
		int[] result = new int[src.length];
		for (int i = 0;i<src.length;i++) {
			result[i] = src[i];
		}
		return result;
	}
}
