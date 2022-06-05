package networkTask.client;

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
	
	public void login(Socket sc) {
		String isLogin = ""; 
		String loginMsg = ""; // 로그인에 사용되는 메시지
		Scanner scan = null;
		
		try {
			// output, input stream 생성
			OutputStream os = sc.getOutputStream();
			InputStream is = sc.getInputStream();
			
			// 값을 주고받을 pw, br 생성
			PrintWriter pw = new PrintWriter(os,true);
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			
			scan = new Scanner(System.in);
			// 로그인 계속 요청
			while(true) {
				// id,pass 입력
				System.out.printf("ID: ");
				loginMsg = scan.nextLine() + " ";
				System.out.printf("PASS: ");
				loginMsg += scan.nextLine();
				
				// id,pass를 서버에 보냄
				pw.println(loginMsg);
				
				// id와 pass에 대한 서버값을 받음
				isLogin = br.readLine();
				
				if (isLogin.equals("true")) {
					// 로그인 했을 때 break
					System.out.println("**FTP 서버에 접속하였습니다**");
					ClientCommand command = new ClientCommand(sc);
					break;
				} else if (isLogin.equals("false")){
					System.out.println("**ID 또는 PASS가 틀림**");
				}
				
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("로그인 스트림 생성 실패");
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		
		try {
			Socket sc = new Socket("127.0.0.1", 5000); // 명령어 주고 받기용
			ClientMain cl = new ClientMain();
			cl.login(sc);
//			// 로그인
//			try {
//				String isLogin = "";
//				String loginMsg = "";
//				Scanner scan = null;
//				
//				OutputStream os = sc.getOutputStream();
//				InputStream is = sc.getInputStream();
//				while (true) {
//					
//					// id,pass를 입력
//					System.out.printf("ID: ");
//					scan = new Scanner(System.in);
//					loginMsg = scan.nextLine();
//					System.out.printf("PASS: ");
//					// id와 pass를 // 로 나눈다
//					loginMsg += " ";
//					scan = new Scanner(System.in);
//					loginMsg += scan.nextLine();
//					
//					// id, pass를 서버에 보냄
//					PrintWriter pw = new PrintWriter(os,true);
//					pw.println(loginMsg);
//					
//					// id와 pass에 대한 서버값을 받음
//					
//					BufferedReader br = new BufferedReader(new InputStreamReader(is));
//					isLogin = br.readLine();
//					
//					if (isLogin.equals("True")) {
//						// 로그인 했을 때 break
//						System.out.println("**FTP 서버에 접속하였습니다**");
//						ClientCommand command = new ClientCommand(sc);
//						break;
//					} else if (isLogin.equals("False")){
//						System.out.println("**ID 또는 PASS가 틀림**");
//					}
//				}
//				
//				
//			} catch (Exception e) {
//				// TODO: handle exception
//				e.printStackTrace();
//				System.out.println("Client:로그인 스크림 생성 실패");
//			}
			
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
