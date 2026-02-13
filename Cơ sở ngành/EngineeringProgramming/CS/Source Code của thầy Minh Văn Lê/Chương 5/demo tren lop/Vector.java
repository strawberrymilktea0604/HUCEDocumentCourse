class Vector {
    private double x;
    private double y;

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public String toString() {
        return "Vector(" + x + ", " + y + ")";
    }
}

class Main {
    public static void main(String[] args) {
        Vector v = new Vector(3.0, 4.0);
        System.out.println(v);
    }
}