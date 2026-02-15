import java.util.Iterator;

public interface BinaryTreeADT<T> {
   public void removeLeftSubtree();
   public void removeRightSubtree();
   public void removeAllElements();
   public boolean isEmpty();
   public int size();
   public boolean contains (T targetElement);
   public T find (T targetElement);
   public String toString();
   public Iterator<T> iteratorInOrder();
   public Iterator<T> iteratorPreOrder();
   public Iterator<T> iteratorPostOrder();
   public Iterator<T> iteratorLevelOrder();

}