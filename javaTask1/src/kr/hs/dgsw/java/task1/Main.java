package kr.hs.dgsw.java.task1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

// 파일에는 파일 전화번호 의 형태로 저장된다
//인자로 보낸 파일, 라인 으로 선택된 라인을 enter로 띄어주는 class만들기(ㅑ) 

public class Main {

	public void confirmFile(File file) {
		// 파일이 존재하지 않을 때 생성
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("파일 생성 실패");
				e.printStackTrace();
			}
		}
	}
	
	// 인자로 받은 파일의 라인 개수를 리턴해준다
	public boolean isEmpty(File file) {
		boolean isEmpty = true;
		try {
			BufferedReader br = new BufferedReader(new FileReader(file));
			// buffer를 한 번 읽는다
			String firstLine = br.readLine();
			if (firstLine != null){
				isEmpty = false;
			}
			br.close();
		} catch (Exception e) {
			System.out.println("getFileLength오류");
			// TODO: handle exception
		}
		return isEmpty;
	}
	
	// 기본 세팅을 해준다(파일,도움말)
	public void setting(File file) {
		try {
			FileOutputStream output = new FileOutputStream(file,false);
			OutputStreamWriter writer = new OutputStreamWriter(output,"UTF-8");
			BufferedWriter out = new BufferedWriter(writer);
			
			out.write("\n");
			out.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

	public static void main(String[] args)  {
		// 현재 위치에 파일 생성
		File file = new File(System.getProperty("user.dir") + "\\phoneNumber.txt");

		Main main = new Main();
		
		// 파일이 없다면 생성
		main.confirmFile(file);
		// 파일에 내용이 없다면 기본세팅을 해준다
//		if (main.isEmpty(file)) { // 비어있을 때
//			main.setting(file);
//		}
		
		
		// 세팅 완료시 command로 넘어간다
		Command command = new Command(file);
		
	}
}


// randomAccessFile utf사용하려 했는데, 안됐다