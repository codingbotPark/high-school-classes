package kr.hs.dgsw.java.dept23.d0428;

import java.util.ArrayList;
import java.util.List;

public class ListStudy {

	// 배열은 같은 타입의 큰 값들을 저장
	// 하지만 배열의 크기는 정해져있다
	// 이런 배열의 장점을 그대로 가져가고 단점을 보안한 것이 리스트이다
	public void studyList() {
		// 제네릭
		List<String> list = new ArrayList<String>();
		String[] array = new String[5];
		
		
		// 저장하기
		array[0] = "blue";
		array[1] = "black";
		array[4] = "red";
		
		list.add("blue");
		list.add("black");
		list.add("red");
		list.add("black");
		list.add("yellow");
		list.add("green");
		
		// 특정한 위치에 값 추가
		list.add(3,"white");
		
		// 읽어오기
		String color = array[1];
		
		color = list.get(1);
		
		// 크기
		int size = array.length;
		size = list.size();
		
		for (int i = 0;i<list.size();i++) {
			System.out.println(i + " : " + list.get(i));
		}
		
		for (String str : list) {
			System.out.printf(str);
		}
		
		// 삭제하기
		String value = list.remove(1);
		System.out.println(list.get(1));
	}
	
	
	public static void main(String[] args) {
		ListStudy listStudy = new ListStudy();
		listStudy.studyList();
	}
}
