package Maze;

public class Queuearray {
    private int[] arr;
    private int front;
    private int rear;
    private int capacity;

    public Queuearray(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    public void enqueue(int item) {
        if (isFull()) {
            System.out.println("Queue is full");
            return;
        }
        rear++;
        arr[rear] = item;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        int item = arr[front];
        front++;
        return item;
    }

    public boolean isEmpty() {
        return front == rear + 1;
    }

    public boolean isFull() {
        return rear == capacity - 1;
    }

    public int size() {
        return rear - front + 1;
    }
}
