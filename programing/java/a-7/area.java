// Base class
class Shape {

    double calculateArea() {
        return 0;
    }
}

// Rectangle class
class Rectangle extends Shape {
    double length;
    double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Override calculateArea
    double calculateArea() {
        return length * width;
    }
}

// Triangle class
class Triangle extends Shape {
    double base;
    double height;

    Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    // Override calculateArea
    double calculateArea() {
        return 0.5 * base * height;
    }
}

// Main class
public class area {
    public static void main(String[] args) {

        Rectangle r = new Rectangle(10, 5);
        Triangle t = new Triangle(8, 4);

        System.out.println("Area of Rectangle: " + r.calculateArea());
        System.out.println("Area of Triangle: " + t.calculateArea());
    }
}