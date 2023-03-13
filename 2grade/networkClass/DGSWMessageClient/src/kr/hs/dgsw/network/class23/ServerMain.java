package kr.hs.dgsw.network.class23;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ServerMain {
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(5000);
			Socket sc = ss.accept();
			// Socket객체를 반환하고, 클라이언트가 연겨로디면 
			// java.net.Socket객체 형태로 반환

			Thread ot = new Output_Thread(sc);
			ot.start();
			
			Thread it = new Input_Thread(sc);
			it.start();
			
			try {
				ot.join();
				it.join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			

			// thread로 inputStream, outputStream하기

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
