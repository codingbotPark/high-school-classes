package kr.hs.dgsw.java.dept23.task2;

import java.util.Arrays;

public class BinarySearch implements Searcher{

	@Override
	public int search(int[] sortedValues, int value) {
		
		// 중간 번째 인덱스를 확인 후 배열을 
		// Arrays.copyOfRange 함수로 잘라준다
		int index = 1;
		
		int arrLength; // 배열 길이를 저장할 변수
		int targetedValue; // 배열의 index에 위치한 값
		
		// 배열의 앞 부분을 잘랐을 때 알맞은 인덱스를 구해주기 위해
		// 자른 만큼 index를 더해줄 변수
		int supportIndex = 0; 
		
		// index가 0이라면 배열에 찾고자 하는 수가 없는 것이다
		while(sortedValues.length > 0) {
			arrLength = sortedValues.length;
			index = arrLength / 2;
			targetedValue = sortedValues[index];
				
			if (targetedValue == value) {
				return index + supportIndex;
			} else if (targetedValue > value) { // index기준 뒷부분을 자른다
				sortedValues = Arrays.copyOfRange(sortedValues,0,index);
			} else { // index기준 앞부분을 자른다
				// 앞부분을 자를 때는 index를 앞부분 만큼 + 해준다
				supportIndex += index+1;
				sortedValues = Arrays.copyOfRange(sortedValues, index+1, arrLength);
			}
		}

		// TODO Auto-generated method stub
		return -1;
	}

}
