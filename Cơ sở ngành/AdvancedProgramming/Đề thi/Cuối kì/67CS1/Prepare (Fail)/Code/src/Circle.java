public class Circle extends Shape {

    private double radius;

    public void calculateArea(double area) {

    }

    public Circle() {


    }

    public Circle(double r) {
        radius = r;
        calculateArea(Math.PI * r * r);
    }

    public double getRadius() {
        return radius;
    }

}
