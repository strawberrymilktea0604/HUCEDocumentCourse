import java.util.Arrays; 

public class ArrayQueue<T> implements QueueADT<T> 
{
    private final static int DEFAULT_CAPACITY = 20; 
    private int top; 
    private T[] queue;

    @SuppressWarnings("unchecked")
    public ArrayQueue() 
    {
        top = 0; 
        queue = (T[]) (new Object[DEFAULT_CAPACITY]); 
    }

    @Override
    public void enqueue(T data) 
    {
        if(top == queue.length) 
            expandCapacity();

        queue[top] = data; 
        top++;
    }

    @Override
    public T dequeue() throws EmptyCollectionException 
    {
        if(isEmpty())
            throw new EmptyCollectionException("queue");   

        T res = queue[0];
        queue = Arrays.copyOfRange(queue, 1, top); 
        top--;
        return res; 
    }

    @Override
    public T first() throws EmptyCollectionException 
    {
        if(isEmpty())
            throw new EmptyCollectionException("queue");  

        T res = queue[0];
        return res; 
    }

    @Override
    public boolean isEmpty() 
    {
        return top == 0;
    }

    @Override
    public int size() 
    {
        return top;
    }

    private void expandCapacity() 
    {
        queue = Arrays.copyOf(queue, queue.length * 2); 
    }

    public String toString() 
    {
        String res = "";
        for(int i = 0; i < size(); i++) 
            res += String.valueOf(queue[i]) + " "; 
        
        return res; 
    }
}
