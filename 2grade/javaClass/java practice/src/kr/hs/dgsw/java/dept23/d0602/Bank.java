package kr.hs.dgsw.java.dept23.d0602;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Bank {

	// 이름을 key로 하고, 계좌를 값으로하는 map
	private final Map<String, Account> accountMap = new HashMap<String, Account>();
	// 말그대로 hashing을 사용하여 많은 데이터를 다룰 때 좋다
	
	// 계좌개설
	public void makeAccount(String name) {
		Account account = new Account(name);
		accountMap.put(name, account);
	}

	// synchronized를 하면 동기화가 된다
	// 동기화가 되면 실행되는 도중 제어권을 뺏앗기지 않는다
	// name을 가진 계좌에 amount만큼 돈을 추가하는 메소드
	public void deposit(String name, int amount) {
		// 주어진 사람의 계좌를 가져온다
		Account account = accountMap.get(name);
		
		// synchronized는 임계구역이다
		// account라는 자원을 사용하는 것을 동기화를 시켜준다
		synchronized (account) {
			// 개좌를 가져왔다면 잔액을 가져와서 추가 후 다시 넣으면 된다
			if (account != null) {
				int balance = account.getBalance();
				//은행 시스템에서 시간이 걸린다고 가정
				try {
					Thread.sleep(new Random().nextInt(1000));
				} catch (InterruptedException e) {
					// TODO: handle exception
					e.printStackTrace();
				}
				int newBalance = balance + amount;
				account.setBalance(newBalance);
				
			}
		}	
		
		// 위처럼 하나의 자원을 여러 개의 쓰레드가 공유할 때는 문제가 되지 않지만
		// 두 개의 자원을 사용할 때는?
		// 스레드 A가 A,B자원을 사용할 때 A자원을 가지고 B자원을 기다리고 있고
		// 스레드 B가 B,A 자원을 사용할 때 B자원을 가지고 A자원을 기다리면
		// 교착 현상이 발생할 수 있다
		
	}
	
	public Account getAccount(String name) {
		return accountMap.get(name);
	}
	
	public static void main(String[] args) {
		// 은행과 계좌를 만든다
		Bank bank = new Bank();
		bank.makeAccount("이름");
		
		Thread thread1 = new Thread(new DepositThread(bank, 50000));
		thread1.start();
		
		Thread thread2 = new Thread(new DepositThread(bank, 20000));
		thread2.start();
		
		
		
		try {
			thread1.join();
			thread2.join();
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		
		Account account = bank.getAccount("이름");
		System.out.println(account.getName() + account.getBalance() + "원 입니다");
	}
}
