package network;

import java.io.IOException;
import java.io.InputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.net.Socket;

public class ObjectClient {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 5000);
			
			OutputStream os = socket.getOutputStream();
			InputStream is = socket.getInputStream();
			

			ObjectOutputStream oos = new ObjectOutputStream(os);
			ObjectInputStream ois = new ObjectInputStream(is);
	         
			MyMember member = new MyMember();
			member.setId("admin");
			member.setPwd("1234");

			oos.writeObject(member);
			
			String message;
			message = (String) ois.readObject();
			System.out.println(message);

		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
}