package kr.hs.dgsw.java.dept23.d0407;

import java.util.Arrays;

public class ArrayStudy {
	public void studyArray() {
		int[] array1 = new int[10];
		int array2[];
		
		String[] names = new String[5];
		
		// 선언해서 만드는 배열
		int[] array3 = new int[10];
		// 값을 넣어서 만드는 배열
		int[] values = {1,2,3,4,5};
		
		
		// colors라는 문자열 타입의 배열 선언,
		// 값을 초기화
		String[] colors = {"blue","red","green"};
		// red출력
//		System.out.println(colors[1]);
		// java에서 index를 넘어가면 ArrayIndexOutOfBounsException
		// 에러가 나온다
//		System.out.println(colors[3]);
		
		
		
		// 이렇게 한다면 주소만 복사가 된다
		String[] colors2 = colors;
		colors[2] = "blue";
		
		// 값 공유 확인
		
		ArrayCopy arrayCopy = new ArrayCopy();
		String[] colors3 = arrayCopy.copy(colors);
		colors3[2] = "green";
//		System.out.println(colors[2]);
		
		// Arrays를 헤서 colors2의 모든 값을 출력할 수 있다
		System.out.println("colors2 : " + Arrays.toString(colors));
		
	}
	
	
	// string을 인자로 받는다
	public void printLastArray(String[] values) {
		// length로 배열의 길이를 알 수 있다
		int length = values.length;
		System.out.println(values[length-1]);
	}
	
	public void printColors(String[] colors) {
		for (int i = 0;i<colors.length;i++) {
			System.out.println(colors[i]);
		}
		
		// 선생님 코드, foreach문이다
		for (String color : colors) {
			System.out.println(color);
		}
		
		
	}
	
	public static void main(String[] args) {
		ArrayStudy study = new ArrayStudy();
		study.studyArray();
		
	}
}
