package kr.hs.dgsw.java.dept23.d0526;

public class Sprint100 {
	public static class Athlete implements Runnable{
		private final String name;
		
		private final double record;

		public Athlete(String name, double record)
		{
		// TODO Auto-generated constructor st1ub
			this.name = name;
			this.record = record;
		}
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			int times = 0;
			double distance = 0;
			while(true) {
				distance = times * (100 / record);
				System.out.printf("%s선수가 %d초 동안 %.2fm를 달렸습니다\n",
						name,times,distance);
				
				if (distance >= 100) {
					break;
				}
				
				times++;

				
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

	}
	
	
	public void playGame() {
		Athlete bolt = new Athlete("우산인볼트", 9.58);
		Athlete bolkimd = new Athlete("김국영", 10.07);
		Athlete ji = new Athlete("지건", 12.56);
		Athlete student = new Athlete("고딩", 14.02);
		
		new Thread(bolt).start();
		new Thread(bolkimd).start();
		new Thread(ji).start();
		new Thread(student).start();
		
	}
	
	public static void main(String[] args) {
		Sprint100 game = new Sprint100();
		game.playGame();
	}
}
