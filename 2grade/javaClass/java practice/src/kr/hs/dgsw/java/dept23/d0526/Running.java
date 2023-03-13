package kr.hs.dgsw.java.dept23.d0526;

public class Running implements Runnable{
	
	private final double second;
	private final String name;
	
	public Running(double second,String name) {
		// TODO Auto-generated constructor stub
		this.second = second;
		this.name = name;
	}
	
	// 100 중 1초에 가는 길이
	public long M100perS() {
		return Math.round(100 / this.second); 
	}

	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0;i*this.M100perS()<100;i++) {
			System.out.printf("%s가 %d초에 %d만큼 이동했습니다\n",this.name,i,this.M100perS() * i);
			
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.printf("%s가 도착했습니다\n",this.name);
	}
	
	public static void main(String[] args) {
		Running UB= new Running(9.58,"우사인볼트");
		Running JG = new Running(12.56,"박지건");
		
//		Thread nadalThread = new Thread(nadal);
//		nadalThread.start();
//		
		new Thread(UB).start();
		new Thread(JG).start();
	}
}
