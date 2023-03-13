package kr.hs.dgsw.network.class23.repeatServer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class ClientThread extends Thread{
	// 통신하는 사람들의 리스트
	private static List<ClientThread> ClientList = Collections.synchronizedList(new ArrayList<ClientThread>());

	private Socket sc = null;
	private Scanner scan = new Scanner(System.in);

	OutputStream os = null;
	PrintWriter pw = null;
	
	// 소켓을 입력으로 받고
	public ClientThread(Socket sc) {
		this.sc = sc;
		
		// 리스트에 이 ClientThread를 넣는다
		ClientList.add(this);
		
		try {
			// Client의 Stream을 만든다
			os = sc.getOutputStream();
			pw = new PrintWriter(os, true);
			// printWriter은 스트림에 있는 개체의 형식화된 텍스트 출력으로 인쇄
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void sendMessage(String msg) {
		pw.println(msg);
	}
	
	public void run() {
		try {
			InputStream is = sc.getInputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			while (true) {
				String brmsg = br.readLine();
				for (ClientThread cttmp:ClientList) {
					cttmp.sendMessage(brmsg);
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			ClientList.remove(this);
		}
	}

}
