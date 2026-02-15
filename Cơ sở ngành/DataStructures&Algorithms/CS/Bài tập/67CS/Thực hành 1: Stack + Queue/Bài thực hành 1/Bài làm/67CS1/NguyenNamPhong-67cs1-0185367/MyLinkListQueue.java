public class MyLinkListQueue implements IStackAndQueue {

    private class Node {
        private int value;
        private Node next;

        Node(int value) {
            this.value = value;
        }
    }

    Node headNode, tailNode;

    MyLinkListQueue() {
        headNode = tailNode = null;
    }

    @Override
    public boolean push(int value) {
        Node newNode = new Node(value);
        if(isEmpty()) {
            headNode = tailNode = newNode;
        }else {
            // thêm phần tử vào cuối
            tailNode.next = newNode;
            tailNode = newNode;
        }
        return true;
    }

    @Override
    public int pop() {
        int value = headNode.value;
        if(isEmpty()) {
            return -1;
        }

        if(headNode == tailNode) {
            headNode = tailNode = null;
        }else {
            headNode = headNode.next; 
        }
        return value;
    }

    @Override
    public boolean isFull() {
        return false;
    }

    @Override
    public boolean isEmpty() {
        return (headNode == null && tailNode == null);
    }

    @Override
    public void show() {
        if(isEmpty()) {
            System.out.println("Queue is Empty!");
        }
        Node curNode = headNode;
        while(curNode != null) {
            System.out.print(curNode.value + " ");
            curNode = curNode.next;
        }
        System.out.println();
    }
}
