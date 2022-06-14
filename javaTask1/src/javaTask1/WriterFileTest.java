package javaTask1;

import java.io.File;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.stream.Stream;

// id 랑 번호, id 랑 이름을 해서 번호, 이름은 각각 정렬되어서 나오게 된다

// 인자로 보낸 파일, 라인 으로 선택된 라인을 enter로 띄어주는 class만들기(ㅑ) 


public class WriterFileTest {
	
	public static void main(String[] args) {
		
		// 파일
		File file = new File("C:\\Users\\DGSW\\Desktop\\writeingTest.txt");

		Path path = Paths.get("C:\\Users\\DGSW\\Desktop\\writeingTest.txt");
		
		try {
			
			// 파일 Stream
			Stream<String> stream = Files.lines(path);
			// 2줄 넘겨서, 3번째 라인을 찾게된다
			String nthLine = stream.skip(2).findFirst().get();
			System.out.println(nthLine);
			
			long lineCount = Files.lines(path).count();
			System.out.println(lineCount);
			
			
		} catch (Exception e) {
			System.out.println("main에서 오류");
			// TODO: handle exception
		}
	}

	
	//	public static void main(String[] args) {
//		
//		try {
//			File file = new File("C:\\Users\\DGSW\\Desktop\\writeingTest.txt");
//			
//			if (!file.exists()) {
//				file.createNewFile();
//			}
//			
//			FileWriter fw = new FileWriter(file,true);
//			BufferedWriter writer = new BufferedWriter(fw);
//			
//			writer.write("덮어쓰기 ㄱㄴ?");
//			
//			fw.flush();
//			writer.close();
//		} catch (IOException e) {
//			// TODO: handle exception
//			System.out.println("실패");
//		}
//		
//	}
	
	
}

