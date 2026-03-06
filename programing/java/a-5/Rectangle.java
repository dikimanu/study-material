class Rectangle {
    int length;
    int width;

    // Parameterized Constructor
    Rectangle(int l, int w) {
        length = l;
        width = w;
    }

    // Copy Constructor
    Rectangle(Rectangle r) {
        length = r.length;
        width = r.width;
    }

    void display() {
        System.out.println("Length: " + length);
        System.out.println("Width: " + width);
        System.out.println();
    }

    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(10, 5);
        System.out.println("Original Object");
        r1.display();

        Rectangle r2 = new Rectangle(r1);
        System.out.println("Copied Object");
        r2.display();
    }
}