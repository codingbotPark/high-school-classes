package kr.hs.dgsw.network.d0523.server;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ClientThread extends Thread{ 
	private static List<ClientThread> ClientList = (List<ClientThread>) Collections.synchronizedList(new ArrayList<ClientThread>());
	
	private ClientAccept ca = null;
	private String nickname = null;
	
	public ClientThread(String nickname, ClientAccept ca) {
		this.ca = ca;
		this.nickname = nickname;
		ClientList.add(this);
//		notMeMessage("[Start]\r\n" + "Type::LogIn\r\n" + "FromNick::"+nickname+"\r\n" + "[End]");
	}
	
	public boolean containsNickname(String nickname) {
		for (ClientThread cttmp:ClientList) {
			if(cttmp.nickname.equals(nickname)) {
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
		for (ClientThread cttmp:ClientList) {
			cttmp.sendMessage(msg);
		}
	}
	
	// 특정 사람에게 발송하기
	public void message(String msg,String toNick) {
		for (ClientThread cttmp:ClientList) {
			if (cttmp.nickname.equals(toNick))
				cttmp.sendMessage(msg);
		}
	}
	
	
	public void notMeMessage(String msg) {
		for (ClientThread cttmp:ClientList) {
			if (cttmp != this)
				cttmp.sendMessage(msg);
		}
	}
	
	public void run() {
		boolean loginboolean = true;
		while (loginboolean) {
			String brmsg = ca.readMessage();
			
			String msgType = "";
		}
	}
	
}
