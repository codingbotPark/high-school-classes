package networkTask.server;

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
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class CommandThread extends Thread{
	public static List<CommandThread> ClientList = 
			Collections.synchronizedList(new ArrayList<CommandThread>());
	
	
	private Socket sc = null;
	
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
	
	
	InputStream is = null;
	OutputStream os = null;
	PrintWriter pw = null;
	
	// 파일
	BufferedInputStream bir;
	DataInputStream dis;
	
	public void command() {
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		
		File Folder = new File("C:\\files");
		
		// 보낼 메시지
		String msg;
		
		// ls를 모듈화 하여
		// 업로드, 다운로드 할 때도 ls함수를 실행시켜준다
		
		while(true) {
			// 초기화
			msg = "";
			
			try {
				String command = br.readLine();
				if (command.equals("ls")) {
					
					// 폴더가 없다면 생성
					if (!Folder.exists()) {
						try {
							Folder.mkdir();
							System.out.println("폴더 생성");
						} catch (Exception e){
							System.out.println("폴더 생성 실패");
						}
					}
					
					
					
					msg = list(Folder);
					
					// 리스트 보내기
					pw.println(msg);
					
				} else if (command.startsWith("ul")) {
					
					String[] commands = command.split(" ",3);	
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
					
					String[] commands = command.split(" ",2);
					File file = new File(Folder + "\\" +commands[1]);
					
//					System.out.println(file.exists());
//					System.out.println(file.getAbsolutePath());
					
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
					
				}
			}catch (IOException e) {
				// TODO Auto-generated catch block
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
		} catch (IOException e) {
			// TODO: handle exception
			System.out.println("서버 스트림 생성 실패");
		}
		
		// 아이디 비밀번호 체크
		BufferedReader br = null;
		String[] loginMsg = null;
		br = new BufferedReader(new InputStreamReader(is));
		
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
		
		// 아이디 체크가 되면 add, command를 받는다
		ClientList.add(this);
		// command를 받기 시작
		command();
		
		
	}
}
