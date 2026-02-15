interface QueueADT<T>
{
    public void enqueue(T data);
    public T dequeue() throws EmptyCollectionException; 
    public T first() throws EmptyCollectionException; 
    public boolean isEmpty(); 
    public int size(); 
}
