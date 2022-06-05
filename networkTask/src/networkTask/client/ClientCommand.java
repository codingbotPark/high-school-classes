package networkTask.client;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ClientCommand {

	Socket scc;

	Scanner scan = new Scanner(System.in);

	String command;

	OutputStream cos;
	InputStream cis;
	PrintWriter pw;

	public void execute() {
		// pw 설정
		this.pw = new PrintWriter(cos, true);
		// br 설정
		BufferedReader br = new BufferedReader(new InputStreamReader(cis));
		
		
		while (true) {
			System.out.printf("Write command: ");
			command = scan.nextLine();
			
//			System.out.println("client에서 command받는중");
			// 파일 목록
			if (command.equals("ls")) {
				// 파일 목록
				String[] list;
				// 파일 개수
				int fileNum = 0;
				
				pw.println("ls");
				System.out.println("** File List **");
				
				// 읽고 list에 string배열로 저장
				try {
					list = (br.readLine()).split(":");
					
					// 비었다면 \을 서버에서 보내준다
					if (!list[0].equals("\\")) {
						for (String name:list) {
							System.out.printf("** %s **\n",name);
						}
						fileNum = list.length;
					}
					// 파일 개수 출력
					System.out.printf("** %d개 파일 **\n",fileNum);
					
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				};
				
			} else if(command.startsWith("ul")) { // 업로드
				
				if (!command.contains(" ")) {
					continue;
				}
				
				String[] commands = command.split(" ",2);
				
				// split 잘못되면 client로그인 스트림 생성 실패 오류
				String[] FileNames = commands[1].split("\\\\"); 
				String FileName = FileNames[FileNames.length - 1];
				
				
				String[] list = null;
				try {
					// 보내기 전 파일리스트를 가져온다
					pw.println("ls");
					list = (br.readLine()).split(":");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					System.out.println("리스트 받기 실패");
					e.printStackTrace();
				}
				
				// 동일 파일 검사
				String YorN = "Yes"; // 기본값은 true
				for(String name:list) {
					if (name.equals(FileName)) {
						System.out.printf("파일이 이미 있습니다. 덮어쓰기 하실건가요??(Yes: 덮어쓰기 / No: 업로드 취소): ");
						YorN = scan.nextLine();
						break;
					}
				}
				
				// 파일이 존재할 때
				if (new File(commands[1]).exists()) {
					if (YorN.equals("Yes")) {
						// 명령어와 파일 이름, 파일크기을 서버에 보낸다
						
						File file = new File(commands[1]);
						
						// ul와 파일 이름, 파일 길이를 보낸다(바이트 단위)
						pw.println("ul " + FileName + " " + file.length());
						// 파일을 보낸다
						SendFile sendfile = new SendFile(cos,file);
					}
				} else {
					System.out.println("파일이 존재하지 않습니다");
				}
				
			} else if(command.startsWith("dl")) {// 다운로드
				
				String[] commands = command.split(" ", 2);
				
				String[] list = null;
				try {
					// 보내기 전 파일리스트를 가져온다
					pw.println("ls");
					list = (br.readLine()).split(":");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					System.out.println("리스트 받기 실패");
					e.printStackTrace();
				}
				
				// 동일 파일 검사
				boolean canDl = false;
				for(String name:list) {
					if (name.equals(commands[1])) {
						canDl = true;
						break;
					}
				}
				
				if (canDl) { // 다운로드 할 파일이 존재할 때
					//다운로드 명령과 다운로드할 파일을 요청
	
					pw.println("dl "+commands[1]);
					
					String size = "0";
					try {
						size = br.readLine();
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					
					
					
					// 다운로드 없으면 만들어 주기
					File file = new File("D:\\download\\"+commands[1]);
					
					try {
						// 파일 크기를 int형으로 바꿈
						int byteSize = Integer.parseInt(size);
						file.createNewFile();
						// 파일에 넣기
						FileOutputStream fout = new FileOutputStream(file);
						
						byte[] bytes = new byte[1024];
						int readbit = 0;
						
						BufferedInputStream bir = new BufferedInputStream(cis);
						DataInputStream dis = new DataInputStream(bir);
						
						while((readbit = dis.read(bytes)) != -1) {
							byteSize -= readbit;
							fout.write(bytes,0,readbit);
							if (byteSize == 0) {
								break;
							}
						}
						
					} catch (IOException e) {
						// TODO: handle exception
						System.out.println("파일 다운로드 실패");
					}
					
				} else {
					System.out.println("서버에 존재하지 않는 파일입니다");
				}
	
			}
			else {
				System.out.println("**없는 명령어입니다**");
			}

		}
	}

	public ClientCommand(Socket scc) {
		// TODO Auto-generated constructor stub
		this.scc = scc;
		try {
			// 스트림 생성
			this.cos = scc.getOutputStream();
			this.cis = scc.getInputStream();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		execute();
	}

}
