import java.util.Arrays;

public class ArrayStack<T> implements StackADT<T> {

    private final static int DEFAULT_CAPACITY = 20;
    private int top;
    private T[] stack;

    @SuppressWarnings("unchecked")
    public ArrayStack(int initialCapacity) {
        top = 0;
        stack = (T[]) (new Object[initialCapacity]);
    }

    public ArrayStack() {
        this(DEFAULT_CAPACITY);
    }

    @Override
    public void push(T element) {
        if (size() == stack.length)
            expandCapacity();
        stack[top] = element;
        top++;
    }

    @Override
    public T pop() throws EmptyCollectionException {
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        top--;
        T res = stack[top];
        stack[top] = null;

        return res;
    }

    @Override
    public T peek() throws EmptyCollectionException {
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        T res = stack[top - 1];
        return res;
    }

    @Override
    public boolean isEmpty() {
        return top == 0;
    }

    @Override
    public int size() {
        return top;
    }

    public void expandCapacity() {
        stack = Arrays.copyOf(stack, stack.length * 2);
    }
}
