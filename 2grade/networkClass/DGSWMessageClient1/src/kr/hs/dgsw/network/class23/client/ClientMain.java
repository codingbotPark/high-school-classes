package kr.hs.dgsw.network.class23.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class ClientMain {
	public static void main(String[] args) {
		try {
			
			Socket sc = new Socket("127.0.0.1", 5000);
			
			String nboolean ="NNG";
			while(!nboolean.equals("NOK")) {
				// NickName ?ㅼ젙
				
				System.out.printf("?됰꽕?꾩쓣 ?ㅼ젙?섏꽭?? ");
				Scanner scan = new Scanner(System.in);
				
				OutputStream os = null;
				try {
					os = sc.getOutputStream();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				PrintWriter pw = new PrintWriter(os, true);
				
				pw.println("N"+scan.nextLine());
				
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
					nboolean = br.readLine();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			Thread ot = new OutputThread(sc);
			Thread it = new InputThread(sc);
			
			ot.start();
			it.start();
			
			try {
				ot.join();
				it.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
