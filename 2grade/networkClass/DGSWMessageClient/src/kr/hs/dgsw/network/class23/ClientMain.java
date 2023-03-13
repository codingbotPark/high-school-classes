package kr.hs.dgsw.network.class23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientMain {

	public static void main(String[] args) throws Exception {

		// 선생님의 ip에 접속
		Socket sc = new Socket("127.0.0.1", 5000);
		OutputStream os = sc.getOutputStream();
		PrintWriter pw = new PrintWriter(os, true);
		// 네트워크는 꼭 예외처리가 필요하다

		pw.println("만나서 반갑습니다.");

		InputStream is = sc.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(is));

		System.out.println(br.readLine());

	}

}
