package NW220425_1;

public class ThreadMaker extends Thread{
	// �ٸ� class�� �־ ��ü�� ����� �ش�
	private CakePlate cake;
	// �̸� ���� cake�� �ִ� makeBread��� �Լ��� ����� �� �ִ�
	
	public ThreadMaker(CakePlate cake) {
		this.cake = cake;
	}
	
		// �⺻������ ������ �����忡�� run�� �־��ش�
	public void run() {
		for (int i =0;i<50;i++) {
			 cake.makeBread();
		}
	}
}
