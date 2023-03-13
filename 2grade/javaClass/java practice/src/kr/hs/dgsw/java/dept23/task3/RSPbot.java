package kr.hs.dgsw.java.dept23.task3;

import java.util.Random;

public class RSPbot {
	public String doRSP() {
		Random rand = new Random();
		int randNum = rand.nextInt(3);
		if (randNum == 0) {
			return "가위";
		} else if (randNum == 1) {
			return "바위";
		} else {
			return "보";
		}
	}
}
