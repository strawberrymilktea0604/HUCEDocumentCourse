

class Engine{
	String model;
	int maxSpeed;
	int status;
	
	public Engine() {
		
	}
	public Engine(String model, int maxSpeed) {
		this.model=model;
		this.maxSpeed =maxSpeed;
	}
	public void setStatus(int s) {
		status = s;
	}
	public String getModel() {
		return model;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public int getMaxSpeed() {
		return maxSpeed;
	}
	public void setMaxSpeed(int maxSpeed) {
		this.maxSpeed = maxSpeed;
	}
	public int getStatus() {
		return status;
	}
	
	public String toString() {
		return "toString: Model:"+model +"\tMax speed:"+maxSpeed;
	}
	
}


public class Car {
	private Engine e;
	String no;
	float fuel;
	
	public Engine getE() {
		
		return e;
	}
	public void setE(Engine e) {
		this.e = e;
	}
	public String getNo() {
		return no;
	}
	public void setNo(String no) {
		this.no = no;
	}
	public float getFuel() {
		return fuel;
	}
	public void setFuel(float fuel) {
		this.fuel = fuel;
	}
	public void run() {
		e.setStatus(1);
	}
	public void stop() {
		e.setStatus(0);
	}
	public void changeEngine(Engine engine) {
		
		this.e = engine;
	}
	
	public Car() {
		System.out.println("Default constructor's car");
		no = "";
		e = new Engine();
		fuel=0;
	}
	public void fillFuel(float fuel) {
		this.fuel +=fuel;
	}
	public Car(String name, String model, int maxSpeed) {
		no = name;
		e = new Engine(model,maxSpeed);
		fuel=0;
	}
	
	public Car(Car car) {
		this.e = new Engine(car.e.model,car.e.maxSpeed);
		this.no = car.no;
		this.fuel = car.fuel;
	}
	
	public void displayInfor() {
		System.out.println("Plate number:"+ no+"\tModel:"+e.getModel()+"\tMax Speed:"+e.getMaxSpeed());
	}

	public static void main(String[] arr) {
		Car car = new Car("Toyota","Toyota_Y78",200);
		car.displayInfor();
		Engine newEngine = new Engine("Toyota_K52", 300);
		car.changeEngine(newEngine);
		car.displayInfor();
		
		Engine e = car.getE();
		e.setMaxSpeed(200);
		car.displayInfor();
		
		Car car1 = new Car("N2-235","L3407",250);
		Car car2 = new Car(car1); 
		car2.displayInfor();
	}
	
}
