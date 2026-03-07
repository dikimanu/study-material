class Employee {
    void work() {
        System.out.println("Employee is working");
    }

    void getSalary() {
        System.out.println("Employee receives salary");
    }
}

class HRManager extends Employee {

    @Override
    void work() {
        System.out.println("HR Manager manages employees");
    }

    void addEmployee() {
        System.out.println("HR Manager adds a new employee");
    }

    public static void main(String[] args) {
        HRManager hr = new HRManager();

        hr.work();
        hr.getSalary();
        hr.addEmployee();
    }
}


// javac Employee.java
// java HRManager