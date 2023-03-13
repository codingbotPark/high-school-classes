package kr.hs.dgsw.network.class23.repeatServer;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerMain {
	public static void main(String[] args) {
		ServerSocket ss = null;
		try {
			ss = new ServerSocket(5000);
			
			// 여러 명을 받기 위해 while문으로 accept를 한다
			while (true) {
				Socket sc = ss.accept();
				System.out.println(sc.getInetAddress());
				
				ClientThread ct = new ClientThread(sc);
				ct.start();
			}	
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				ss.close();
			} catch(IOException e) {}
		}
		
		
	}
}
