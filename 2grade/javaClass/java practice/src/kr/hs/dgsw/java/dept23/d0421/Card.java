package kr.hs.dgsw.java.dept23.d0421;

public class Card {
	public final String type;
	public int money;
	
	public Card(String inputType, int money) {
		this.type = inputType;
		this.money = money;
	}
	public String getType() {
		return this.type;
	}
	
	public boolean canPaiable(int fee) {
		if (this.money > fee) {
			return true;
		} else {
			return false;
		}
		
	}
	
	public void payment(int fee) {
		this.money -= fee;
	}
}
