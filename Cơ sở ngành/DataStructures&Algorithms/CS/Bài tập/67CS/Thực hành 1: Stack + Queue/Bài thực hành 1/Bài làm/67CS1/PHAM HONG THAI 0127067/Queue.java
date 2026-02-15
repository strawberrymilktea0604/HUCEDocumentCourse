
import java.util.Arrays;

public class Queue<T> {

    private static final int MAX_SIZE = 100; // Kich thuoc toi da cua hang doi
    private Object[] data; // Mang chua du lieu cua hang doi
    private int front; // Chi so cua phan tu dau hang doi
    private int rear; // Chi so cua phan tu cuoi hang doi
    private int size; // Kich thuoc hien tai cua hang doi

    public Queue() {
        data = new Object[MAX_SIZE];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Kiem tra xem hang doi co rong hay khong
    public boolean isEmpty() {
        return size == 0;
    }

    // Kiem tra xem hang doi co day hay khong
    public boolean isFull() {
        return size == MAX_SIZE;
    }

    // Them mot phan tu vao cuoi hang doi
    public void enqueue(T item) {
        if (isFull()) {
            throw new IllegalStateException("Hang doi day");
        }
        rear = (rear + 1) % MAX_SIZE;
        data[rear] = item;
        size++;
    }

    // Loai bo phan tu dau tien cua hang doi va tra ve phan tu do
    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Hang doi rong");
        }
        T item = (T) data[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return item;
    }

    // Lay phan tu dau tien cua hang doi nhung khong loai bo
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Hang doi rong");
        }
        return (T) data[front];
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        System.out.println("Phan tu dau: " + queue.peek());

        while (!queue.isEmpty()) {
            System.out.println("Phan tu lay ra: " + queue.dequeue());
        }
    }
}

