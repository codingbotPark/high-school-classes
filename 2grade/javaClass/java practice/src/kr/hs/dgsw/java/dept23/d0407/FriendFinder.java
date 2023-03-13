package kr.hs.dgsw.java.dept23.d0407;

import java.util.Scanner;

public class FriendFinder {
	private final Friend[] friendList;
	
	
	public FriendFinder() {
		friendList = makeFriendList();
	}
	
	public String findName(int number) {
		for (Friend friend: friendList) {
			if (friend.number == number) {
				return friend.name;
			}
		}
		
		return null;
	}
	
	public int findNumber(String name) {
		for (Friend friend: friendList) {
			if (friend.name.equals(name)) {
				return friend.number;
			}
		}
		
		return -1;
	}
	
	public void execute() {
		Scanner scanner = new Scanner(System.in);
		
		while (true) {
			System.out.println("찾을 번호나 이름을 입력하세요.");
			String input = scanner.next();
			
			if ("quit".equals(input)) {
				break;
			}
			
			int number = 0;
			try {
				number = Integer.parseInt(input);
			} catch (NumberFormatException e) {
				// do nothing
			}
			
			if (number > 0) {
				String name = findName(number);
				if (name != null) {
					System.out.printf("%d번의 이름은 '%s'입니다.\n", number, name);
				} else {
					System.out.printf("%d번은 없습니다.\n", number);
				}
			} else {
				number = findNumber(input);
				if (number > 0) {
					System.out.printf("'%s'은(는) %d번입니다.\n", input, number);
				} else {
					System.out.printf("%s는 2학년 3반 학생이 아닙니다.\n", input);
				}
			}
			
			
		}
		
		scanner.close();
		System.out.println("프로그램이 종료됩니다.");
	}
	
	private Friend[] makeFriendList() {
		Friend[] list = {
			new Friend(1, "정은서")
			, new Friend(2, "강성훈")
			, new Friend(3, "고용빈")
			, new Friend(4, "기준")
			, new Friend(5, "김민성")
			, new Friend(6, "류지훈")
			, new Friend(7, "박병관")
			, new Friend(8, "박성한")
			, new Friend(9, "박지건")
			, new Friend(10, "박현우")
			, new Friend(11, "손원")
			, new Friend(12, "안찬")
			, new Friend(13, "우상범")
			, new Friend(14, "윤병훈")
			, new Friend(15, "윤서준")
			, new Friend(16, "이승민")
			, new Friend(17, "이지호")
			, new Friend(18, "최민재")
			, new Friend(19, "한상빈")
		};
		
		return list;
	}
	
	private class Friend {
		private final int number;
		
		private final String name;
		
		public Friend(int number, String name) {
			this.number = number;
			this.name = name;
		}
	}
	
	public static void main(String[] args) {
		FriendFinder friendFinder = new FriendFinder();
		friendFinder.execute();
		
		
	}
}