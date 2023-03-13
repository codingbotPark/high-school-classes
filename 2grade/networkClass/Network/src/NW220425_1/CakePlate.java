package NW220425_1;

// 하나는 자원을 생산하고, 하나는 자원을 소비
// 모니터를 활용한 동기화
// 하나의 프로세스 내의 다른 스레드 간의 동기화를 사용

// wait = 호출한 쓰레드를 조건 동기 큐에 삽입
// notify = 조건 동기 큐에 있는 하나의 쓰레드 깨우기
// notifyAll = 조건 동기 큐에 있는 모든 쓰레드 깨우기

public class CakePlate {
	// 사용할 공용 변수
	private int breadCount = 0;
	public CakePlate() {}
	
	// synchronized로 임계구역을 만들어서 하나의 쓰레드만 들어갈 수 있도록 한다
	// 공용으로 사용하는 변수를 건들기 때문에 임계구역을 설정한다
	public synchronized void makeBread() {
		if (breadCount >= 10) {
			try {
				System.out.println("빵이 남는다");
				wait();
				// 빵을 다 만들었을 때 cpu에서 내려와야 하기 때문에
				// InterruptedException을 해서 예외처리를 해준다
			} catch (InterruptedException ire) {}
		}
		breadCount++;
		System.out.println("빵을 1개 더 만듦 총 : " + breadCount + "개");
		// 빵을 다 만들었을 때 소비자보고 일어나라고 notifyAll을 해준다
		this.notifyAll();
	}
	
	public synchronized void eatBread() {
		if (breadCount < 1) {
			try {
				System.out.println("빵이 없어요");
				wait();
				// 위에서와 같이 cpu에서 아무것도 하지 않을 때 오류를 예외처리
			} catch (InterruptedException ire) {}
			
		}
		breadCount--;
		System.out.println("방 1개를 먹음 : "+breadCount+"개");
		this.notifyAll();
	}
}
