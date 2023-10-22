public class LabExamples {
    public static void main(String[] args) {
        Box b = new Box(10, 20, 30);
        b.show();
    }
}

class Shape {
    double length;
    double width;

    public Shape(double l, double w) {
        length = l;
        width = w;
    }

    public Shape() {
    };

    public double area() {
        return length * width;
    }
}

class Box extends Shape {
    double height;

    public Box() {
        super();
        height = 0;
    }

    public Box(double l, double w, double h) {
        super(l, w);
        height = h;
    }

    public void show() {
        System.out.println("Length: " + length);
        System.out.println("Width: " + width);
        System.out.println("Height: " + height);
    }
}

class Circle extends Shape {
    public Circle(double r) {
        super(r, r);
    }

    public double area() {
        return Math.PI * length * length;
    }
}