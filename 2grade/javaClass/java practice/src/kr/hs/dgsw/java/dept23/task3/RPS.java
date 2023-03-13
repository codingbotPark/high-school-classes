package kr.hs.dgsw.java.dept23.task3;

public class RPS {
	ValueCase selectedCase;
	
	RSPbot bot = new RSPbot();
	RecodingScore recoder = new RecodingScore();
	
	public int convert(String value) {
		if ("가위".equals(value)) {
			// 가위이고, 보일 때 이기고, 바위 일 때 진다
			selectedCase = new ValueCase("가위","보","바위");
		} else if ("바위".equals(value)) {
			selectedCase = new ValueCase("바위","가위","보");
		} else if ("보".equals(value)) {
			selectedCase = new ValueCase("보","바위","가위");
		} else {
			return -1;
		}
		// 정상적일 때
		return 0;
	}
	
	public void compare(int value) {
		int recordedValue; // -1은 짐, 0은 비김, 1은 이김
		
		String botValue = bot.doRSP();
		System.out.printf("%s vs %s ;",selectedCase.me,botValue);
		if (selectedCase.me.equals(botValue)) { // 비겼을 때
			System.out.println("비겼습니다");
			recordedValue = 1;
		} else if(selectedCase.win.equals(botValue)){ //이겼을 때
			System.out.println("이겼습니다");
			recordedValue = 0;
		} else {
			System.out.println("졌습니다");
			recordedValue = 2;
		}
		recoder.recode(recordedValue);
		recoder.printRecoded();
	}

	public void doRPS(String value) {
		int compareValue = convert(value);
		// 가위바위보 가 아닌 문자열이 들어가면 if문에 들어가지 않는다
		if (compareValue != -1) { 
			compare(compareValue);
		}
	}
}
