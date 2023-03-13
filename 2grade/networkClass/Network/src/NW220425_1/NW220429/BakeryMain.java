package NW220429;

// 빵집, 은행원 알고리즘 이라 불리는 알고리즘의 이유는
// 은행에서 여러 명의 사람을 번호표를 통해 먼저온 대로
// 처리하기 때문이다

public class BakeryMain {
	public static void main(String[] args) {

		// 초기화
		for (int i = 0; i < ThreadBakery.numberOfThreads; i++) {
			ThreadBakery.choosing[i] = false;
			ThreadBakery.ticket[i] = 0;
		}

		ThreadBakery[] threads = new ThreadBakery[ThreadBakery.numberOfThreads];

		for (int i = 0; i < threads.length; i++) {
			// threads배열에 ThreadBacker(i) 로 생성
			threads[i] = new ThreadBakery(i);
			threads[i].start();
		}

		for (int i = 0; i < threads.length; i++) {
			try {
				// 쓰레드가 종료되기를 기다린다
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
