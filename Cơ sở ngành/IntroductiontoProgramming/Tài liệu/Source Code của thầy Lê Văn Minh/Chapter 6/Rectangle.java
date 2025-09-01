public class Rectangle {
    private double width;
    private double height;

    public Rectangle() {
        this.width = 0;
        this.height = 0;
    }

    public Rectangle(double width, double height) {
        if (width >= 0)
            this.width = width;
        if (height >= 0)
            this.height = height;
    }

    public Rectangle(double width) {
        this.width = width;
    }

    public double calArea() {
        return width * height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
}
