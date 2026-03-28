
// 1. WAP to create a abstract class employee with abstract methods calculate salary and display info. Create Subclass manager and programer that extend the employee class and implement the respective methods to calculate salary and display information for each role.

abstract class Employee {
    abstract double calculateSalary();
    abstract void displayInfo();
}

class Manager extends Employee {
    double salary = 50000, bonus = 10000;

    double calculateSalary() {
        return salary + bonus;
    }

    void displayInfo() {
        System.out.println("Manager Salary: " + calculateSalary());
    }
}

class Programmer extends Employee {
    double salary = 40000;

    double calculateSalary() {
        return salary;
    }

    void displayInfo() {
        System.out.println("Programmer Salary: " + calculateSalary());
    }
}

public class Mainu {
    public static void main(String[] args) {
        new Manager().displayInfo();
        new Programmer().displayInfo();
    }
}