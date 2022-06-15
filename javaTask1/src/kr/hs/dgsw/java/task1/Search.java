package kr.hs.dgsw.java.task1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

// getFileContent는 Search에 있고, delete, insert는 상속받는다
// 내용을 가져오는 거, 검색하는 클래스 만들거나?

public class Search extends GetContent{
	
	File file;
	
	public String[] getFileContent() {
//		String[] fileContent;
		ArrayList<String> fileContent = new ArrayList<String>();
 		try {
			BufferedReader br = new BufferedReader(new FileReader(file));
			String temp;
			try {
				while ((temp = br.readLine()) != null) {
					fileContent.add(temp);
					System.out.println(temp);
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
 		return fileContent.toArray(new String[0]);
	}
	
	public void SearchFor(String keyword) {
		
	}
	

	public Search(File file,String keyword) {
		// TODO Auto-generated constructor stub
		
		super(file);
		
//		this.file = file;
//		SearchFor(keyword);
		
		search();
		
	}
}
