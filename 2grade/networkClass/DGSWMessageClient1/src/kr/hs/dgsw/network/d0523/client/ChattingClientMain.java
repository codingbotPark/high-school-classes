package kr.hs.dgsw.network.d0523.client;

import java.net.Socket;

public class ChattingClientMain {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try {
			Socket sc = new Socket("127.0.0.1",5000);
			
			Output_Message om = new Output_Message(sc);
			om.start();
			
			Input_Message im = new Input_Message(sc);
			im.start();
		} catch(Exception e) {
			System.out.println("연결 종료");
			e.printStackTrace();
		}
	}
}
