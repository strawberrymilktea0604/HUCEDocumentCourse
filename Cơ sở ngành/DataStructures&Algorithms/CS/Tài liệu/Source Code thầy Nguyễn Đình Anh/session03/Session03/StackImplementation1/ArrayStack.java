import java.util.Arrays;

public class ArrayStack<T> implements StackADT<T> {

    private static final int INITIAL_CAPACITY = 5;

    T[] stack;
    int top;

    @SuppressWarnings("unchecked")
    public ArrayStack() {
        top = 0;
        stack = (T[])(new Object[INITIAL_CAPACITY]);
    }

    @Override
    public void push(T element) {
        if (size() == top)
            expandCapacity();

        stack[top] = element;
        top ++;
    }

    @Override
    public T pop() {
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        top--;
        T result = stack[top];
        stack[top] = null;

        return result;
    }

    @Override
    public T peek() {
        if (isEmpty())
            throw new EmptyCollectionException("stack");

        return stack[top-1];
    }

    @Override
    public boolean isEmpty() {
        return (top == 0);
    }

    @Override
    public int size() {
        return top;
    }

    private void expandCapacity() {
        stack = Arrays.copyOf(stack, stack.length * 2);
    }
}
