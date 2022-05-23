package kr.hs.dgsw.network.d0523.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerMain {
	public static void main(String[] args) {
		ServerSocket ss = null;
		try {			
			ss = new ServerSocket(5000);
			System.out.println("서버시작");
			
			while(true) {
				// 데이터 주고받는 객체
				Socket sc = ss.accept();
				// 접속된 clinet의 아이디
				System.out.println(sc.getInetAddress()+":접속하였습니다");
				
				try {
					// 데이터 주고 받는 객체
					ClientAccept ca = new ClientAccept(sc);
					
					Thread ct = new ClientThread(sc.getInetAddress().toString(),ca);
					ct.start();
				} catch (Exception e) {
					System.out.println("연결종료");
				}
			}
			
		} catch (Exception e) {
		} finally {
			try {
				ss.close();
			} catch(IOException) {}
		}
	}
}
