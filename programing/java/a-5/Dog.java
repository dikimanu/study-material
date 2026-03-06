class Dog {
    String name;
    String colour;

    // Parameterized Constructor
    Dog(String n, String c) {
        name = n;
        colour = c;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Colour: " + colour);
    }

    public static void main(String[] args) {
        Dog d1 = new Dog("Tommy", "Brown");
        d1.display();
    }
}