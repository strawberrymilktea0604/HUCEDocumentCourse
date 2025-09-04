class Engine {
    String model;
    int MaxSpeed;
    int status;
    public void setStatus(int s) {
        status = s; 
    }


public Engine() {


}

public Engine(String m, int s) {
    this.model = m;
    MaxSpeed = s;

}


public static class bai2 {
    Engine e;
    String id;
    public void run() {
        e.setStatus(1);
    }

    public void stop() {
        e.setStatus(0);
    }

    public void changeEngine(Engine newEngine) {
        this.e = newEngine;
    }

    public bai2(String name, String model, int maxSpeed) {
        System.out.println("Default constructor's car");
        id = " ";
        e = new Engine();
        no = name;

    }

    public bai2(String string) {
    }

    public void displayInfor() {

    }

    public static void main(String[] arr) {
        bai2 car = new bai2("Lambogini");
    }
    
}

}