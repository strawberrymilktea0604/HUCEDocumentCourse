import exceptions.*;
import java.util.Iterator;

public class BinarySearchTreeList<T> extends ArrayBinarySearchTree<T> implements ListADT<T>, OrderedListADT<T>
{
   public BinarySearchTreeList() 
   {
      super();
   }
public void add (T element)
   {
      addElement(element);
   }
   public T removeFirst ()
   {
      return removeMin();
   }


   public T removeLast ()
   {
      return removeMax();
   }


   public T remove (T element)
   {
      return removeElement(element);
   }


   public T first ()
   {
      return findMin();
   }


   public T last ()
   {
      return findMax();
   }



   public Iterator<T> iterator()
   {
      return iteratorInOrder();
   }



}