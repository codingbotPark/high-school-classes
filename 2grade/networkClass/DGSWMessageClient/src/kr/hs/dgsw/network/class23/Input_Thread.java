package kr.hs.dgsw.network.class23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Input_Thread extends Thread {
	Socket sc = null;

	public Input_Thread(Socket sc) {
		this.sc = sc;
	}

	public void run() {
		// null 로 초기화 했다가 sc가 들어오면 실행을 해준다
		// InputStreamReader is = sc.getInputStream();
		InputStream is = null;
		try {
			is = sc.getInputStream();

		} catch (IOException e) {
			e.printStackTrace();
		}
		// br 에 is의 값을 넣음
		BufferedReader br = new BufferedReader(new InputStreamReader(is));

		try {
			System.out.println(br.readLine());
			// br의 값을 읽음
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
