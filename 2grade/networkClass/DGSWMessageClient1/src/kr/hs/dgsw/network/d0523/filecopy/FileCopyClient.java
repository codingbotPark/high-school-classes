package kr.hs.dgsw.network.d0523.filecopy;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;


// 파일 명도 주고받아야 한다


public class FileCopyClient {
	
	
	public static void main(String[] args) {
		
		Socket sc;
		try {
			sc = new Socket("10.80.162.206",5000);
			OutputStream os = sc.getOutputStream();
			BufferedOutputStream bor = new BufferedOutputStream(os);
			DataOutputStream dos = new DataOutputStream(bor);
			
			File f1 = new File("C:\\Users\\DGSW\\Desktop\\myimg\\velogProfile.jpg");
			FileInputStream fis = new FileInputStream(f1);
			
			byte[] bytes = new byte[1024];
			int readbit = 0;
			
			// 파일 명을 보내주기 위한
			// utf-8로 바꿔서 파일 이름을 보내준다
			dos.writeUTF(f1.getName());
			
			// 서버에 보낸
			while((readbit = fis.read(bytes)) != -1)
				dos.write(bytes,0,readbit);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	
		
		
	}

}
