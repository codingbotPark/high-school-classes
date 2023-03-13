package networkTask.client;

import java.net.Socket;

public class Output_Message extends Thread{
	private Socket sc = null;
	
	public Output_Message(Socket sc) {
		
		
		
		this.start();
	}
}

