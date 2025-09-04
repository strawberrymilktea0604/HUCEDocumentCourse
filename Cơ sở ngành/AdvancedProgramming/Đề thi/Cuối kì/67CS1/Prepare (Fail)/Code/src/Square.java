public class Square extends Shape {
    private double edge;

    public void calculateArea(double area) {

    }

    public Square() {

    }

    public Square(double e) {
        edge = e;
        calculateArea(e * e);
    }

    public double getEdge() {
        return edge;
    }

}
