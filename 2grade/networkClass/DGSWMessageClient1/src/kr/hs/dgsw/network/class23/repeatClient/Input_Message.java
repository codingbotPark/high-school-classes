package kr.hs.dgsw.network.class23.repeatClient;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Input_Message extends Thread{
	private Socket sc = null;
	
	public Input_Message(Socket sc) {
		this.sc = sc;
	}
	
	public void run() {
		try {
			InputStream is = sc.getInputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			while(true) {
				System.out.println(br.readLine());
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
