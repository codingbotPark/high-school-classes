package kr.hs.dgsw.java.task1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;

public class ApplyToFile {
	File file;
	
	
	public void apply(ArrayList<String> contents) {
		try {
			FileOutputStream output = new FileOutputStream(file,false);
			OutputStreamWriter writer = new OutputStreamWriter(output,"UTF-8");
			BufferedWriter out = new BufferedWriter(writer);
			
			for(String content:contents) {
//				System.out.println(content);
				out.write(content+"\n");
			}
			
			out.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public ApplyToFile(File file) {
		// TODO Auto-generated constructor stub
		this.file = file;
	}
}
