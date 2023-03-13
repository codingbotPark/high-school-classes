package kr.hs.dgsw.java.dept23.d0428;

import java.util.ArrayList;
import java.util.List;

public class MyList extends ArrayList<String>{
	
//	@Override
	public boolean add(String e) {
		
		boolean added = false;
		
		for (int i = 0;i<size();i++) {
			// e가 인덱스i보다 작을 때 if문에 들어감
			if (e.compareTo(get(i)) < 0) {
				add(i,e);
				// 원하는 위치에 추가
				added = true;
				break;
			}
		}
		
		if (!added) {
			return super.add(e);
			// 제일 뒤에 추가
		} else {
			return true;
		}
		
//		return true;
	}
	
	
	public static void main(String[] args) {
		List<String> list = new MyList();
		
		list.add("red");
		list.add("pink");
		list.add("blue");
		list.add("black");
		list.add("yellow");
		
		for (String color : list) {
			System.out.println(color);
		}
	}
}
