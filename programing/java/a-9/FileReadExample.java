import java.io.FileReader;

public class FileReadExample {
    public static void readFile() {
        try {
            FileReader fr = new FileReader("nonexistent.txt");
            System.out.println("File opened successfully");
        } catch (Exception e) {
            System.out.println("Error: File not found!");
        }
    }

    public static void main(String[] args) {
        readFile();
    }
}