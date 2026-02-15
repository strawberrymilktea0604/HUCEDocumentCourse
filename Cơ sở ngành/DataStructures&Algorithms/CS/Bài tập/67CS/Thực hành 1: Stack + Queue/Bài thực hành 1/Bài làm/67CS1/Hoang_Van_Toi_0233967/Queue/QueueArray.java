package Queue;

public class QueueArray<T> {
    private int size;
    private int maxSize;
    private int front;
    private int back;
    private Node<T>[] array;

    public QueueArray(int maxSize) {
        this.size = this.front = this.back = 0;
        this.maxSize = maxSize;
        this.array = new Node[maxSize];
    }

    public void enqueue(T data) {
        if (isFull()) {
            System.out.println("Queue is full!");
            return;
        }
        array[back] = new Node<T>(data);
        size++;
        back++;
    }

    public Node<T> dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return null;
        }
        Node<T> node = array[front];
        size--;
        front++;
        return node;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == maxSize;
    }

    public int size() {
        return size;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        int temp = front;
        while (temp < back) {
            array[temp].printData();
            temp++;
        }
    }
}