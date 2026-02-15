package Queue;

public class ImplementLinked<T> {
    ImplementLinked<T> next;
    T element;

    public ImplementLinked() {
        next = null;
        element = null;
    }

    public ImplementLinked(T elem){
        next = null;
        element = null;
    }

    public ImplementLinked<T> getNext() {
        return next;
    }

    public void setNext(ImplementLinked<T> node) {
        next = node;
    }

    public T getElement() {
        return element;
    }

    public void setElement(T elem) {
        element = elem;
    }
}
