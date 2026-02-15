public class LinkedStack<E> implements StackADT<E> {
    private LinearNode<E> top;
    private int count;

    public LinkedStack()
    {
        count = 0;
        top = null;
    }

    @Override
    public void push(E element) {
        LinearNode<E> temp = new LinearNode<E>(element);
        temp.setNext(top);
        top = temp;
        count++;
    }

    @Override
    public E pop() {
        if (isEmpty())
            throw new EmptyCollectionException("Linked Stack");
        E result = top.getElement();
        top = top.getNext();
        count --;
        return result;
    }

    @Override
    public E peek() {
        return top.getElement();
    }

    @Override
    public boolean isEmpty() {
        return (count==0);
    }

    @Override
    public int size() {
        return count;
    }
}
