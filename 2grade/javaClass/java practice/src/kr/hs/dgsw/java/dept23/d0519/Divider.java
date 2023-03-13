package kr.hs.dgsw.java.dept23.d0519;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Divider {
	private final Scanner scanner;

	public Divider() {
		this.scanner = new Scanner(System.in);
	}

	private int calculate(int value1, int value2) {
		return value1 / value2;
	}

	public void execute() {
		try {
			System.out.println("두 정수를 입력하세요");

			// 사용자가 잘못된 수를 입력했을 때를 위해
			// try catch로 예외처리를 해준다
			int value1 = scanner.nextInt();
			int value2 = scanner.nextInt();

			int result = calculate(value1, value2);
			System.out.printf("%d / %d = %d\n", value1, value2, result);

			boolean saved = saveResult("C:\\Users\\DGSW\\Desktop\\divide.txt", value1, value2, result);
			System.out.println("파일 저장 결과 : "+saved);


			System.out.println("프로그램을 종료합니다");

			// 예외의 종류가 e 에 들어있다
		} catch (InputMismatchException e) {
			System.out.println("숫자만 입력할 수 있습니다");
		} catch (ArithmeticException e) {
			System.out.println("0으로 나눌 수 없습니다");
		} finally {
			// finally에서 close를 해주면 
			// 이 프로그램이 정상적이건, 비 정상적이건 close를 해준다
			scanner.close();
		}

		// 아래처럼 catch에서 if 문으로 예외를 알려줄 수 있고
		// 위처럼 여러 개의 catch를 사용하여 알려줄 수 있다
//		catch (Exception e) {
//			
//			// TODO: handle exception
//			System.out.println("예외발생");
//			
//			if (e instanceof InputMismatchException) {
//				System.out.println("숫자만 입력할 수 있습니다");
//			} else if (e instanceof ArithmeticException) {
//				System.out.println("0으로 나눌 수 없습니다");
//			}
//		}
//			
	}

	// 내 코드
//	public void saveResult(String path, int value1, int value2, int result) {
//		
//		try {
//			FileOutputStream output = new FileOutputStream(path);
//			output.write((value1 + " 나누기 " + value2 + " 은 " + result).getBytes());
//
//		} catch (FileNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		
//	}

	private boolean saveResult(String filePath, int value1, int value2, int result) {
		String str = String.format("%d / %d = %d\n", value1, value2, result);

		
		OutputStream os = null;
		try {
			File file = new File(filePath);
			os = new FileOutputStream(file);
			os.write(str.getBytes());
			return true;
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			
			// finally 는 return을 수행하기 전 실행된다
			//그래서 정상적으로 작동했을 때 자원을 해제하고 return true가 된다
			
			System.out.println("자원을 해제");
			if (os != null) {
				try {
					os.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

		return false;
	}

	public static void main(String[] args) {
		new Divider().execute();
	}
}
