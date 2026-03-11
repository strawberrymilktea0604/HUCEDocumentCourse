// Builder
public interface Builder {
    void reset();
    void setDrink(String name);
    void setType(String type);
    void seCustomerName(String name);
}

// ConcreteBuilder
public class FuzzyDrinkBuilder implements Builder {
    private FuzzyDrink fuzzydrink;

    public FuzzyDrinkBuilder() {
        this.reset();
    }

    @Override
    public void reset() {
        this.fuzzydrink = new FuzzyDrink();
    }

    @Override
    public void setDrink(String name) {
        fuzzydrink.setDrink(type);
    }

    @Override
    public void setType(String type) {
        fuzzydrink.setType(type);
    }

    @Override
    public void setCustomerName(String name) {
        fuzzydrink.setCustomerName(name);
    }

    public Desktop getResult() {
        return this.fuzzydrink;
    }
}

public class SmoothieBuilder implements Builder {
    private Smoothie smoothie;

    public SmoothieBuilder() {
        this.reset();
    }

    @Override
    public void reset() {
        this.smoothie = new Smoothie();
    }

    @Override
    public void setDrink(String name) {
        smoothie.setDrink(name);
    }

    @Override
    public void setType(String type) {
        smoothie.setType(type);
    }

    @Override
    public void setCustomerName(String name) {
        smoothie.setCustomerName(name);
    }

    public Laptop getResult() {
        return this.smoothie;
    }
}

//Product
public class FuzzyDrink {
    private String drink;
    private String type;
    private String customerName;

    public void setDrink(String drink) {
        this.drink = drink;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setCustomerName(int customerName) {
        this.customerName = customerName;
    }

    @Override
    public String toString() {
        return "Order [FuzzyDrink = " + drink + ", type = " + type + ", Customer Name =" + customerName + "]";
    }
}

public class Laptop {
    private String drink;
    private String type;
    private String customerName;

    public void setDrink(String drink) {
        this.drink = drink;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setCustomerName(int customerName) {
        this.customerName = customerName;
    }

    @Override
    public String toString() {
        return "Order [FuzzyDrink = " + drink + ", type = " + type + ", Customer Name =" + customerName + "]";
    }
}


//Director
public class Director {
    public void makeFuzzydrink(Builder builder) {
        builder.reset();
        builder.setDrink("ABC");
        builder.setType("DEF");
        builder.setCustomerName("Hoang");
    }

    public void makeSmoothie(Builder builder) {
        builder.reset();
        builder.setDrink("FGFh");
        builder.setType("GDA");
        builder.setCustomerName("Vinh");
    }
}

//Client
public class Client {
    public static void main(String[] args) {
        Director director = new Director();

        FuzzyDrinkBuilder fuzzyDrinkBuilder = new FuzzyDrinkBuilder();
        director.makeFuzzydrink(fuzzyDrinkBuilder);
        FuzzyDrink fuzzydrink = OrderBuilder.getResult();
        System.out.println(fuzzydrink);

        SmoothieBuilder smoothieBuilder = new SmoothieBuilder();
        director.makeSmoothie(smoothieBuilder);
        Smoothie smoothie = OrderBuilder.getResult();
        System.out.println(smoothie);
    }
}
