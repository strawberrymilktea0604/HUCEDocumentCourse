
public class LinkedListStack<T> {

    private Node<T> top; // Đỉnh ngăn xếp

    // Dinh nghia mot node trong ngan xep
    private static class Node<T> {
        T data;
        Node<T> next;

        Node(T data) {
            this.data = data;
        }
    }

    // Kiem tra xem ngan xep co rong hay khong
    public boolean isEmpty() {
        return top == null;
    }

    // Them mot phan tu vao dinh cua ngan xep
    public void push(T data) {
        Node<T> newNode = new Node<>(data);
        newNode.next = top;
        top = newNode;
    }

    // Lay phan tu tren dinh cua ngan xep
    public T peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Ngan xep rong");
        }
        return top.data;
    }

    // Xoa phan tu tren dinh cua ngan xep
    public T pop() {
        if (isEmpty()) {
            throw new IllegalStateException("Ngan xep rong");
        }
        T data = top.data;
        top = top.next;
        return data;
    }

    public static void main(String[] args) {
        LinkedListStack<Integer> stack = new LinkedListStack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Phan tu tren dinh: " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("Phan tu lay ra: " + stack.pop());
        }
    }
}

