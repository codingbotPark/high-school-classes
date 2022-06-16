package kr.hs.dgsw.java.task1;

import java.io.File;
import java.util.ArrayList;

public class Search {
	ArrayList<String> contents;
	
	public String[] search(String keyword) {
		// TODO Auto-generated method stub
		ArrayList<String> resultStrings = new ArrayList<String>();
		
		for (String content:contents) {
			// keyword가 문자열에 포함되는지 확인
			if (content.contains(keyword)) {
				resultStrings.add(content);
			}
		}
		return  resultStrings.toArray(new String[0]);
	}
	
	public Search(File file) {
		// TODO Auto-generated constructor stub
		GetContent getContent = new GetContent(file);
//		this.contents=getContent.getContent();
		this.contents = getContent.getContent();
	}
}

