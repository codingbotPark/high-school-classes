package networkTask.client;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.file.Files;

public class SendFile {

	OutputStream cos;
	File file;
	
	BufferedOutputStream bos;
	DataOutputStream dos;
	FileInputStream fis;

	public void send() {
		// 1024씩 읽고, readbit를 저장해서 비교
		byte[] bytes = new byte[1024];
		int readbit = 0;
		try {

			while (true) {
				readbit = fis.read(bytes);
				
				// 읽은게 없을 때 까지
				if (readbit == -1) {
					dos.flush();
					break;
				}
				dos.write(bytes, 0, readbit);

			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public SendFile(OutputStream cos, File file) {
		// TODO Auto-generated constructor stub
		try {
			this.cos = cos;
			this.bos = new BufferedOutputStream(cos);
			this.dos = new DataOutputStream(bos);
			this.file = file;
			this.fis = new FileInputStream(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("파일 보내기 세팅 실패");
			e.printStackTrace();
		}
		send();
	}
}
