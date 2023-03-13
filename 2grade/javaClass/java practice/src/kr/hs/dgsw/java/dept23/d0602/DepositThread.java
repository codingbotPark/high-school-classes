package kr.hs.dgsw.java.dept23.d0602;

public class DepositThread implements Runnable{
	
	private final Bank bank;
	private final int amount;
	
	public DepositThread(Bank bank, int amount) {
		this.bank = bank;
		this.amount = amount;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		
		// 은행에 돈을 넣는다(이름 이라는 사람의 계좌에)
		System.out.printf("%s계좌에 %d원을 적립합니다\n","이름",amount);
		bank.deposit("이름", amount);
		
	}
}
