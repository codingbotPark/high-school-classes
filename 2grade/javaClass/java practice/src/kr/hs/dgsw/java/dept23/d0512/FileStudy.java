package kr.hs.dgsw.java.dept23.d0512;

import java.io.File;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class FileStudy {
	// 예외가 발생할 때 이를 호출한 곳으로 떠넘기겠다!
	public void studyFileDate() throws Exception {
		// 기본 생성자가 없고, 문자열을 줘야한다
		// 가자 기본 사용은 절대 경로를 준다
		File file = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\sample.txt");
		// 파일은 독립적이 아닌 파일 시스템 안에 있다
		
		// 자바의 장점은 모든 os에서 돌릴 수 있는 것인데
		// 경로를 \ 로 구분하는 것은 window이다
		// 자바에서 알아서 바꿔주지만 그냥 / 를 하는게 가장 기본이다
		
		File file2 = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\none.txt");
		File file3 = new File("C:/Users/DGSW/Desktop/java/fileStudy");
		// 파일이 물리적으로 존재 여부
				
		System.out.println("파일의 물리적 존재 여부");
		System.out.println(file.getName() + " " + file.exists());
		System.out.println(file2.getName() + " " + file2.exists());
		System.out.println(file3.getName() + " " + file3.exists());
		System.out.println();
		
		// 파일인지 디렉토리인지 판단하기
		// 파일이면서 디렉토리인 경우가 있을까?
		// 없다면 java를만든 사람이 file에 isFile(), isDirectory()를 만들었을 이유가 없다

		boolean bFile = file.isFile();
		boolean bDir = file.isDirectory();
		
		System.out.println("파일의 물리적 존재 여부");
		System.out.println(file.getName() + " " + bFile + " " + bDir);
		System.out.println(file2.getName() + " " + file2.isFile() + " " + file2.isDirectory());
		System.out.println(file3.getName() + " " + file3.isFile() + " " + file3.isDirectory());
		System.out.println();
		
		
		// 파일의 경로 알아내기
		File file4 = new File("./hello.jpg");
		String path = file4.getPath();
		System.out.println("파일의 경로");
		System.out.println("getPath() : "+path);
		// 그냥 상대경로가 나온다
		
		// 아래처럼 해서 절대경로를 할 수 이/ㅅ다
		String absolutePath = file4.getAbsolutePath();
		System.out.println("getAbsolutePath() : "+absolutePath);
		
		// 우리가 일반적으로 쓰는 절대경로로 바꿔준다
		String canonicalPath = file.getCanonicalPath();
		System.out.println("canonicalPath() : "+canonicalPath);
		
		// 파일의 크기
		// 파일의 크기는 운영체제의 api를 사용하는 것이라서
		// 운영체제에 따라 다른 결과가 나올 수 있다
		long size = file.length();
		System.out.println("파일의 크기");
		System.out.println(file.getName() + " "+size);
		System.out.println(file2.getName()+" " +file2.length());
		System.out.println(file3.getName() + " "+file3.length());
		System.out.println();
		
		// 파일의 수정된 시간
		long time = file.lastModified();
		System.out.println(time);
		System.out.println("수정된 시각");
		System.out.println(file.getName() + " " + time);
		System.out.println(file.getName() + " " + convertToDate(time));
		System.out.println(file.getName() + " " + formatDate(convertToDate(time)));
		System.out.println();
		
	};
	
	public Date convertToDate(long unixTime) {
		return new Date(unixTime);
	}
	
	public String formatDate(Date date) {
		SimpleDateFormat dateFormat = 
				new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		return dateFormat.format(date);
	}
	
	
	public void studyManage() throws Exception{
		File file = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\hello.txt");
		
		// 파일 생성
		boolean created = file.createNewFile();
		// 하드디스크에 파일을 만들 때 예외가 발생할 수 있다
		System.out.println("파일 생성");
		System.out.println(file.getName() + " " + created);
		System.out.println();
		
		// 파일 삭제
		boolean deleted = file.delete();
		System.out.println("파일 삭제");
		System.out.println(file.getName() + " " + deleted);
		System.out.println();
		
		File dir = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\subDir");
		// 위는 줄기세포와 같이 파일이 될 수도, 폴더가 될 수도 있다
		// 디렉토리 생성
		created = dir.mkdir();
		System.out.println("디렉토리 생성");
		System.out.println(dir.getName() + " " + created);
		System.out.println();
		
		// 디렉토리 삭제
		// 삭제할 때는 파일이나, 디렉토리나 둘 다 delete이다
		// 디렉토리가 비어있을 때 삭제가 된다
		deleted = dir.delete();
		System.out.println("디렉토리 삭제");
		System.out.println(dir.getName() + " " + created);
		System.out.println();
		
		
		// 파일 이름 바꾸기
		File original = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\sample.txt");
		File target = new File("C:\\Users\\DGSW\\Desktop\\java-2학년\\fileStudy\\진달래꽃.txt");
		original.renameTo(target);
		// 이름변경과 파일이동이 된다
	}
	
	
	public void studyList() {
		// 이 방법을 사용하면 파일들을 스트링 타입으로 리턴
		File dir = new File("C:/");
		
		String[] list = dir.list();
		for (String name : list) {
			System.out.println(name);
		}
		
		// listFiles는 속해있는 파일들을 파일 타입으로 리턴
		// 그래서 파일을 실제로 만들거나 할 대 더 편할 수 있다
		File[] listFiles = dir.listFiles();
		for (File file : listFiles) {
			 System.out.println(file.getAbsolutePath());
		}
	}
	

	
	public static void main(String[] args)throws Exception  {
		FileStudy fileStudy = new FileStudy();
		fileStudy.studyFileDate();
//		fileStudy.studyManage();
//		fileStudy.studyList();
//		fileStudy.test();
	} 
	
	
	
}
