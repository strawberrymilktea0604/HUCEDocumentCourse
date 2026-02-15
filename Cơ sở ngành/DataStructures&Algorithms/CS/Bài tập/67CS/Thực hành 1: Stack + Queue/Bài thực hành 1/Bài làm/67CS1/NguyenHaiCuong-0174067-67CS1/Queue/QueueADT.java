package Queue;

import Stack.EmptyCollectionException;

public interface QueueADT<T> {
    public void enqueue(T element);                       //push
    public T dequeue() throws EmptyCollectionException;   //pop  
    public T first() throws EmptyCollectionException;     //peek
    public boolean isEmpty();
    public int size();
}