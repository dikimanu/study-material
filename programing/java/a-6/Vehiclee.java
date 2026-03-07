class Vehiclee {
    void drive() {
        System.out.println("The vehicle is driving");
    }
}

class Car extends Vehiclee {
    @Override
    void drive() {
        System.out.println("The car is driving smoothly");
    }

    public static void main(String[] args) {
        Car c = new Car();
        c.drive();
    }
}

// javac Vehiclee.java
// java Car