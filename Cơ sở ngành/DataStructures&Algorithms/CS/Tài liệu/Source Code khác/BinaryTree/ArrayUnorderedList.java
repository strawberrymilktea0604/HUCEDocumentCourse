import exceptions.*;

public class ArrayUnorderedList<T> extends ArrayList<T> implements UnorderedListADT<T>
{
   public ArrayUnorderedList()
   {
      super();
   }

   public ArrayUnorderedList (int initialCapacity)
   {
      super(initialCapacity);
   }

   
   public void addToFront (T element)
   {
      if (size() == list.length)
         expandCapacity();

      for (int scan=rear; scan > 0; scan--)
         list[scan] = list[scan-1];

      list[0] = element;
      rear++;
   }

   
   public void addToRear (T element)
   {
      if (size() == list.length)
         expandCapacity();

      list[rear] = element;
      rear++;
   }

   public void addAfter (T element, T target)
   {
      if (size() == list.length)
         expandCapacity();

      int scan = 0;
      while (scan < rear && !target.equals(list[scan])) 
          scan++;
      
      if (scan == rear)
         throw new ElementNotFoundException ("list");
    
      scan++;
      for (int scan2=rear; scan2 > scan; scan2--)
         list[scan2] = list[scan2-1];

      list[scan] = element;
      rear++;
   }
}
