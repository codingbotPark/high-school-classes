package kr.hs.dgsw.java.task1;

import java.io.File;
import java.util.ArrayList;

// 검색했을 때 비슷한 내용을 리턴해주는 함수 필요

// 3개 다 모두 검색이 필요, 
// insert는 넣을 곳 위치 검색,
// search는 비슷한 문자 검색,
// delete는 비슷한 문자 검색

public class DoInsert{
	File file;
	
	// insert할 자리를 찾는다
	// search에는 파일에 있는 내용을 찾는데, 
	// insert에서는 들어갈 자리를 찾음 
	public ArrayList<String> insert(String insertValue) {
		GetContent getContent = new GetContent(file);
		ArrayList<String> contents = getContent.getContent();
		int i = 0;
		for (String content:contents) {
			if (content.compareTo(insertValue) > 0) {
				break;
			}
			i++;
		}

		contents.add(i,insertValue);
		return contents;
	}
	
	public DoInsert(File file,String insertValue) {
		// TODO Auto-generated constructor stub
		this.file = file;
		ArrayList<String> insertedContent = insert(insertValue);
		
		// 파일에 적용
		ApplyToFile apply = new ApplyToFile(file);
		apply.apply(insertedContent);
		
	}
}
