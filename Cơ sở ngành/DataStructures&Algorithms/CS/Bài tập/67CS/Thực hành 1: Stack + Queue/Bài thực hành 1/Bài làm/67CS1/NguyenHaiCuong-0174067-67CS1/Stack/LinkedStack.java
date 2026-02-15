package Stack;


public class LinkedStack<T> implements StackADT<T> {
    
    private int count;
    private ImplementLinked<T> top;

    public LinkedStack(){
        count = 0;
        top = null;
    }

    @Override
    public void push(T element) {
        ImplementLinked<T> temp = new ImplementLinked<T>(element);

        temp.setNext(top);
        top = temp;
        count++;
    }

    @Override
    public T pop() throws EmptyCollectionException{
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        T result = top.getElement();
        top = top.getNext();
        count--;

        return result;
    }

    @Override
    public T peek() throws EmptyCollectionException {
        // TODO Auto-generated method stub
        if(isEmpty())
            throw new EmptyCollectionException("stack");
        return top.element;
    }

    @Override
    public boolean isEmpty() {
        // TODO Auto-generated method stub
        return count == 0;
    }

    @Override
    public int size() {
        // TODO Auto-generated method stub
                return count;
    }

}
