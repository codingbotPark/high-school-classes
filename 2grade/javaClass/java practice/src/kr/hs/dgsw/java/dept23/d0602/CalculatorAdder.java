package kr.hs.dgsw.java.dept23.d0602;

public class CalculatorAdder implements Runnable{

	private final CalculatorMain buffer;
	
	public CalculatorAdder(CalculatorMain buffer) {
		// TODO Auto-generated constructor stub
		this.buffer = buffer;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true) {
			synchronized (buffer) {
				try {
					buffer.wait();
					int value1 = buffer.get();
					int value2 = buffer.get();
					System.out.printf("%d더하기 %d는 %d\n",value1,value2,value1+value2);
					
				} catch (InterruptedException e) {
					// TODO: handle exception
					e.printStackTrace();
				}
			}
		}
	}


}
