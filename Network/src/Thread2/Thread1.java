package Thread2;

public class Thread1 implements Runnable{
	public String name;
	
	public Thread1(String name) {
		this.name = name;
	}
	
	public void run() {
		for (int i=0;i<500;i++) {
//			System.out.prinln("T1 Thread")
		}
		System.out.println("T%s Thread End");
	}
}
