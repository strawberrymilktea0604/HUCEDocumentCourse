package Queue;

public class DemoQueue {
    public static void main(String[] args) {
        // QueueArray<Integer> queueArray = new QueueArray(10);
        // queueArray.enqueue(1);
        // queueArray.enqueue(2);
        // queueArray.enqueue(3);
        // queueArray.print();
        // System.out.println("\nBefore dequeue\n");
        // queueArray.dequeue();
        // queueArray.print();
        QueueLinkedList<Integer> queueLinkedList = new QueueLinkedList<Integer>();
        queueLinkedList.enqueue(1);
        queueLinkedList.enqueue(2);
        queueLinkedList.enqueue(3);
        System.out.println();
        queueLinkedList.print();
        System.out.println("\nBefore dequeue\n");
        queueLinkedList.dequeue();
        queueLinkedList.print();
    }
}
