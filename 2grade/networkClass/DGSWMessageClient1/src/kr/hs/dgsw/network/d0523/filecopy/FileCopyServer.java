package kr.hs.dgsw.network.d0523.filecopy;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class FileCopyServer {
	public static void main(String[] args) throws IOException{
		ServerSocket ss = new ServerSocket(5000);
		Socket sc = ss.accept();
		
		InputStream os = sc.getInputStream();
		BufferedInputStream bir = new BufferedInputStream(os);
		DataInputStream dis = new DataInputStream(bir);
		
		
		String fileName = dis.readUTF();
		FileOutputStream fos = new FileOutputStream("C:\\Users\\DGSW\\Desktop\\myimg\\" + fileName);
	
		
		
		byte[] bytes = new byte[1024];
		int readbit = 0;
		
		
		// 정상적인 종료가 되지 않는다
		// while문에서 클라이언트가 파일을 보내기를 기다린다
		while((readbit = dis.read(bytes)) != -1)
			fos.write(bytes,0,readbit);
	}
}
