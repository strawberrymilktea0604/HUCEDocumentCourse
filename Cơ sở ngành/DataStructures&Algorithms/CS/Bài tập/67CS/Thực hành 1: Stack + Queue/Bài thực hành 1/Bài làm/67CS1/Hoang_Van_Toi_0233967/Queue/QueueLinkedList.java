package Queue;

public class QueueLinkedList<T> {
    private int size;
    private Node<T> head;
    private Node<T> tail;

    public QueueLinkedList() {
        this.size = 0;
        this.head = this.tail = null;
    }

    public void enqueue(T data) {
        Node<T> newNode = new Node<T>(data);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail.setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    public Node<T> dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return null;
        }
        if (head == tail) {
            head = tail = null;
        }
        Node<T> node = head;
        head = head.getNext();
        size--;
        return node;
    }

    public boolean isEmpty() {
        return head ==  null;
    }

    public int size() {
        return size;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty!");
            return;
        }
        Node<T> temp = head;
        while (temp != null) {
            temp.printData();
            temp = temp.getNext();
        }
    }
}
