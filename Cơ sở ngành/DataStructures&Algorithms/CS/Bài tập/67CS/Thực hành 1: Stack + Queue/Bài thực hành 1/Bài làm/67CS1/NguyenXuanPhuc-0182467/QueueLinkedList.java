package Maze;
class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }

    public Node getNext() {
        return null;
    }

    public void setNext(Node newNode) {
    }

    public int getData() {
        return 0;
    }
}

public class QueueLinkedList {
    private Node front;
    private Node rear;
    private int size;

    public QueueLinkedList() {
        front = null;
        rear = null;
        size = 0;
    }

    public boolean isEmpty() {
        return (front == null);
    }

    public int getSize() {
        return size;
    }

    public void enqueue(int data) {
        Node newNode = new Node(data);
        if (rear == null) {
            front = newNode;
            rear = newNode;
        } else {
            rear.setNext(newNode);
            rear = newNode;
        }
        size++;
    }

    public int dequeue() {
        if (front == null) {
            System.out.println("Queue is empty");
            return -1;
        } else {
            int data = front.getData();
            front = front.getNext();
            if (front == null) {
                rear = null;
            }
            size--;
            return data;
        }
    }

    public void display() {
        Node temp = front;
        while (temp != null) {
            System.out.print(temp.getData() + " ");
            temp = temp.getNext();
        }
    }
}

