package kr.hs.dgsw.java.dept23.task2;

import java.util.Random;
import java.util.Scanner;

public class SearchExecutor {

	public static final int SIZE = 1000;
	
	public static int[] makeSampleData() {
		int[] array = new int[SIZE];
		Random random = new Random(System.currentTimeMillis());
		
		int value = 0;
		for (int i = 0 ; i < array.length ; i++) {
			value += random.nextInt(3) + 1;
			array[i] = value;
		}
		
		return array;
	}
	
	public void doSearch(int[] array) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("찾을 값을 (정수로) 입력하세요.");
		int value = scanner.nextInt();

		for (int a : array) {
			System.out.println(a);
		}
		
		Searcher searcher = new BinarySearch();  // TODO 이 부분을 수정하세요.
		int index = searcher.search(array, value);
		
		if (index >= 0) {
			System.out.printf("배열에서 정수 %d는 %d 위치에 존재합니다.", value, index);
		} else {
			System.out.printf("배열에서 정수 %d는 존재하지 않습니다.", value);
		}
		
		scanner.close();
	}
	
	public static void main(String[] args) {
		SearchExecutor searchExecutor = new SearchExecutor();
		int[] sampleData = SearchExecutor.makeSampleData();
		
		searchExecutor.doSearch(sampleData);
	}
	
}
