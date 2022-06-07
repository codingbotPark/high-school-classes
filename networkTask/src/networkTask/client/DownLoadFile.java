package kr.hs.dgsw.network.test01.n2307.client;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class DownLoadFile {
	
	InputStream is;
	DataInputStream dis;
	
	File file;
	FileOutputStream fout;
	
	BufferedInputStream bir;
	
	int byteSize;
	
	public void downLoad() {
		try {
			file.createNewFile();
			// 파일에 넣기

			byte[] bytes = new byte[1024];
			int readbit = 0;

			while ((readbit = dis.read(bytes)) != -1) {
				byteSize -= readbit;
				fout.write(bytes, 0, readbit);
				if (byteSize == 0) {
					break;
				}
			}

		} catch (IOException e) {
			// TODO: handle exception
			System.out.println("파일 다운로드 실패");
		}
	}
	
	public DownLoadFile(InputStream is,File file,int size) {
		// TODO Auto-generated constructor stub

		try {
			this.is = is;
			this.file = file;
			this.byteSize = size;
			
			this.bir = new BufferedInputStream(is);
			this.dis= new DataInputStream(bir);
			this.fout = new FileOutputStream(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("파일 받기 세팅 실패");
			e.printStackTrace();
		}
		
		downLoad();
	}
	
}
