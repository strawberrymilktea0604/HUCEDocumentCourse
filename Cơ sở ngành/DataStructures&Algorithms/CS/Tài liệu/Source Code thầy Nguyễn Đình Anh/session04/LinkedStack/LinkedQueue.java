public class LinkedQueue<T> implements QueueADT<T> {
    private int count;
    private LinearNode<T> front, rear;

    public LinkedQueue()
    {
        count = 0;
        front = rear = null;
    }

    public void enqueue(T element)
    {
        LinearNode<T> node = new LinearNode<T>(element);
        if (isEmpty())
            front = node;
        else
            rear.setNext(node);

        rear = node;
        count++;
    }

    public T dequeue() throws EmptyCollectionException
    {
        if (isEmpty())
            throw new EmptyCollectionException("queue");
        
        T result = front.getElement();
        front = front.getNext();
        count--;
        return result;
    }

    public T first() throws EmptyCollectionException
    {
        if (isEmpty())
            throw new EmptyCollectionException("queue");
        
        return front.getElement();
        
    }

    public boolean isEmpty()
    {
        return count == 0;
    }

    public int size()
    {
        return count;
    }
}
