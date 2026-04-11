import java.util.Arrays;

class SortThread extends Thread {
    int[] arr;

    SortThread(int[] arr) {
        this.arr = arr;
    }

    public void run() {
        Arrays.sort(arr);
    }
}

public class MultiThreadSort {
    public static void main(String[] args) throws InterruptedException {
        int[] arr = {9, 5, 2, 8, 1, 7};

        SortThread t1 = new SortThread(arr);

        t1.start();
        t1.join();

        System.out.println("Sorted Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}