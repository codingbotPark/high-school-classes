package networkTask.client;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.file.Files;

public class SendFile {

	OutputStream cos;
	BufferedOutputStream bos;
	DataOutputStream dos;

	File file;
	FileInputStream fis;

	public void send() {
		byte[] bytes = new byte[1024];
		int readbit = 0;
		try {

			while (true) {
				readbit = fis.read(bytes);
				if (readbit == -1) {
					dos.flush();
					break;
				}
				dos.write(bytes, 0, readbit);

			}

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public SendFile(OutputStream cos, File file) {
		// TODO Auto-generated constructor stub
		this.cos = cos;
		this.bos = new BufferedOutputStream(cos);
		this.dos = new DataOutputStream(bos);
		this.file = file;
		try {
			this.fis = new FileInputStream(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		this.file = file;
		send();
	}
}
