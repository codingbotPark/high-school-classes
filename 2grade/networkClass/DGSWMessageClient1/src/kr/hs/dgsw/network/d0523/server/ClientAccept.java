package kr.hs.dgsw.network.d0523.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class ClientAccept {
	public Socket sc = null;
	
	private OutputStream os = null;
	private PrintWriter pw = null;
	private BufferedReader br = null;
	
	
	// 생성
	public ClientAccept(Socket sc) {
		this.sc = sc;
		
		// 메시지 보내기 객체 생성
		try {
			// os에 OutputStream을 가져옴
			this.os = sc.getOutputStream();
			this.pw = new PrintWriter(this.os, true);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		// 메시지 받기 객체 생성
		InputStream is = null;
		try {
			// 소켓을 입력 받고 소켓에 InputStream생성
			is = sc.getInputStream();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		// InputStream의 buffer를 저장
		this.br = new BufferedReader(new InputStreamReader(is));
	}
	
	// 메시지 보내기
	public void sendMessage(String msg) {
		// println으로 보냄
		pw.println(msg);
	}
	
	public String readMessage() throws IOException{
		// 버퍼를 읽는다
		return br.readLine();
	}
}
