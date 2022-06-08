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

	long byteSize;

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
			
			fout.flush();
			fout.close();
			// 다 못받고 나왔다면
			if (byteSize != 0) {
				System.out.println("완벽한 다운로드에 실패");
				// 파일이 존재한다면
				if (file.exists()) {
					// 파일을 잡고있는 경우 파일 삭제를 실패할 수도 있다
					for (int i = 0; i < 50; i++) {
						if (file.delete()) { // 성공했을 때 break
							System.out.println("다운로드 받던 파일을 삭제했습니다");
						} else {
							// 삭제 못했을 때 1초 기다리기
							try {
								Thread.sleep(1000);
							} catch (InterruptedException e1) {
								e1.printStackTrace();
							}
						}
					}
				}
			}
		} catch (IOException e) {
			// TODO: handle exception	
			
			System.out.println("파일 다운로드 실패");
		}
	}

	public DownLoadFile(InputStream is, File file, long size) {
		// TODO Auto-generated constructor stub

		try {
			this.is = is;
			this.file = file;
			this.byteSize = size;

			this.bir = new BufferedInputStream(is);
			this.dis = new DataInputStream(bir);
			this.fout = new FileOutputStream(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("파일 받기 세팅 실패");
			e.printStackTrace();
		}

		downLoad();
	}

}
