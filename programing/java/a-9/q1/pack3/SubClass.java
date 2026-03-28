package q1.pack3;
import q1.pack1.ClassA;

public class SubClass extends ClassA {
    public void show() {
        System.out.println("Accessing inherited num: " + num);
        displayA();
    }

    public static void main(String[] args) {
        SubClass obj = new SubClass();
        obj.show();
    }
}