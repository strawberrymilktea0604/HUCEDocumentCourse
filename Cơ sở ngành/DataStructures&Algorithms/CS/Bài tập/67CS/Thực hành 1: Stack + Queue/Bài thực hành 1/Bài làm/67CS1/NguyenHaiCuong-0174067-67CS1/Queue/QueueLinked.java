package Queue;

import Stack.EmptyCollectionException;

public class QueueLinked<T> implements QueueADT<T> {
    private int count;
    private ImplementLinked<T> top;
    private ImplementLinked<T> rear;

    public QueueLinked() {
        count = 0;
        top = null;
        rear = null;
    }

    @Override
    public void enqueue(T ele) {
        ImplementLinked<T> s = new ImplementLinked<>(ele);
        if(isEmpty())
            top = s;
        else
            rear.next = s;

        rear = s;
        count++;
    }

    @Override
    public T dequeue() throws EmptyCollectionException{
        if(isEmpty())
            throw new EmptyCollectionException("queue");

        T result = top.element;
        top = top.next;
        count--;

        if(isEmpty())
            rear = null;
        
        return result;
    }

    @Override
    public T first() throws EmptyCollectionException {
        if(isEmpty())
            throw new EmptyCollectionException("queue.");
        
            return top.element;
    }

    @Override
    public boolean isEmpty() {
        return count == 0;
    }

    @Override
    public int size() {
        return count;
    }

}
