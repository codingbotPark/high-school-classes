package kr.hs.dgsw.java.dept23.d0616;

import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

public class CollectionStudy {
	public void studyMap() {
		// 맵은 key와 value, 두 개의 제네릭을 요구
		Map<String, Integer> map =new HashMap<String,Integer>();
		
		// 재봉쌤 너무 똑똑합니다
		map.put("임진왜란", 1592);
		map.put("조선건국", 1392);
		map.put("신대륙발견", 1492);
		map.put("프랑스대혁명", 1789);
		map.put("서로마멸망", 476);
		
		Integer year = map.get("임진왜란");
		System.out.println(year);
		
		// 없으면 null을 반환
		year = map.get("공자탄생");
		System.out.println(year);
		
		// key는 항상 유니크 하기 때문에 뒤에 있는 것이 덮어쓰게된다
		
		// set = 집합, 중복이 없고, 기준이 있어야 한다
		Set<String> keys = map.keySet();
		Collection<Integer> values = map.values();
		
		
	}
	
	public void studyQueue() {
		// Queue는 LinkedList를 상속받는다
		Queue<String> queue = new LinkedList<String>();
		List<String> list = new LinkedList<String>();
		
		queue.add("Korea");
		queue.add("Japan");
		queue.add("China");
		queue.add("USA");
		
		while(queue.size() > 0) {
			System.out.println(queue.poll());
		}
	}
	
	public void studySet() {
		Set<String> set = new HashSet<String>();
		
		set.add("Korea");
		set.add("Japan");
		set.add("China");
		set.add("USA");
		
		for(String str:set) {
			System.out.println(str);
		}
		// set은 순서를 지켜주지 않는다, 중복을 없앤다
	}
	
	public static void main(String[] args) {
		new CollectionStudy().studySet();
		
		
	}
}
