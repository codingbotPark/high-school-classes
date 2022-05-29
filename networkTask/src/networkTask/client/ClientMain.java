package networkTask.client;

import java.io.IOException;
import java.net.Socket;

public class ClientMain {
	public static void main(String[] args) {
		try {
			Socket sc = new Socket("127.0.0.1",5000);
			
			// outputThread생성, 클래스 안에서 실행
			Output_Message om = new Output_Message(sc);
			Input_Message im = new Input_Message(sc);
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
