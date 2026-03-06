class Cat {
    int age;
    String name;

    // Default Constructor
    Cat() {
        name = "Kitty";
        age = 2;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

    public static void main(String[] args) {
        Cat c1 = new Cat();
        c1.display();
    }
}