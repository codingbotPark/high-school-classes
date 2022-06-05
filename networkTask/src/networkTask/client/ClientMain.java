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

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		try {
			Socket scc = new Socket("127.0.0.1", 5000); // 명령어 주고 받기용
			
			// 로그인
			try {
				String isLogin = "";
				String loginMsg = "";
				Scanner scan = null;
				
				
				OutputStream cos = scc.getOutputStream();
				InputStream cis = scc.getInputStream();
				while (true) {
					
					// id,pass를 입력
					System.out.printf("ID: ");
					scan = new Scanner(System.in);
					loginMsg = scan.nextLine();
					System.out.printf("PASS: ");
					// id와 pass를 // 로 나눈다
					loginMsg += " ";
					scan = new Scanner(System.in);
					loginMsg += scan.nextLine();
					
					// id, pass를 서버에 보냄
					PrintWriter pw = new PrintWriter(cos,true);
					pw.println(loginMsg);
					
					// id와 pass에 대한 서버값을 받음
					
					BufferedReader br = new BufferedReader(new InputStreamReader(cis));
					isLogin = br.readLine();
					
					if (isLogin.equals("True")) {
						// 로그인 했을 때 break
						System.out.println("**FTP 서버에 접속하였습니다**");
						ClientCommand command = new ClientCommand(scc);
						break;
					} else if (isLogin.equals("False")){
						System.out.println("**ID 또는 PASS가 틀림**");
					}
				}
				
				
			} catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
				System.out.println("Client:로그인 스크림 생성 실패");
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
