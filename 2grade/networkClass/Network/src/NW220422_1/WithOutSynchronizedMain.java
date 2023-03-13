package NW220422_1;

public class WithOutSynchronizedMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyRun_WithOutSynchronized mr1=new MyRun_WithOutSynchronized();
		Thread t1=new Thread(mr1, "t1");
		Thread t2=new Thread(mr1, "t2");
		Thread t3=new Thread(mr1, "t3");
		
		t1.start();
		t2.start();
		t3.start();
	}

}
