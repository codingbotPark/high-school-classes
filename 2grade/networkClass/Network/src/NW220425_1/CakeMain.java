package NW220425_1;

// 다시 설명을 적으면
// CakePlate라는 크레스에 뺭 만들기, 빵 먹기 함수가 있고,
// 그 함수를 각각 ThreadMaker, ThreadEater에서 사용
// 이 ThreadMaker와 ThreadEater를 

public class CakeMain {
	public static void main(String[] args) {
		// CakePlate를 main에서 선언해서 넣음
		CakePlate cake = new CakePlate();
		ThreadEater eater = new ThreadEater(cake);
		ThreadMaker baker = new ThreadMaker(cake);
		
		baker.start();
		eater.start();
	}
}
