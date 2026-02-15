package Queue;

import java.util.Arrays;
import Stack.EmptyCollectionException;

public class QueueArray<T> implements QueueADT<T> {
    private final static int CAP = 15;
    private int head;
    private T[] QuAr;

    
    public QueueArray() {
        head = 0;
        QuAr = (T[]) (new Object[CAP]);
    }

    private void expandCapacity() {
        QuAr = Arrays.copyOf(QuAr, QuAr.length * 2);
    }

    @Override
    public void enqueue(T element){
        if(head == QuAr.length)
            expandCapacity();

        QuAr[head] = element;
        head++;
    }

    @Override
    public T dequeue() throws EmptyCollectionException
    {
        if(isEmpty())
            throw new EmptyCollectionException("queue");
        T result = QuAr[0];
        QuAr = Arrays.copyOfRange(QuAr, 1, head);
        head--;
        return result;
    }

    @Override
    public T first() throws EmptyCollectionException{
        if(isEmpty())
            throw new EmptyCollectionException("queue");
        T result = QuAr[0];
        return result;
    }

    @Override
    public boolean isEmpty(){
        return head == 0;
    }

    public String toString() {
        String result = "";
        for(int i = 0; i < size(); i++)
            result += String.valueOf(QuAr[i]) + " ";

        return result;
    }

    @Override
    public int size() {
        return head;
    }
}

