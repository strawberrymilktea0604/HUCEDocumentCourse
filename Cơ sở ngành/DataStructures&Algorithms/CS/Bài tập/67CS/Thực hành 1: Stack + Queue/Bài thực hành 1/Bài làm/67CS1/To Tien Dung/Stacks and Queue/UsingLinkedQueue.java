public class UsingLinkedQueue<T> implements QueueADT<T> 
{
    private int count; 
    private LinearNode<T> head;  
    private LinearNode<T> tail;

    public LinkedQueue() 
    {
        count = 0; 
        head = null; 
        tail = null;
    }

    @Override
    public void enqueue(T data) 
    {
        LinearNode<T> node = new LinearNode<>(data);
        if(isEmpty()) 
            head = node;
        else
            tail.next = node;
        
        tail = node; 
        count++; 
    }

    @Override
    public T dequeue() throws EmptyCollectionException 
    {
        if(isEmpty()) 
            throw new EmptyCollectionException("queue");

        T res = head.data; 
        head = head.next; 
        count--; 

        if(isEmpty())
            tail = null;

        return res;
    }

    @Override
    public T first() throws EmptyCollectionException 
    {
        if(isEmpty()) 
            throw new EmptyCollectionException("queue");

        return head.data;
    }

    @Override
    public boolean isEmpty() {
        return count == 0;
    }

    @Override
    public int size() 
    {
        return count;
    }


}
