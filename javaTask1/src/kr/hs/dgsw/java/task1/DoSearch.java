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

public class DoSearch{
	
	File file;
	
	public ArrayList<String> search(String keyword){
		GetContent getContent = new GetContent(file);
		ArrayList<String> contents = getContent.getContent();
		
		ArrayList<String> resultStrings = new ArrayList<String>();
		
		if (keyword.equals("*")) {
			resultStrings = contents;
		} else {
			for (String content:contents) {
				// keyword가 문자열에 포함되는지 확인
				if (content.contains(keyword)) {
					resultStrings.add(content);
				}
			}
		}
		
		
		return  resultStrings;
	}

	public void printnSearchResult(String keyword) {
		for (String temp:search(keyword)) {
			System.out.println(temp);
		}
	}

	public DoSearch(File file,String keyword) {
		// TODO Auto-generated constructor stub
		this.file = file;
		printnSearchResult(keyword);
	}
}
