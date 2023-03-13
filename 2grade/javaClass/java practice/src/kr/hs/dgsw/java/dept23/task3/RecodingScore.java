package kr.hs.dgsw.java.dept23.task3;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class RecodingScore {
	File file;
	FileWriter fw;
	BufferedWriter writer;	
	GetScore getScore;
	
	public void writeScore(String content) {
		try {
			fw = new FileWriter(file);
			writer = new BufferedWriter(fw);
			writer.write(content);
			writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	public void confirmFile() {
		if (!file.exists()) {
			try {
				file.createNewFile();
				writeScore("0 0 0");
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("**파일설정실패**");
				System.exit(0);
				e.printStackTrace();
			}
		} 
	}
	
	
	public void recode(int value) {
		int[] result = getScore.readRecorded();
		result[value]++;
		writeScore(Arrays.toString(result).replaceAll("[^0-9 ]",""));
	}
	
	public void printRecoded() {
		int[] result = getScore.readRecorded();
		System.out.printf("%d승 %d무 %d패\n",result[0],result[1],result[2]);
	}
	
	public RecodingScore() {
		// TODO Auto-generated constructor stub
		// 현재 위치 파일 생성
		this.file = new File(System.getProperty("user.dir") + "\\score.txt");
		getScore = new GetScore(file);
		
		// 파일 존재를 확실하게 한다, fw 와 writer를 세팅
		// 기본 세팅으로 파일에 "0 0 0" 을 넣어 0승, 0무, 0패를 넣는다 
		confirmFile();
		
	}
}
