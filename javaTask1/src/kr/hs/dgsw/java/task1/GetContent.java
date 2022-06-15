package kr.hs.dgsw.java.task1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

public class GetContent {
	File file;
	// search delete insert3개 다 필요함 함수
	
	private String[] getContent() {
		ArrayList<String> fileContent = new ArrayList<String>();
		try {
			FileInputStream input = new FileInputStream(file);
			try {
				InputStreamReader reader = new InputStreamReader(input,"UTF-8");
				BufferedReader br = new BufferedReader(reader);
				
				String temp;
				try {
					while ((temp = br.readLine()) != null) {
						fileContent.add(temp);
						System.out.println(temp);
					}
					br.close();
					
					
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}	
			} catch (UnsupportedEncodingException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
 		return fileContent.toArray(new String[0]);
	}
	
	// 검색한 결과를 String배열로 리턴
//	public String[] search() {
	public void search() {
		String[] contents = getContent();
//		for (String temp:contents) {
//			System.out.println(temp);
//		}
	}

	public GetContent(File file) {
		// TODO Auto-generated constructor stub
		this.file = file;
	}
}
