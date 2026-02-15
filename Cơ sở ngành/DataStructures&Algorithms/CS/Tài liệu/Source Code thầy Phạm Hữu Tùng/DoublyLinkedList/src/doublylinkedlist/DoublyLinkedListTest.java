package doublylinkedlist;

public class DoublyLinkedListTest {
    public static void main(String[] args) {
        DoublyLinkedList<String> list = new DoublyLinkedList<>();

        list.addFirst("B");
        list.addFirst("A");
        list.addLast("C");
        list.addLast("D");
        System.out.println("After adding elements: " + list);

        list.removeFirst();
        System.out.println("After removeFirst: " + list);

        list.removeLast();
        System.out.println("After removeLast: " + list);

        System.out.println("First element: " + list.first());
        System.out.println("Last element: " + list.last());
        System.out.println("Size: " + list.size());
    }
}
