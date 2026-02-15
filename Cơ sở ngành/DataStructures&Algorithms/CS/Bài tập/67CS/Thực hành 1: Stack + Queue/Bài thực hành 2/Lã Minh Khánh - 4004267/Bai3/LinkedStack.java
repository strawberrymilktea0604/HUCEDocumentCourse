public class LinkedStack<T> implements StackADT<T> 
{
    private LinearNode<T> top;
    private int count;

    public LinkedStack()
    {
        top = null;
        count = 0;
    }

    @Override
    public void push(T element) 
    {
        LinearNode<T> temp = new LinearNode<T>(element);
        temp.setNext(top);
        top = temp;
        count ++;
    }

    @Override
    public T pop()
    {
        if (isEmpty())
            throw new EmptyCollectionException("stack");
        T result = top.getElement();
        top = top.getNext();
        count--;
        return result;
    }

    @Override
    public T peek() 
    {
        if (isEmpty())
            throw new EmptyCollectionException("stack");
        return top.getElement();
    }

    public boolean isEmpty()
    {
        return (count==0);
    }

    public int size()
    {
        return count;
    }
}
