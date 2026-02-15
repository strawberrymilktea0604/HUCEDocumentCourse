import exceptions.*;
import java.util.Iterator;

public class ArrayList<T> implements ListADT<T>
{
   protected final int DEFAULT_CAPACITY = 100;
   private final int NOT_FOUND = -1;
   protected int rear;
   protected T[] list; 


   public ArrayList()
   {
      rear = 0;
      list = (T[])(new Object[DEFAULT_CAPACITY]);
   }


   public ArrayList (int initialCapacity)
   {
      rear = 0;
      list = (T[])(new Object[initialCapacity]);
   }


   public T removeLast () throws EmptyCollectionException
   {
      T result;

      if (isEmpty())
         throw new EmptyCollectionException ("list");

      rear--;
      result = list[rear];
      list[rear] = null;

      return result;
   }


   public T removeFirst() throws EmptyCollectionException
   {
      if (isEmpty())
         throw new EmptyCollectionException ("list");

      T result = list[0];
      rear--;

      for (int scan=0; scan < rear; scan++)
         list[scan] = list[scan+1];

 
      list[rear] = null;
 
      return result;
   }


   public T remove (T element)
   {
      T result;
      int index = find (element);

      if (index == NOT_FOUND)
         throw new ElementNotFoundException ("list");

      result = list[index];
      rear--;
      for (int scan=index; scan < rear; scan++)
         list[scan] = list[scan+1];

 
      list[rear] = null;

      return result;
   }

   

   public T first() throws EmptyCollectionException
   {
      if (isEmpty())
         throw new EmptyCollectionException ("list"); 

      return list[0];
   }


   public T last() throws EmptyCollectionException
   {
      if (isEmpty())
         throw new EmptyCollectionException ("list"); 

      return list[rear-1];
   }


   public boolean contains (T target)
   {
      return (find(target) != NOT_FOUND);
   }


   private int find (T target)
   {
      int scan = 0, result = NOT_FOUND;
      boolean found = false;

      if (! isEmpty())
         while (! found && scan < rear)
            if (target.equals(list[scan]))
               found = true;
            else
               scan++;

      if (found)
         result = scan;

      return result;
   }


   public boolean isEmpty()
   {
      return (rear == 0);
   }
 

   public int size()
   {
      return rear;
   }


   public Iterator<T> iterator()
   {
      return new ArrayIterator<T> (list, rear);
   }

   public String toString()
   {
      String result = "";

      for (int scan=0; scan < rear; scan++) 
         result = result + list[scan].toString() + "\n";

      return result;
   }


   protected void expandCapacity()
   {
      T[] larger = (T[])(new Object[list.length*2]);

      for (int scan=0; scan < list.length; scan++)
         larger[scan] = list[scan];

      list = larger;
   }
}


