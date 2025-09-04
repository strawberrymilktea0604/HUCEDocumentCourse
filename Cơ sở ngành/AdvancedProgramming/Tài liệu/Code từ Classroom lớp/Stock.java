
public class Stock {
	String symbol;
	float price;
	public String getSymbol() {
		return symbol;
	}
	public void setSymbol(String symbol) {
		this.symbol = symbol;
	}
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	
	public Stock() {
		symbol = "";
		price = 0.0f;
	}
	
	public Stock(String s, float p) {
		symbol =s;
		price = p;
	}
	
	public boolean equals(Stock s) {
		
		if (symbol.equals(s.symbol)&& price == s.price) return true;
		return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stock stock1 = new Stock("SHB",10000);
		Stock stock2 = new Stock("SHB",10000);
		
		if(stock1.equals(stock2)) 
			System.out.println("Two stocks are the same!");
		else 
			System.out.println("Two stocks are not the same!");

	}

}
