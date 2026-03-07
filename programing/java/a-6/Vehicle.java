class Vehicle {
    String make;
    String model;
    int year;
    String fuelType;

    Vehicle(String make, String model, int year, String fuelType) {
        this.make = make;
        this.model = model;
        this.year = year;
        this.fuelType = fuelType;
    }

    void fuelEfficiency(double distance, double fuel) {
        System.out.println("Fuel Efficiency: " + (distance / fuel) + " km/l");
    }

    void maxSpeed(int speed) {
        System.out.println("Max Speed: " + speed + " km/h");
    }
}

class Truck extends Vehicle {

    Truck(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    public static void main(String[] args) {
        Truck t = new Truck("Volvo", "FH16", 2022, "Diesel");
        System.out.println("Truck Details");
        t.fuelEfficiency(400, 50);
        t.maxSpeed(120);
    }
}

class Car extends Vehicle {

    Car(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    public static void main(String[] args) {
        Car c = new Car("Toyota", "Camry", 2023, "Petrol");
        System.out.println("Car Details");
        c.fuelEfficiency(500, 25);
        c.maxSpeed(180);
    }
}

class Motorcycle extends Vehicle {

    Motorcycle(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    public static void main(String[] args) {
        Motorcycle m = new Motorcycle("Yamaha", "R15", 2024, "Petrol");
        System.out.println("Motorcycle Details");
        m.fuelEfficiency(300, 10);
        m.maxSpeed(150);
    }
}