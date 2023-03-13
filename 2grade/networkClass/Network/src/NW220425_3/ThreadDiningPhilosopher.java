package NW220425_3;

import java.util.concurrent.Semaphore;

public class ThreadDiningPhilosopher extends Thread{
	int id; // 철학자 id
    Semaphore lstick, rstick; // 왼쪽, 오른쪽 젓가락
    ThreadDiningPhilosopher(int id, Semaphore lstick, Semaphore rstick) {
        this.id = id;
        this.lstick = lstick;
        this.rstick = rstick;
    }
    public void run() {
        try {
            while(true) {
                lstick.acquire(); 		// 왼쪽 집어들기
                rstick.acquire(); 		// 오른쪽 집어들기
                eating(); 				// 식사
                rstick.release(); 		// 오른쪽 내려놓기
                lstick.release(); 		// 왼쪽 내려놓기
                thinking(); 			// 생각하기
            }
        } catch (InterruptedException e) {}
    }
    
    void eating() {
        System.out.println("[" + id + "] 식사 중");
    }
    
    void thinking() {
        System.out.println("[" + id + "] 생각 중");
    }
	
}
