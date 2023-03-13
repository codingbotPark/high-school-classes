package kr.hs.dgsw.java.dept23.d0421;

import java.util.Calendar;
import java.util.Date;

public class MyDate extends Date{
//	 public static void main(String[] args) {
//		 Date date = new Date();
//		 System.out.println(date);
//		 
//		 MyDate date1 = new MyDate();
//		 System.out.println(date1);
//	 }
	
	public int getYear1() {
		Calendar calendar = Calendar.getInstance();
		calendar.setTimeInMillis(getTime());
		
		return calendar.get(Calendar.YEAR);
	}
	
}
