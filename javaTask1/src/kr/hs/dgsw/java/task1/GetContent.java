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

	public String[] getContent() {
		ArrayList<String> fileContent = new ArrayList<String>();
		
		try {
			FileInputStream input = new FileInputStream(file);

			InputStreamReader reader = new InputStreamReader(input, "UTF-8");
			BufferedReader br = new BufferedReader(reader);

			String temp;

			while ((temp = br.readLine()) != null) {
				fileContent.add(temp);
			}
			br.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return fileContent.toArray(new String[0]);
	}

	public GetContent(File file) {
		// TODO Auto-generated constructor stub
		this.file = file;
	}
}
