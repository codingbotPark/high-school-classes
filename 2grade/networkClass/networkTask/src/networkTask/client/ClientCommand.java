package kr.hs.dgsw.network.test01.n2307.client;

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

	OutputStream os;
	InputStream is;

	PrintWriter pw;
	BufferedReader br;

	Scanner scan = new Scanner(System.in);
	String command;
	
	// 파일 사이즈를 지정
	public String resize(String fileSize) {
		long size = Long.parseLong(fileSize);
		String[] units = {"","Kb","Mb","Gb","Tb"};
		
		int i = 0;
		for (i = 0;size > 1024;i++) {
			size/=1024;
		}
		return size + units[i];
	}

	public void ls() {
		// 파일 목록과 파일 개수
		String[] fileList;
		int fileNum = 0;
		// 서버 요청
		pw.println("ls");
		System.out.println("** File List **");

		// 읽고 list에 string배열로 저장
		// 파일과 파일을 나누는 기준을 띄어쓰기 때문에 : 로 했다
		try {
			fileList = (br.readLine()).split(":");

			// 비었다면 \을 서버에서 보내준다
			if (!fileList[0].equals("\\")) {
//				for (String file : fileList) {
//					System.out.printf("** %s **\n", file);
//				}
				for (int i = 0;i<fileList.length;i++) {
					if(i % 2 == 0) { // 짝수일 때
						System.out.printf("** %20s ",fileList[i]);
					} else {
						System.out.printf("%10s **\n",resize(fileList[i]));
					}
				}
				// 인덱스 짝수 = 파일 이름
				// 인덱스 홀수 = 파일 크기
				fileNum = fileList.length / 2;
			}
			System.out.printf("** %d개 파일 **\n", fileNum);

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	// ls를 사용하는데에, fileName을 넣으면 그 파일이 서버에 있는지(true), 없는지(false)를 리턴
	public boolean ls(String fileName) {
		String fileList;
		pw.println("ls");
		try {
			fileList = br.readLine();
			// 파일 리스트는 ":" 을 간격으로 오기 때문에 contains를 사용해도 된다
//			if (fileList.contains(fileName))
//				return true;
			
			String[] fileInfos = fileList.split(":");
			for (int i=0;i < fileInfos.length;i+=2) {
				if (fileInfos[i].equals(fileName)) {
					return true;
				}
			}

		} catch (Exception e) {
			// TODO Auto-generated catch block
			System.out.println("list요청 후 값 받아오지 못함");
			e.printStackTrace();
		}
		;
		// 포함하지 않으면 0
		return false;
	}

	public void ul(String fileName, File file) {
		// ul와 파일 이름, 파일 길이를 보낸다(바이트 단위)
		pw.println("ul " + fileName + " " + file.length());
		// 파일을 보낸다
		SendFile sendfile = new SendFile(os, file);

	}
	
	public void dl(String fileName, File downLoadFolder) {
		pw.println("dl " + fileName);

		String size = "0";
		try {
			size = br.readLine();

			File file = new File(downLoadFolder.getAbsolutePath() + "//" + fileName);

			// int형으로 변경해서 size를 보내준다
			DownLoadFile downLoadFile = new DownLoadFile(is,file,Long.parseLong(size));

		} catch (IOException e1) {
			// TODO Auto-generated catch block
			System.out.println("사이즈 받기 실패");
			e1.printStackTrace();
		}
	}

	public void execute() {
		System.out.println("***************");
		System.out.println("*ls: 파일 리스트 *");
		System.out.println("*ul: 파일 업로드 *");
		System.out.println("*dl: 파일 다운로드*");
		System.out.println("*quit: 연결종료 *");
		System.out.println("***************");
		
		// while 조건 달거나 하기
		while (true) {
			System.out.printf("Write command: ");
			command = scan.nextLine();

			// 파일 목록
			if (command.equals("ls")) {

				ls();

			} else if (command.startsWith("ul")) { // 업로드

				// 띄어쓰기, 즉 파일을 안 적었을 때 탈출
				if (!command.contains(" "))
					continue;

				// 파일 이름 추출
				String[] commands = command.split(" ", 2);
				String[] fileNames = commands[1].split("\\\\");
				String fileName = fileNames[fileNames.length - 1];

				// 파일을 서버에 넣을거냐 기본값은 true
				String YorN = "Yes";

				// 파일이 서버에 있을 때
				if (ls(fileName)) {
					while (true) {
						System.out.printf("파일이 이미 있습니다. 덮어쓰기 하실건가요??(Yes: 덮어쓰기 / No: 업로드 취소): ");
						YorN = scan.nextLine();
						if (YorN.equals("Yes") || YorN.equals("No")) {
							break;
						} else {
							System.out.println("Yes 또는 No 를 정확하게 입력해주세요");
						}
					}

				}

				// 파일이 존재하는지 검사하고, 존재한다면 ul를 해줌
				File file = new File(commands[1]);
				if (file.exists()) {
					if (YorN.equals("Yes")) {

						ul(fileName, file);

					}
				} else {
					System.out.println("파일이 존재하지 않습니다");
				}

			} else if (command.startsWith("dl")) {// 다운로드

				String[] commands = command.split(" ", 2);

				// 다운로드 받을 폴더, 없으면 생성, 다운로드 하기 전 동일 파일 검사
				File downLoadFolder = new File("D:\\download");
				if (!downLoadFolder.exists()) {
					try {
						downLoadFolder.mkdir();
					} catch (Exception e) {
						System.out.println("폴더 생성 실패");
					}
				}
				
				

				// 파일을 클라에 넣을거냐 기본값은 true
				String YorN = "Yes";
				String[] dlList = downLoadFolder.list();
				for (String file : dlList) {
					if (file.equals(commands[1])) {
						while (true) {
							System.out.printf("파일이 이미 있습니다. 덮어쓰기 하실건가요??(Yes: 덮어쓰기 / No: 업로드 취소): ");
							YorN = scan.nextLine();
							if (YorN.equals("Yes") || YorN.equals("No")) {
								break;
							} else {
								System.out.println("Yes 또는 No 를 정확하게 입력해주세요");
							}
						}
					}
				}
	
				// 다운로드 폴더에 이미 있는지 확인

				// ls(String) 은 파일이 있을 때 true를 리턴
				// 파일이 서버에 있을 때 dl를 요청
				if (YorN.equals("Yes")) {
					if (ls(commands[1])) {
						
						dl(commands[1],downLoadFolder);
					} else {
						System.out.println("서버에 존재하지 않는 파일입니다");
					}
				}

			} else if(command.equals("quit")) {
				pw.println("quit");
				break;
			} else {
				System.out.println("**없는 명령어입니다**");
			}
			

		}
	}

	public ClientCommand(OutputStream os, InputStream is) {
		// 스트림 생성
		this.os = os;
		this.is = is;
		// pw,br 설정
		pw = new PrintWriter(os, true);
		br = new BufferedReader(new InputStreamReader(is));

		execute();

	}

}
