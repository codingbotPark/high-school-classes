package kr.hs.dgsw.java.dept23.task3;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class GetScore {
	File file;

	public int[] convertStringArray(String score) {
		String[] values = score.split(" ", 3);
		int[] returnValues = {-1,-1,-1};
		for (int i = 0; i < values.length; i++) {
			returnValues[i] = Integer.parseInt(values[i]);
		}
		return returnValues;
	}

	public int[] readRecorded() {
		int[] values = null;
		try {
			BufferedReader reader = new BufferedReader(new FileReader(file));

			values = convertStringArray(reader.readLine());
		} catch (IOException e) {
			System.out.println("파일읽기 실패");
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return values;
	}

	public GetScore(File file) {
		// TODO Auto-generated constructor stub
		this.file = file;
	}
}
