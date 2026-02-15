public class LinkedStack<T> implements StackADT<T>
{
    private int count; 
    private LinearNode<T> top;

    public LinkedStack() 
    {
        count = 0; 
        top = null;
    }

    @Override
    public void push(T data) 
    {
        LinearNode<T> temp = new LinearNode<T>(data);
        
        temp.next = top;
        top = temp; 
        count++;
    }

    @Override
    public T pop() throws EmptyCollectionException 
    {
        if(isEmpty()) 
            throw new EmptyCollectionException("stack");

        T res = top.data; 
        top = top.next; 
        count--; 

        return res;
    }   

    @Override
    public T peek() throws EmptyCollectionException 
    {
        if(isEmpty()) 
            throw new EmptyCollectionException("stack"); 
        
        return top.data; 
    }

    @Override
    public boolean isEmpty() 
    {
        return count == 0;     
    }

    @Override
    public int size() 
    {
        return count;    
    }

    
 }