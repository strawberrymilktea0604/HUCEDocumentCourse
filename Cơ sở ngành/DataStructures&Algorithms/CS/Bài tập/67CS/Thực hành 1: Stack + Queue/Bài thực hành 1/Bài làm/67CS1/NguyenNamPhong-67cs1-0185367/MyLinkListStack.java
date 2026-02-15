import java.util.ArrayList;

public class MyLinkListStack implements IStackAndQueue {

    private class Node {
        private int value;
        private Node next;

        Node(int value) {
            this.value = value;
        }
    }

    Node topNode;
    MyLinkListStack() {
        topNode = null;
    }

    @Override
    public boolean push(int value) {
        if(!isFull()) {
            Node newNode = new Node(value);
            newNode.next = topNode;
            topNode = newNode;
            return true;
        }
        return false;
    }

    @Override
    public int pop() {
        if(isEmpty()) {
            return -1;
        }
        int value = topNode.value;
        topNode = topNode.next;
        return value;
    }

    @Override
    public boolean isFull() {
        return false;
    }

    @Override
    public boolean isEmpty() {
        return topNode == null;
    }

    @Override
    public void show() {
        if(isEmpty()) {
            System.out.println("Stack is Empty!");
            return;
        }else {
            Node tempNode = topNode;
            ArrayList<Integer> temArrayList = new ArrayList<>();
            while(tempNode != null) {
                temArrayList.add(tempNode.value);
                tempNode = tempNode.next;
            }
            for (int i = temArrayList.size() - 1; i >=0; i--) {
                System.out.print(temArrayList.get(i) + " ");
            }
            System.out.println();
        }
    }
}
