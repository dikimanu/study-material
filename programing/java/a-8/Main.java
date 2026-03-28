// 2. WAP to create an abstract class shape 3D with abstract methods calculate volume and calculate surface area.creat subclass sphere and cube the extend shape 3D class and implement the respective methods to calculate the volume and surface area of each shape

// Abstract class
abstract class Shape3D {
    // Abstract methods
    abstract double calculateVolume();
    abstract double calculateSurfaceArea();
}

// Subclass Sphere
class Sphere extends Shape3D {
    double radius;

    Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    double calculateVolume() {
        return (4.0 / 3.0) * Math.PI * radius * radius * radius;
    }

    @Override
    double calculateSurfaceArea() {
        return 4 * Math.PI * radius * radius;
    }

    void display() {
        System.out.println("Sphere:");
        System.out.println("Radius: " + radius);
        System.out.println("Volume: " + calculateVolume());
        System.out.println("Surface Area: " + calculateSurfaceArea());
        System.out.println();
    }
}

// Subclass Cube
class Cube extends Shape3D {
    double side;

    Cube(double side) {
        this.side = side;
    }

    @Override
    double calculateVolume() {
        return side * side * side;
    }

    @Override
    double calculateSurfaceArea() {
        return 6 * side * side;
    }

    void display() {
        System.out.println("Cube:");
        System.out.println("Side: " + side);
        System.out.println("Volume: " + calculateVolume());
        System.out.println("Surface Area: " + calculateSurfaceArea());
        System.out.println();
    }
}

// Main class
public class Main {
    public static void main(String[] args) {
        Sphere s = new Sphere(3);
        Cube c = new Cube(4);

        s.display();
        c.display();
    }
}