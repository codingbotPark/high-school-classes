package kr.hs.dgsw.network.class23.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

import kr.hs.dgsw.network.class23.server.inputThread;

public class InputThread extends Thread {
	Socket sc = null;
	
	public InputThread(Socket sc) {
		this.sc = sc;
	}

	public void run() {
		// 받기
		InputStream is = null;
		try {
			is = sc.getInputStream();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		BufferedReader br = 
				new BufferedReader(new InputStreamReader(is));
		
		try {
			while(true)
				System.out.println(br.readLine());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


}
