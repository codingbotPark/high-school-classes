package NW220425_1;

// �ٽ� ������ ������
// CakePlate��� ũ������ �� �����, �� �Ա� �Լ��� �ְ�,
// �� �Լ��� ���� ThreadMaker, ThreadEater���� ���
// �� ThreadMaker�� ThreadEater�� 

public class CakeMain {
	public static void main(String[] args) {
		// CakePlate�� main���� �����ؼ� ����
		CakePlate cake = new CakePlate();
		ThreadEater eater = new ThreadEater(cake);
		ThreadMaker baker = new ThreadMaker(cake);
		
		baker.start();
		eater.start();
	}
}
