package kr.hs.dgsw.network.d0523.server;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ClientThread extends Thread {
	private static List<ClientThread> ClientList = (List<ClientThread>) Collections
			.synchronizedList(new ArrayList<ClientThread>());

	private ClientAccept ca = null;
	private String nickname = null;

	public ClientThread(String nickname, ClientAccept ca) {
		this.ca = ca;
		this.nickname = nickname;
		ClientList.add(this);
//		notMeMessage("[Start]\r\n" + "Type::LogIn\r\n" + "FromNick::"+nickname+"\r\n" + "[End]");
	}

	public boolean containsNickname(String nickname) {
		for (ClientThread cttmp : ClientList) {
			if (cttmp.nickname.equals(nickname)) {
				return true;
			}
		}
		return false;
	}

	public void sendMessage(String msg) {
		ca.sendMessage(msg);
	}

	// 전체에게 메시지 발송
	public void allMessage(String msg) {
		for (ClientThread cttmp : ClientList) {
			cttmp.sendMessage(msg);
		}
	}

	// 특정 사람에게 발송하기
	public void message(String msg, String toNick) {
		for (ClientThread cttmp : ClientList) {
			if (cttmp.nickname.equals(toNick))
				cttmp.sendMessage(msg);
		}
	}

	// 나를 제외한 모두에게 발송
	public void notMeMessage(String msg) {
		for (ClientThread cttmp : ClientList) {
			if (cttmp != this)
				cttmp.sendMessage(msg);
		}
	}

	public void run() {
		try {
			boolean loginboolean = true;
			while(loginboolean) {
				String brmsg = ca.readMessage();
					
				String msgType = "";
				String msgNickName = "";
				String msgToNick = "";
				String msgMessage = "";
					
				if(brmsg.equals("[Start]")) {
					brmsg = ca.readMessage();
					String[] brmsgarr = brmsg.split("::");
					if (brmsgarr[0].equals("Type")) {
						msgType = brmsgarr[1];
					} else {
						System.out.println(this.nickname + ": 발송 메시지가 이상합니다");
						continue;
					}
						
					while(!(brmsg = ca.readMessage()).equals("[End]")) {
						brmsgarr = brmsg.split("::");
						switch(brmsgarr[0]) {
						case "NickName":
							msgNickName = brmsgarr[1];
							break;
						case "ToNick":
							msgToNick = brmsgarr[1];
							break;
						case "Message":
							msgMessage = "";
							while(!(brmsg = ca.readMessage()).equals("::Message")) {
								msgMessage += brmsg + "\r\n";
							}
							msgMessage.substring(0,msgMessage.length()-2);
							break;
						default:
							break;
						}
					}
					switch (msgType) {
						case "Login":
							allMessage("[Start]\r\n" + "FromNick::" + this.nickname + "\r\n" + "[End]");
							break;
						case "LogOut":
							ClientList.remove(this);
							loginboolean = false;
							notMeMessage("[start]\r\n" + "FromNick::" + this.nickname + "\r\n" + "[End]");
							sendMessage("[start]\r\n" + "Type::LoginOutOk\r\n" + "[End]");
							break;
						case "NickName":
							if (!containsNickname(msgNickName)) {
								// 중복 안 되면
								// 관련 메시지 발송
								notMeMessage("[Start]\r\n" + "Type::NickNameInform\r\n" + "BeforNick::" + this.nickname + "\r\n" + "AfterNick::" + msgNickName + "\r\n" + "[End]");
								sendMessage("[Start]\r\n" + "Type::NickNameOKK\r\n" + "BeforNick::" + this.nickname + "\r\n" + "AfterNick::" + msgNickName + "\r\n" + "[End]");
								
								this.nickname = msgNickName;
							} else {
								sendMessage("[Start]\r\n" + "Type::NickNameOverlap\r\n" + "[End]");	
							}
							break;
						case "Whisper":
							if (containsNickname(msgToNick)) {
								message("[Start]\r\n" + "Type::Whisper\r\n" + "FromNick::"+ this.nickname +"\r\n" + "Message::\r\n" + msgMessage + "::Message\r\n" + "[End]", msgToNick);
								sendMessage("[Start]\r\n" + "Type::WhisperOK\r\n" + "[End]");
							} else {
								sendMessage("[Start]\r\n" + "Type::WhisperWhithout\r\n" + "[End]");
							}
							break;
						case "AllMessage":
							notMeMessage("[Start]\r\n" + "Type::AllMessage\r\n" + "FromNick::"+ this.nickname +"\r\n" + "Message::\r\n" + msgMessage + "::Message\r\n" + "[End]");
							break;
						case "NickList":
							String tmpmsg="[Start]\r\n"
									+ "Type::NickList\r\n"
									+ "JoinCount::" + ClientList.size() + "\r\n"
									+ "Message::\r\n";
							for(ClientThread tmpcl:ClientList) {
								tmpmsg += tmpcl.nickname +"\r\n";
							}
							tmpmsg += "::Message\r\n"
									+ "[End]";
							sendMessage(tmpmsg);
							break;
					}
				}
			}
		} catch (IOException e) {
			//TODO Auto-generated catch block
			System.out.println("연결 종료");
			e.printStackTrace();
		}
	}
}
