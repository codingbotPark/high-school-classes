package kr.hs.dgsw.java.dept23.d0407;

public class ArrayCopy {
	// �־��� src�迭�� �����ؼ� ����
	public String[] copy(String[] src) {
		String[] result = new String[src.length];
		for (int i = 0;i<src.length;i++) {
			result[i] = src[i];
		}
		return result;
	}
	
	// int�� �������ִ� �޼���
	public int[] copy(int[] src) {
		int[] result = new int[src.length];
		for (int i = 0;i<src.length;i++) {
			result[i] = src[i];
		}
		return result;
	}
}
