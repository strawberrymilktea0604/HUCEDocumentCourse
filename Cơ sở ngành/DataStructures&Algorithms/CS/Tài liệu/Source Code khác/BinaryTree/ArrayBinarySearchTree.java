import java.util.Iterator;
import exceptions.*;


public class ArrayBinarySearchTree<T>  extends ArrayBinaryTree<T> implements BinarySearchTreeADT<T> {

   protected int height;
   protected int maxIndex;

   public ArrayBinarySearchTree() 
   {
      super();
      height = 0;
      maxIndex = -1;
   }  

   public ArrayBinarySearchTree (T element) 
   {
      super(element);
      height = 1;
      maxIndex = 0;
   }  

   public void addElement (T element) 
   {

      if (tree.length < maxIndex*2+3)
         expandCapacity();

      Comparable<T> tempelement = (Comparable<T>)element;

      if (isEmpty()) {
         tree[0] = element;
         maxIndex = 0;
      }
      else 
      {
         boolean added = false;
         int currentIndex = 0;

         while (!added) 
         {
            if (tempelement.compareTo((tree[currentIndex]) ) < 0) 
            {
               
               if (tree[currentIndex*2+1] == null) 
               {
                  tree[currentIndex*2+1] = element;
                  added = true;
                  if (currentIndex*2+1 > maxIndex)
                     maxIndex = currentIndex*2+1;
               }
               else
                  currentIndex = currentIndex*2+1;
            }
            else {
               
               if (tree[currentIndex*2+2] == null) 
               {
                  tree[currentIndex*2+2] = element;
                  added = true;
                  if (currentIndex*2+2 > maxIndex)
                     maxIndex = currentIndex*2+2;
               }
               else
                  currentIndex = currentIndex*2+2;
            }
            
         }
      }

      height = (int)(Math.log(maxIndex + 1) / Math.log(2)) + 1;
      count++;

   }


   public T removeElement (T targetElement) throws
   ElementNotFoundException 
   {
      T result = null;
      boolean found = false;

      if (isEmpty())
         return result;

      for (int i = 0; (i <= maxIndex) && !found; i++) {
         if ((tree[i] != null) && targetElement.equals(tree[i])) 
         {
            found = true;
            result = tree[i] ;               
            replace(i);
            count--;
         }
      }

      if (!found)
         throw new ElementNotFoundException("element not found in the binary tree");
      
      int temp = maxIndex;
      maxIndex = -1;
      for (int i = 0; i <= temp; i++)
         if (tree[i] != null)
            maxIndex = i;
      
      height = (int)(Math.log(maxIndex + 1) / Math.log(2)) + 1;
      
      return result;
      
   }


   public T[] getArray()
   {
      T[] temp;
      if (size() == 0) {
         temp = (T[]) new Object[0];
         return temp;
      }

      temp = (T[]) new Object[tree.length];
      for (int i = 0; i < tree.length; i++) {
         if (tree[i] != null)
            temp[i] = tree[i];
         else
            temp[i] = null;
      }
      return temp;
   }


   public int getHeight()
   {
      return height;
   }


   public int getMaxIndex()
   {
      return maxIndex;
   }

   public void removeAllElements() 
   {
      super.removeAllElements();
      height = 0;
      maxIndex = -1;
   }


   public void removeAllOccurrences (T targetElement) throws
   ElementNotFoundException 
   {
        removeElement(targetElement);

	   while (contains(targetElement))
          removeElement(targetElement);

   }


   public T removeMin() throws EmptyCollectionException 
   {

      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         int currentIndex = 1;
         int previousIndex = 0;
         while (tree[currentIndex] != null && currentIndex <= tree.length) 
         {
            previousIndex = currentIndex;
            currentIndex = currentIndex * 2 + 1;
         }
         result = tree[previousIndex] ;
         replace(previousIndex);
      }

      count--;

