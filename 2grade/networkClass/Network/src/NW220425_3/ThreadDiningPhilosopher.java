package NW220425_3;

import java.util.concurrent.Semaphore;

public class ThreadDiningPhilosopher extends Thread{
	int id; // ö���� id
    Semaphore lstick, rstick; // ����, ������ ������
    ThreadDiningPhilosopher(int id, Semaphore lstick, Semaphore rstick) {
        this.id = id;
        this.lstick = lstick;
        this.rstick = rstick;
    }
    public void run() {
        try {
            while(true) {
                lstick.acquire(); 		// ���� ������
                rstick.acquire(); 		// ������ ������
                eating(); 				// �Ļ�
                rstick.release(); 		// ������ ��������
                lstick.release(); 		// ���� ��������
                thinking(); 			// �����ϱ�
            }
        } catch (InterruptedException e) {}
    }
    
    void eating() {
        System.out.println("[" + id + "] �Ļ� ��");
    }
    
    void thinking() {
        System.out.println("[" + id + "] ���� ��");
    }
	
}
