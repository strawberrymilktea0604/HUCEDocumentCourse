
// Queue using an Array
public class QueueArray<T> {
    private static final int DEFAULT_CAPACITY = 10;
    private T[] array;
    private int front;
    private int rear;
    private int size;

    public QueueArray() {
        array = (T[]) new Object[DEFAULT_CAPACITY];
        front = rear = -1;
        size = 0;
    }

    public void enqueue(T data) {
        if (size == array.length) {
            resize();
        }
        rear = (rear + 1) % array.length;
        array[rear] = data;
        if (isEmpty()) {
            front = rear;
        }
        size++;
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        T data = array[front];
        front = (front + 1) % array.length;
        size--;
        return data;
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

    private void resize() {
        int newCapacity = array.length * 2;
        T[] newArray = (T[]) new Object[newCapacity];
        for (int i = 0, j = front; i < size; i++, j = (j + 1) % array.length) {
            newArray[i] = array[j];
        }
        array = newArray;
        front = 0;
        rear = size - 1;
    }
}