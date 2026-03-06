class Book {
    String title;
    String author;
    double price;

    // Default Constructor
    Book() {
        title = "Unknown";
        author = "Unknown";
        price = 0.0;
        System.out.println("Default Constructor");
        display();
    }

    // Constructor with title and author
    Book(String t, String a) {
        title = t;
        author = a;
        price = 0.0;
        System.out.println("Constructor with Title and Author");
        display();
    }

    // Constructor with title, author and price
    Book(String t, String a, double p) {
        title = t;
        author = a;
        price = p;
        System.out.println("Constructor with Title, Author and Price");
        display();
    }

    void display() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println();
    }

    public static void main(String[] args) {
        Book b1 = new Book();
        Book b2 = new Book("Java Basics", "James");
        Book b3 = new Book("Advanced Java", "John", 500);
    }
}