      return result;
   }

   public T removeMax() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         int currentIndex = 2;
         int previousIndex = 0;
         while (tree[currentIndex] != null && currentIndex <= maxIndex) 
         {
            previousIndex = currentIndex;
            currentIndex = currentIndex * 2 + 2;
         }
         result = tree[previousIndex] ;
         replace(previousIndex);
      } 

      count--;

      return result;
   } 


   public T findMin() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else {
         int currentIndex = 0;
         while ((currentIndex*2+1 <= maxIndex) && (tree[currentIndex*2+1] != null))
            currentIndex = currentIndex*2+1;
         result = tree[currentIndex] ;
      }
      return result;
   }

   public T findMax() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else {
         int currentIndex = 0;
         while ((currentIndex*2+2 <= maxIndex) && (tree[currentIndex*2+2] != null))
            currentIndex = currentIndex*2+2;
         result = tree[currentIndex] ;
      }
      return result;
   }  


   protected void replace (int targetIndex) 
   {
      int currentIndex, parentIndex, temp, oldIndex, newIndex;
      ArrayUnorderedList<Integer> oldlist = new ArrayUnorderedList<Integer>();
      ArrayUnorderedList<Integer> newlist = new ArrayUnorderedList<Integer>();
      ArrayUnorderedList<Integer> templist = new ArrayUnorderedList<Integer>();
      Iterator<Integer> oldIt, newIt;
      
      if ((targetIndex*2+1 >= tree.length) || (targetIndex*2+2 >= tree.length))
         tree[targetIndex] = null;


      else if ((tree[targetIndex*2+1] == null) && (tree[targetIndex*2+2] == null))
         tree[targetIndex] = null;
      

      else if ((tree[targetIndex*2+1] != null) && (tree[targetIndex*2+2] == null)) {


         currentIndex = targetIndex*2+1;
         templist.addToRear(new Integer(currentIndex));
         while (!templist.isEmpty()) {
            currentIndex = ((Integer)templist.removeFirst()).intValue();
            newlist.addToRear(new Integer(currentIndex));
            if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
               templist.addToRear(new Integer(currentIndex*2+1));
               templist.addToRear(new Integer(currentIndex*2+2));
            }
         }
         
         
         currentIndex = targetIndex;
         templist.addToRear(new Integer(currentIndex));
         while (!templist.isEmpty()) {
            currentIndex = ((Integer)templist.removeFirst()).intValue();
            oldlist.addToRear(new Integer(currentIndex));
            if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
               templist.addToRear(new Integer(currentIndex*2+1));
               templist.addToRear(new Integer(currentIndex*2+2));
            }
         }
         
         
         oldIt = oldlist.iterator();
         newIt = newlist.iterator();
         while (newIt.hasNext()) {
            oldIndex = oldIt.next();
            newIndex = newIt.next();
            tree[oldIndex] = tree[newIndex];
            tree[newIndex] = null;
         }         
      }

      
      else if ((tree[targetIndex*2+1] == null) && (tree[targetIndex*2+2] != null)) {

         
         
         
         
         currentIndex = targetIndex*2+2;
         templist.addToRear(new Integer(currentIndex));
         while (!templist.isEmpty()) {
            currentIndex = ((Integer)templist.removeFirst()).intValue();
            newlist.addToRear(new Integer(currentIndex));
            if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
               templist.addToRear(new Integer(currentIndex*2+1));
               templist.addToRear(new Integer(currentIndex*2+2));
            }
         }
         
         
         currentIndex = targetIndex;
         templist.addToRear(new Integer(currentIndex));
         while (!templist.isEmpty()) {
            currentIndex = ((Integer)templist.removeFirst()).intValue();
            oldlist.addToRear(new Integer(currentIndex));
            if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
               templist.addToRear(new Integer(currentIndex*2+1));
               templist.addToRear(new Integer(currentIndex*2+2));
            }
         }
         

         oldIt = oldlist.iterator();
         newIt = newlist.iterator();
         while (newIt.hasNext()) {
            oldIndex = oldIt.next();
            newIndex = newIt.next();
            tree[oldIndex] = tree[newIndex];
            tree[newIndex] = null;
         }         
      }


      else
      {
         currentIndex = targetIndex*2+2;
         
         while (tree[currentIndex*2+1] != null) {
            currentIndex = currentIndex*2+1;
         }
         
         tree[targetIndex] = tree[currentIndex];

 
         int currentRoot = currentIndex;  
         

         if (tree[currentRoot*2+2] != null) {


            currentIndex = currentRoot*2+2;
            templist.addToRear(new Integer(currentIndex));
            while (!templist.isEmpty()) {
               currentIndex = ((Integer)templist.removeFirst()).intValue();
               newlist.addToRear(new Integer(currentIndex));
               if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
                  templist.addToRear(new Integer(currentIndex*2+1));
                  templist.addToRear(new Integer(currentIndex*2+2));
               }
            }
               
            
            currentIndex = currentRoot;
            templist.addToRear(new Integer(currentIndex));
            while (!templist.isEmpty()) {
               currentIndex = ((Integer)templist.removeFirst()).intValue();
               oldlist.addToRear(new Integer(currentIndex));
               if ((currentIndex*2+2) <= (Math.pow(2,height)-2)) {
                  templist.addToRear(new Integer(currentIndex*2+1));
                  templist.addToRear(new Integer(currentIndex*2+2));
               }
            }
         
            
            oldIt = oldlist.iterator();
            newIt = newlist.iterator();
            while (newIt.hasNext()) {
               oldIndex = oldIt.next();
               newIndex = newIt.next();
               tree[oldIndex] = tree[newIndex];
               tree[newIndex] = null;
            }               
         }
         else
            tree[currentRoot] = null;
      }

   }

   public String toString() throws EmptyCollectionException 
   {
      String result = "";

      for (int i = 0; i <= maxIndex; i++)
         if (tree[i] != null)
            result += tree[i] .toString() + "\n";
      
      return result;
   } 

   public String toString2() throws EmptyCollectionException 
   {
      String result = "";
      int counter = 1;
      int level = 1;
      int index = 1;

      if (isEmpty())
         return result;
      
      for (int i = 0; i < Math.pow(2, height-level)-1; i++)
         result += " ";
      result += tree[0] .toString();
      
      while (index <= maxIndex) {
         if (index == counter) {
            counter = counter*2 + 1;
            level++;
            result += "\n";
            for (int i = 0; i < Math.pow(2, height-level)-1; i++)
               result += " ";
         }
         if (tree[index] != null)
            result += tree[index] .toString();
         else
            result += " ";
         for (int i = 0; i < Math.pow(2, height-level+1)-1; i++)
            result += " ";
         index++;
      }
      
      return result;
   } 

} 
