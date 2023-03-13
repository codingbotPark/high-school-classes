package NW220425_1;

public class ThreadMaker extends Thread{
	// 다른 class에 있어서 객체로 만들어 준다
	private CakePlate cake;
	// 이를 통해 cake에 있는 makeBread라는 함수를 사용할 수 있다
	
	public ThreadMaker(CakePlate cake) {
		this.cake = cake;
	}
	
		// 기본적으로 생성자 쓰레드에는 run을 넣어준다
	public void run() {
		for (int i =0;i<50;i++) {
			 cake.makeBread();
		}
	}
}
