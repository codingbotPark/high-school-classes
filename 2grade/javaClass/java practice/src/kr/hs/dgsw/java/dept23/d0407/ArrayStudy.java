package kr.hs.dgsw.java.dept23.d0407;

import java.util.Arrays;

public class ArrayStudy {
	public void studyArray() {
		int[] array1 = new int[10];
		int array2[];
		
		String[] names = new String[5];
		
		// �����ؼ� ����� �迭
		int[] array3 = new int[10];
		// ���� �־ ����� �迭
		int[] values = {1,2,3,4,5};
		
		
		// colors��� ���ڿ� Ÿ���� �迭 ����,
		// ���� �ʱ�ȭ
		String[] colors = {"blue","red","green"};
		// red���
//		System.out.println(colors[1]);
		// java���� index�� �Ѿ�� ArrayIndexOutOfBounsException
		// ������ ���´�
//		System.out.println(colors[3]);
		
		
		
		// �̷��� �Ѵٸ� �ּҸ� ���簡 �ȴ�
		String[] colors2 = colors;
		colors[2] = "blue";
		
		// �� ���� Ȯ��
		
		ArrayCopy arrayCopy = new ArrayCopy();
		String[] colors3 = arrayCopy.copy(colors);
		colors3[2] = "green";
//		System.out.println(colors[2]);
		
		// Arrays�� �켭 colors2�� ��� ���� ����� �� �ִ�
		System.out.println("colors2 : " + Arrays.toString(colors));
		
	}
	
	
	// string�� ���ڷ� �޴´�
	public void printLastArray(String[] values) {
		// length�� �迭�� ���̸� �� �� �ִ�
		int length = values.length;
		System.out.println(values[length-1]);
	}
	
	public void printColors(String[] colors) {
		for (int i = 0;i<colors.length;i++) {
			System.out.println(colors[i]);
		}
		
		// ������ �ڵ�, foreach���̴�
		for (String color : colors) {
			System.out.println(color);
		}
		
		
	}
	
	public static void main(String[] args) {
		ArrayStudy study = new ArrayStudy();
		study.studyArray();
		
	}
}
