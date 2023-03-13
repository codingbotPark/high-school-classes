package network;

import java.io.*;
import java.net.*;

public class ObjectServer {
	public static void main(String[] args) {
		try {
			ServerSocket serverSocket = new ServerSocket(5000);

			Socket ss = serverSocket.accept();
	
			InputStream is = ss.getInputStream();
			OutputStream os = ss.getOutputStream();
	
			ObjectInputStream ois = new ObjectInputStream(is);
			ObjectOutputStream oos = new ObjectOutputStream(os);
	
			MyMember member = (MyMember)ois.readObject();

			
			System.out.println(member.getId() + " " + member.getPwd());
			
			oos.writeObject("[" + member.getId() + "]님 로그인 성공");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}