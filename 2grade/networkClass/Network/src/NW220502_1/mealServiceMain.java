//package NW220502_1;
//
//import java.io.BufferedReader;
//import java.io.InputStreamReader;
//import java.net.MalformedURLException;
//import java.net.URL;
//import java.text.ParseException;
//import java.text.SimpleDateFormat;
//import java.util.Calendar;
//
//public class mealServiceMain {
//	SimpleDateFormat sdf = new simpleDateFormat("yyyyMMdd");
//	Calendar cal = Calendar.getInstance();
//	
//	String newUrls = "https://open.neis.go.kr/hub/mealServiceDietInfo?"
//			+ "Type=json&"
//			+ "ATPT_OFCDC_SC_CODE=D10&"
//			+ "SD_SCHUL_CODE=7240454&"
//			+ "MLSV_YMD=" + sdf.format(cal.getTime());
//		
//	// 인터넷 접속에는 무조건 오류가 난다고 생각, 그래서 예외처리
//	try {
//		URL url = new URL(newUrls);
//		BufferedReader br = new BufferedReader(
//					new InputStreamReader(
//							url.openStream(),"utf-8"));
//		
//		JSONParser jsonParser = new JSONParser();
//		try {
//			JSONObject jsonObject = (JSONObject) jsonParser.parser(br.readLine());
//			
//			JSONArray jsonArray = (JSONArray) jsonObject.get("mealServiceDietInfo");
//			
//			JSONObject row = (JSONObject) jsonArray.get(1);
//			
//			JSONArray row_array = (JSONArray) row.get("row");
//			
//			for (int i = 0;i<row_array.size();i++) {
//				JSONObject out = (JSONObject) row_array.get(i);
//				System.out.println()
//			}
//		} catch (ParseException e) {
//			e.printStackTrace();
//		}
//				
//	} catch (MalformedURLException e){
//		e.printStackTrace();
//	}
//}


package NW220502_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

public class mealServiceMain {
   public static void main(String[] args) {
      SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
      Calendar cal = Calendar.getInstance();
      
      String newUrls = "https://open.neis.go.kr/hub/mealServiceDietInfo?\r\n"
            + "Type=json&ATPT_OFCDC_SC_CODE=D10\r\n"
            + "&SD_SCHUL_CODE=7240454\r\n"
            + "&MLSV_YMD=20220502" + sdf.format(cal.getTime());
      try {
         URL url = new URL(newUrls);
         try {
            BufferedReader br = new BufferedReader(
                  new InputStreamReader(url.openStream(),"utf-8"));
            
            JSONParser jsonparser = new JSONParser();
            try {
               JSONObject jsonobject = (JSONObject) jsonparser.parser(br.readLine());
               JSONArray jsonarray = (JSONArray) jsonobject.get("mealServiceDGSW");
               JSONObject row = (JSONObject) jsonarray.get(1);
               JSONArray row_(JSONObject) row.get("row");
               
            } catch (Exception e) {
               // TODO: handle exception
            }
            
         } catch (MalformedURLException e) {
            e.printStackTrace();
         }
      } catch (IOException e) {
         e.printStackTrace();
      }
   } 
}