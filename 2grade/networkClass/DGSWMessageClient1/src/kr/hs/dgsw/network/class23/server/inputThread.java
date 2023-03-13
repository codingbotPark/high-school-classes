package kr.hs.dgsw.network.class23.server;

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


public class inputThread extends Thread{
	public static List<inputThread> ClientList = 
			Collections.synchronizedList(new ArrayList<inputThread>());
	
	Socket sc = null;
	PrintWriter pw = null;
	String nickname = null;
	
	public inputThread(String msg, Socket sc) {
		this.sc = sc;
		this.nickname = msg;
		ClientList.add(this);
		
		OutputStream os = null;
		try {
			os = sc.getOutputStream();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		pw = new PrintWriter(os, true);
	}

	public void msgPringln(String msg) {
		pw.println(msg);
	}
	
	public void run() {

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
			while (true) {

				String msg = br.readLine();
				if (msg.substring(0,1).equals("G")) {
					String[]msgarr = msg.substring(1).split("::");
					for (inputThread tmpit:ClientList) {
						if (tmpit.nickname == msgarr[0]) {
							tmpit.msgPringln(("[귓속말]" + nickname + ":" + msgarr[1]));
						}
					}
				} else {
					for (inputThread tmpit:ClientList) {
						if(tmpit != this) {
							tmpit.msgPringln(nickname + ": " + msg.substring(1));
						}
					}
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("?꾧뎔媛媛 ?묒냽 醫낅즺?섏??듬땲??");
		}
	}

}
