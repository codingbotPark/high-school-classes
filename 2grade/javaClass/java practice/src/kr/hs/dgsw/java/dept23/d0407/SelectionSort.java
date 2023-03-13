package kr.hs.dgsw.java.dept23.d0407;
import java.util.Scanner;

public class SelectionSort {
	private Scanner scanner;
	public void prepareScanner() {
		this.scanner = new Scanner(System.in);
	}
	public void closeScanner() {
		this.scanner.close();
	}
	public Scanner getScanner() {
		return this.scanner;
	}
	
	
//	public void bubbleSort(int[] nums) {
//		for (int i = 0;i<nums.length-1;i++) {
//			for (int j = 0;j<nums.length-1;j++) {
//				if (nums[j] > nums[j+1]) {
//					int temp = nums[j];
//					nums[j] = nums[j+1];
//					nums[j+1] = temp;
//				}
//			}
//		}
//		
//		for (int i = 0;i<nums.length;i++) {
//			System.out.printf("%d ",nums[i]);
//		}
//	}
	public void selectionSort(int[] nums) {
		for (int i = 0;i<nums.length-1;i++) {
			int small = i;
			for (int j = i+1;j<nums.length;j++) {
				if (nums[small] > nums[j]) {
					small = j;
				}
			}
			int temp = nums[i];
			nums[i] = nums[small];
			nums[small] = temp;
			System.out.printf("%d ",nums[i]);
		}
		System.out.printf("%d ",nums[nums.length-1]);
	}
	
	public void sort() {
		int[] numbers1 =  new int[5];
		System.out.println("5개의 수를 입력하세요");
		for (int i = 0;i<5;i++) {
			numbers1[i] = scanner.nextInt();
		}
//		bubbleSort(numbers1);
		selectionSort(numbers1);
	}
	
	public static void main(String[] args) {
		SelectionSort task1 = new SelectionSort();
		task1.prepareScanner();
		
		task1.sort();
		
		task1.closeScanner();
	}
}
