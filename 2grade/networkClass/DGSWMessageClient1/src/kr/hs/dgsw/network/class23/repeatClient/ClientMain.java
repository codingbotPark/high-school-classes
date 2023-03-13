package kr.hs.dgsw.network.class23.repeatClient;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class ClientMain {
	public static void main(String[] args) {
		try {
			Socket sc = new Socket("127.0.0.1",5000);
			
			Output_Message om = new Output_Message(sc);
			om.start();
			
			Input_Message im = new Input_Message(sc);
			im.start();
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		
//		Output_Message om = new Output_Message(sc);
//		om.start();
	}
}
