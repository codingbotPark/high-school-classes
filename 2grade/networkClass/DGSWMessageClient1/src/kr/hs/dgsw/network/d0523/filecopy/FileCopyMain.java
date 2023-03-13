package kr.hs.dgsw.network.d0523.filecopy;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileCopyMain {
	public static void main(String[] args) {
		File f1 = new File("C:\\Users\\DGSW\\Desktop\\myimg\\velogProfile.jpg");
		try {
			FileInputStream fis = new FileInputStream(f1);

			FileOutputStream fos = new FileOutputStream("C:\\Users\\DGSW\\Desktop\\myimg\\testVelogProfile.jpg");
			
			//1kb씩 파일을 저장해서 복사
			byte[] bytes = new byte[1024];
			
			// fis의 내용을 읽어서 bytes에 저장
			// 읽어온 용량을 반환, 없다면 -1을 반환
			int readbit = 0;
			
			try {
				while((readbit = fis.read(bytes)) != -1)
					// 인자값 0과 readbit는 데이터를 정리할 때 편하기 위해
					fos.write(bytes,0,readbit);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			// bytes에 이미지 내용이 저장되어있고, readbit에 내용 길이가 저장
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
