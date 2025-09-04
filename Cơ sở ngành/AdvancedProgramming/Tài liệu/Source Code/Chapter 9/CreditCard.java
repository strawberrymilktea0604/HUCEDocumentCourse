
public class CreditCard {
//	balance:Money -creditLimit:Money -owner:Person
	
	private Money balance;
	
	private Money creditLimit;
	
	private Person owner;
	
	public CreditCard(Person owner, Money money) {
		this.owner = owner;
		Money copiedMoney = new Money(money);
		this.creditLimit = copiedMoney;
		Money initialMoney = new Money(0);
		this.balance = initialMoney;
	}
	
	public Money getBalance() {
		Money copiedMoney = new Money(this.balance);
		return copiedMoney;
	}
	
	public Money getCreditLimit() { 
		Money copiedMoney = new Money(this.creditLimit);
		return copiedMoney;
	}
	
	public String getOwner() {
		return this.owner.toString();
	}
	
	//charge(amount:Money):void
	public void charge(Money amount) {
		
	}
	
	
}
