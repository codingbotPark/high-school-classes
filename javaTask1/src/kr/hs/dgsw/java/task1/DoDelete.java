package kr.hs.dgsw.java.task1;

import java.io.File;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class DoDelete {
	File file;
	
	
	// 삭제할 값 을 찾고, 정한다,
	// delete는 정확하게 들어온 이름을 보고 하기 때문에 search와 다르다
	public ArrayList<String> getSelected(String name) {
		GetContent getContent = new GetContent(file);
		ArrayList<String> content = getContent.getContent();
		
		// 삭제할 이름과 같은 것을 추출 
		ArrayList<String> selectedList = new ArrayList<String>();
		
		for (String item:content) {
			if (name.equals(item.split(" ")[0])) {
				selectedList.add(item);
			}
		}
		
		return selectedList;
	}
	
	// delete로 선택한 이름이 있는지 확인,
	// 여러 개 있을 때 선택하도록 한다
	public String confirmDelete(String deleteValue) {
		ArrayList<String> selectedList = getSelected(deleteValue);
		int listLength = selectedList.size();
		
		String resultLine;
		
		if(listLength == 0) {
			System.out.println("없는 이름입니다");
			resultLine = "empty";
		} else if(listLength == 1) {
			// 하나 뿐인 요소를 resultLine에 넣는다
			resultLine = selectedList.toArray(new String[0])[0];
		} else {
			System.out.println(listLength+"개의 검색결과가 있습니다, 어떤것을 삭제할까요? : ");
			
			// 사용자에게 선택을 하게 한다
			Scanner scan = new Scanner(System.in);
			
			while(true) {
				int userCho = scan.nextInt();
				// 제대로된 선택 값인지 확인
				if (userCho > 0 && userCho <= listLength) {
					resultLine = selectedList.toArray(new String[0])[userCho-1];
							
				} else {
					System.out.printf("1~%d사이의 값을 선택해주세요\n",listLength);
				}
			}
			
		}
		
		return resultLine;
		
	}
	
	public void delete(String deleteValue){
		// 파일에서 지울 한 줄을 가져온다
		String decidedValue = confirmDelete(deleteValue);
		
		GetContent getContent = new GetContent(file);
		ArrayList<String> contents = getContent.getContent();
		
//		contents.remove(Arrays.asList(contents).indexOf(decidedValue));
		
		if (!decidedValue.equals("empty")) {
			int i = 0;
			for (String content:contents) {
				if (content.equals(decidedValue)) {
					break;
				}
				i++;
			}
			
			contents.remove(i);
			
			ApplyToFile apply = new ApplyToFile(file);
			apply.apply(contents);
		}
		
		
	}
	
	public DoDelete(File file, String deleteValue) {
		// TODO Auto-generated constructor stub
		this.file = file;
		delete(deleteValue);
//		ArrayList<String> deletedContent = delete(deleteValue);
//		
//		ApplyToFile apply = new ApplyToFile(file);
//		apply.apply(deletedContent);
	}
}
