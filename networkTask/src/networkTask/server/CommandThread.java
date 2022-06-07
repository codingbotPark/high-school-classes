package kr.hs.dgsw.network.test01.n2307.server;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class CommandThread extends Thread{
	
	InputStream is = null;
	OutputStream os = null;
	PrintWriter pw = null;
	BufferedReader br = null;
	
	// 파일
	BufferedInputStream bir;
	DataInputStream dis;
	
	private Socket sc = null;
	
	// 
	public String list(File Folder) {
		String msg = "\\";
		String[] fileList;
		// fileList출력
		fileList = Folder.list();
		if (fileList.length > 0) {
			msg = "";
			for(String file:fileList) {
				msg+=(file + ":");
			}
		}
		
		// 없다면 기본값인 \\가 들어감
		return msg;
	}
	
	
	public void command() {
		
		
		File Folder = new File("C:\\files");
		
		// 폴더가 없다면 생성
		if (!Folder.exists()) {
			try {
				Folder.mkdir();
			} catch (Exception e){
				System.out.println("폴더 생성 실패");
			}
		}
		
		// 보낼 메시지
		String msg;
		// 명령어
		String command;
		// 나눈 명령
		String[] commands;
		
		while(true) {
			// 초기화
			msg = "";
			
			try {
				
				command = br.readLine();
				
				
				if (command.equals("ls")) {
						
					msg = list(Folder);
					
					// 리스트 보내기
					pw.println(msg);
					
				} else if (command.startsWith("ul")) {
					
					commands = command.split(" ",3);	
					System.out.println(commands[1]);
					File file = new File(Folder + "\\" + commands[1]);
					System.out.println(file.getAbsolutePath());
					
					try {
						
						// int형으로 변환
						int byteSize = Integer.parseInt(commands[2]);
						System.out.println(byteSize);
						// 파일 생성
						file.createNewFile();
						FileOutputStream fout = new FileOutputStream(file);
						
						byte[] bytes = new byte[1024];
						int readbit = 0;
						
						// 여러 번 보낼 때 여러 번 받기
						while((readbit = dis.read(bytes)) != -1){
							byteSize -= readbit;
							fout.write(bytes,0,readbit);
							if (byteSize == 0) {
								break;
							}
							
						}
						fout.flush();
						fout.close();

						
					} catch (IOException e) {
						// TODO: handle exception
						System.out.println("파일 아웃풋 스트림 생성 실패");
					}	
				} else if (command.startsWith("dl")) {
					
					commands = command.split(" ",2);
					File file = new File(Folder + "\\" +commands[1]);
					
					pw.println(file.length());
					
					BufferedOutputStream bos = new BufferedOutputStream(os);  
					DataOutputStream dos = new DataOutputStream(bos);
					FileInputStream fis = new FileInputStream(file);
					
					// bytes도 dl, ul 같이 사용
					byte[] bytes = new byte[1024];
					int readbit = 0;
					System.out.println("파일 보내기 시작");
					try {
						while (true) {
							readbit = fis.read(bytes);
							if (readbit == -1) {
								dos.flush();
								break;
							}
							dos.write(bytes, 0, readbit);

						}
					}catch (IOException e) {
						// TODO: handle exception
					}
					System.out.println("파일 보내기 끝");
					
				} else if (command.equals("quit")) {
					sc.close();
				}
				
			}catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("catch");
				try {
					sc.close();
					System.out.println("클로스 했음");
					break;
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				e.printStackTrace();
			}
		}
	}
	
	
	
	
	
	public CommandThread(Socket sc) {
		this.sc = sc;
		
		try {
			// inputStream과 outputStream 생성
			this.os = sc.getOutputStream();
			this.pw = new PrintWriter(os,true);
			this.is = sc.getInputStream();
			
			this.bir = new BufferedInputStream(is);
			this.dis = new DataInputStream(bir);
			
			this.br = new BufferedReader(new InputStreamReader(is));
		} catch (IOException e) {
			// TODO: handle exception
			System.out.println("서버 스트림 생성 실패");
		}
		
	}
	
	@Override
	public void run() {
		// 아이디 비밀번호 체크
		String[] loginMsg = null;
		
		try {
			while(true) {
				String idPass = br.readLine();
				loginMsg = idPass.split(" ",2);
				if (loginMsg[0].equals("admin") && loginMsg[1].equals("1234")) {
					pw.println("true");
					break;
				} else {
					pw.println("false");
				}
			}
		}catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("버퍼 읽기 실패");	
		}
		
		// command를 받기 시작
		command();
		
	}
}
