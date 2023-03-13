package NW220425_1;

// �ϳ��� �ڿ��� �����ϰ�, �ϳ��� �ڿ��� �Һ�
// ����͸� Ȱ���� ����ȭ
// �ϳ��� ���μ��� ���� �ٸ� ������ ���� ����ȭ�� ���

// wait = ȣ���� �����带 ���� ���� ť�� ����
// notify = ���� ���� ť�� �ִ� �ϳ��� ������ �����
// notifyAll = ���� ���� ť�� �ִ� ��� ������ �����

public class CakePlate {
	// ����� ���� ����
	private int breadCount = 0;
	public CakePlate() {}
	
	// synchronized�� �Ӱ豸���� ���� �ϳ��� �����常 �� �� �ֵ��� �Ѵ�
	// �������� ����ϴ� ������ �ǵ�� ������ �Ӱ豸���� �����Ѵ�
	public synchronized void makeBread() {
		if (breadCount >= 10) {
			try {
				System.out.println("���� ���´�");
				wait();
				// ���� �� ������� �� cpu���� �����;� �ϱ� ������
				// InterruptedException�� �ؼ� ����ó���� ���ش�
			} catch (InterruptedException ire) {}
		}
		breadCount++;
		System.out.println("���� 1�� �� ���� �� : " + breadCount + "��");
		// ���� �� ������� �� �Һ��ں��� �Ͼ��� notifyAll�� ���ش�
		this.notifyAll();
	}
	
	public synchronized void eatBread() {
		if (breadCount < 1) {
			try {
				System.out.println("���� �����");
				wait();
				// �������� ���� cpu���� �ƹ��͵� ���� ���� �� ������ ����ó��
			} catch (InterruptedException ire) {}
			
		}
		breadCount--;
		System.out.println("�� 1���� ���� : "+breadCount+"��");
		this.notifyAll();
	}
}
