package kr.hs.dgsw.java.dept23.task2;

public interface Searcher {

	/**
	 * 주어진 정렬된 배열에서 주어진 값이 존재하는 위치의 인덱스를 되돌린다.
	 * 
	 * @param sortedValues 오름차순으로 정렬된 정수 배열
	 * @param value 찾을 값
	 * @return value가 위치하는 인덱스, 만약 배열에 주어진 값이 없으면 -1
	 */
	
	public int search(int[] sortedValues, int value);
	
}

