public interface HeapADT<T extends Comparable<T>> extends BinaryTreeADT<T>
{
    public void addElement(T element);
    public T removeMin();
    public T findMin();
}