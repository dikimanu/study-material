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
        double efficiency = distance / fuel;
        System.out.println("Fuel Efficiency: " + efficiency + " km/l");
    }

    void maxSpeed(int speed) {
        System.out.println("Max Speed: " + speed + " km/h");
    }
}

class Truck extends Vehicle {

    Truck(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }
}

class Car extends Vehicle {

    Car(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }
}

class Motorcycle extends Vehicle {

    Motorcycle(String make, String model, int year, String fuelType) {
        super(make, model, year, fuelType);
    }

    public static void main(String[] args) {

        Car car = new Car("Toyota", "Camry", 2022, "Petrol");
        car.fuelEfficiency(500, 25);
        car.maxSpeed(180);

        Truck truck = new Truck("Volvo", "FH", 2021, "Diesel");
        truck.fuelEfficiency(400, 50);
        truck.maxSpeed(120);

        Motorcycle bike = new Motorcycle("Yamaha", "R15", 2023, "Petrol");
        bike.fuelEfficiency(300, 10);
        bike.maxSpeed(150);
    }
}