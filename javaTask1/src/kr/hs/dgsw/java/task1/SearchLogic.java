package kr.hs.dgsw.java.task1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

// 상속 없애고, getContent를 생성자로 만들어서 search에 사용,
// delete에서는 search를 생성자를 만들어서 search를 한다
// search를 search기능하는 클래스와, search로직(숫자인지 문자인지)

// insert는 그냥 쳐넣기
// search는 startwith이 아닌, contain후 sort를 해서 출력
// delete는 이름으로 검색

// 정렬해서 파일에 넣고, (파일에 넣는 클래스 하나 만들기)
// 그냥 contain 으로 찾으면 한글, 영어 둘 다 쌉가능
// 그렇게 해서 찾은거는 그냥 출력(정렬해서 파일에 저장되기 때문)

public class SearchLogic{
	
	File file;
	
	public void search() {
		
	}
	
//	public void SearchFor(String keyword) {
//		// 검색이 번호로 이루어졌는지, 숫자로 이루어 졌는지 확인
//		char keywordFirst = keyword.charAt(0);
//		if (keywordFirst > 47 && keywordFirst < 58) {
//			System.out.println("문자로 검색");
//		} else {
//			System.out.println("숫자로 검색");
//		}
//	}
	

	public SearchLogic(File file) {
		// TODO Auto-generated constructor stub
		
//		super(file);
//		
//		String[] contents = getContent();
		
		
//		this.file = file;
//		SearchFor(keyword);
		
	}
}
