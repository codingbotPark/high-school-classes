package NW220429;

// ����, ����� �˰��� �̶� �Ҹ��� �˰����� ������
// ���࿡�� ���� ���� ����� ��ȣǥ�� ���� ������ ���
// ó���ϱ� �����̴�

public class BakeryMain {
	public static void main(String[] args) {

		// �ʱ�ȭ
		for (int i = 0; i < ThreadBakery.numberOfThreads; i++) {
			ThreadBakery.choosing[i] = false;
			ThreadBakery.ticket[i] = 0;
		}

		ThreadBakery[] threads = new ThreadBakery[ThreadBakery.numberOfThreads];

		for (int i = 0; i < threads.length; i++) {
			// threads�迭�� ThreadBacker(i) �� ����
			threads[i] = new ThreadBakery(i);
			threads[i].start();
		}

		for (int i = 0; i < threads.length; i++) {
			try {
				// �����尡 ����Ǳ⸦ ��ٸ���
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
