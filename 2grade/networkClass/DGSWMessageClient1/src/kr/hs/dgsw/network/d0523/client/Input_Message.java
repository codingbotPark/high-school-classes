package kr.hs.dgsw.network.d0523.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Socket;

public class Input_Message extends Thread {
	private Socket sc = null;

	// 소켓을 입력받음
	public Input_Message(Socket sc) {
		this.sc = sc;
	}

	public void run() {
		try {
			InputStream is;
			is = sc.getInputStream();
			BufferedReader br = new BufferedReader(new InputStreamReader(is));
			boolean loginboolean = true;

			while (loginboolean) {
				String brmsg = br.readLine();

				String msgType = "";
				String msgFromNick = "";
				String msgBeforeNick = "";
				String msgAfterNick = "";
				String msgJoinCount = "";
				String msgMessage = "";
				if (brmsg.equals("[Start]")) {
					brmsg = br.readLine();
					String[] brmsgarr = brmsg.split("::");
					if (brmsgarr[0].equals("Type")) {
						msgType = brmsgarr[1];
					} else {
						System.out.println("수신 메시지가 이상합니다");
						continue;
					}

					while (!(brmsg = br.readLine()).equals("[End]")) {
						brmsgarr = brmsg.split("::");
						switch (brmsgarr[0]) {
						case "FromNick":
							msgFromNick = brmsgarr[1];
							break;
						case "BeforeNick":
							msgBeforeNick = brmsgarr[1];
							break;
						case "AfterNick":
							msgAfterNick = brmsgarr[1];
							break;
						case "JoinCount":
							msgJoinCount = brmsgarr[1];
							break;

						case "Message":
							msgMessage = "";
							while (!(brmsg = br.readLine()).equals("::Message")) {
								msgMessage += brmsg + "\r\n";
							}
							msgMessage = msgMessage.substring(0, msgMessage.length() - 2);
							break;
						default:
							break;
						}
					}

					switch (msgType) {
					case "LogIn":
						System.out.println("[" + msgFromNick + "] 접속하였습니다.");
						break;
					case "LogOutOK":
						System.out.println("로그아웃하였습니다.");
						loginboolean = false;
						break;
					case "LogOut":
						System.out.println("[" + msgFromNick + "] 사용자가 로그아웃하였습니다.");
						break;
					case "NickNameOK":
						System.out.println("닉네임을 [" + msgAfterNick + "]로 변경하였습니다.");
						break;
					case "NickNameOverlap":
						System.out.println("닉네임을 [" + msgAfterNick + "]는 이미 사용중입니다.");
						break;
					case "NickNameInform":
						System.out.println("[" + msgBeforeNick + "] 사용자가 닉네임을 [" + msgAfterNick + "]로 변경하였습니다.");
						break;
					case "Whisper":
						System.out.println("[귓속말] " + msgFromNick + ": " + msgMessage);
						break;
					case "WhisperOK":
						System.out.println("[귓속말] 전송 성공");
						break;
					case "WhisperWhithout":
						System.out.println("[귓속말] 전송 실패 / 닉네임이 없습니다.");
						break;
					case "AllMessage":
						System.out.println(msgFromNick + ": " + msgMessage);
						break;
					case "NickList":
						System.out.println("접속자수: " + msgJoinCount);
						System.out.println("[접속자리스트]");
						System.out.println(msgMessage);
						System.out.println("[접속자리스트끝]");
						break;
					default:
						break;
					}
				}
			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println("연결 종료");
			e.printStackTrace();
		}

	}

}
