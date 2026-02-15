import java.util.*;

import org.w3c.dom.Node;
public class LinkedStack<T> implements StackADT<T> {
    private int count;
    private LinearNode<T> top;
    public LinkedStack() {
        count = 0;
        top = null;
    }
    public void push(T element) {
        LinearNode<T> temp = new LinearNode<T>(element);
        temp.setNext(top);
        top = temp;
        count++;
    }
    public T pop() throws EmptyCollectionException {
        if (isEmpty())
            throw new EmptyCollectionException("stack");
        T result = top.getElement();
        top = top.getNext();
        count--;
        return result;
    }
    public T peek() throws EmptyCollectionException {
        if (isEmpty()) {
            throw new EmptyCollectionException("stack");
        } else {
            return top.getElement();
        }
    }
    public boolean isEmpty() {
        return top == null;
    }
    public int size() {
        if (top == null) {
            return 0;
        }
        int size = 0;
        Node tmpNode = (Node) top;
        while (tmpNode != null) {
            size++;
            tmpNode = tmpNode.getNextSibling();
        }
        return size;
    }
}
