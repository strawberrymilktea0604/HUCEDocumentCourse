public class ArrayQueue<T> {
    private T[] array;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public ArrayQueue(int capacity) {
        this.capacity = capacity;
        array = (T[]) new Object[capacity];
        front = rear = size = 0;
    }

    public void enqueue(T item) {
        if (size == capacity) {
            throw new IllegalStateException("Queue is full");
        }
        array[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return array[front];
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
