// 강피셜 쉽게 해결할 수 있는 방법

package networkTask.server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class ServerMain {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			ServerSocket ssc = new ServerSocket(5000); // 명령어 주고 받기용
			
			while (true) {
				Socket scc = ssc.accept();
				
				// 다른 사람이 로그인 할 때도 계속 접속 가능해야해서 thread에서 검사해준다
				System.out.println(scc.getInetAddress()+"접속함");
				CommandThread ct = new CommandThread(scc);
//				Thread ac = new Thread(scc, scu, scd);
				// 임계구역 종료
				
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
