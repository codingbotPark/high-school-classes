package kr.hs.dgsw.java.dept23.d0602;

public class Account {
	private final String name;
	// 계좌주
	
	private int balance;
	// 잔액
	
	public Account(String name) {
		this.name = name;
		this.balance = 0;
	}
	
	public String getName() {
		return name;
	}
	
	public int getBalance() {
		return balance;
	}
	
	public void setBalance(int balance) {
		this.balance = balance;
	}
	
	
}
