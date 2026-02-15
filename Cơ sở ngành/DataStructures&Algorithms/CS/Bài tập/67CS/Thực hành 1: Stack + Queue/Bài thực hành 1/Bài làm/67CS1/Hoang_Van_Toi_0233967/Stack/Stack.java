package Stack;

class Stack<T> {
    private Node<T> top;
    private int size;

    public Stack() {
        this.top = null;
    }

    public void push(T data) { 
        Node<T> node = new Node<T>(data);
        node.setNext(top);
        top = node;
        size++;
        
        }

    public Node<T> peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return null;
        }
        return top;
    }

    public Node<T> pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return null;
        }
        Node<T> node = top;
        top = top.getNext();
        size--;
        return node;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        if (top == null) return true;
        return false;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Stack is empty!");
            return;
        }
        Node<T> temp = top;
        while (temp != null) {
            temp.printData();
            temp = temp.getNext();
        }
    }

}