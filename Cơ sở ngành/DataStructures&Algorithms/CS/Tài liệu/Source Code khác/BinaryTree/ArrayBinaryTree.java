import java.util.Iterator;
import exceptions.*;

public class ArrayBinaryTree<T> implements BinaryTreeADT<T> 
{

   protected int count;
   protected T[] tree; 
   private final int capacity = 50;


   public ArrayBinaryTree() 
   {
      count = 0;
      tree = (T[]) new Object[capacity];
   }
   
   public ArrayBinaryTree (T element) 
   {
      count = 1;
      tree = (T[]) new Object[capacity];

      tree[0] = element;
   }



   protected void expandCapacity()
   {
      T[] temp = (T[]) new Object[tree.length * 2];
      for (int ct=0; ct < tree.length; ct++)
         temp[ct] = tree[ct];
      tree = temp;
   }
   

   public void removeLeftSubtree() 
   {

   }
   
   public void removeRightSubtree() 
   {
      
   }
   
   public void removeAllElements() 
   {
      count = 0;
      for (int ct=0; ct<tree.length; ct++)      
         tree[ct] = null;
   }
   
   public boolean isEmpty() 
   {
      return (count == 0);
   }
   
   public int size() 
   {
      return count;
   }
   
   public boolean contains (T targetElement) 
   {
      boolean found = false;

      for (int ct=0; ct<count && !found; ct++)
         if (targetElement.equals(tree[ct]))
	       found = true;

      return found;

   }
   
   public T find (T targetElement) throws ElementNotFoundException 
   {
      T temp=null;
	 boolean found = false;

      for (int ct=0; ct<count && !found; ct++)
         if (targetElement.equals(tree[ct]))
         {
	       found = true;
            temp = tree[ct];
         }

      if (!found)
         throw new ElementNotFoundException("binary tree");

      return temp;


   }
   
   public String toString() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      inorder (0, templist);
      return templist.toString();
   }
   
   public Iterator<T> iteratorInOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      inorder (0, templist);
      return templist.iterator();
   }
   
   protected void inorder (int node, ArrayUnorderedList<T> templist) 
   {
      if (node < tree.length)
         if (tree[node] != null) 
 	    {
            inorder ((node+1)*2-1, templist);
            templist.addToRear(tree[node]);
            inorder ((node+1)*(2+1)-1, templist);
         }

   } 
   
   public Iterator<T> iteratorPreOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      preorder (0, templist);
      return templist.iterator();
   }
   
   protected void preorder (int node, ArrayUnorderedList<T> templist) 
   {
      if (node < tree.length)
         if (tree[node] != null) 
 	    { 
            templist.addToRear(tree[node]);
            inorder ((node+1)*2-1, templist);
            inorder ((node+1)*(2+1)-1, templist);
         }

      

   } 
   
   public Iterator<T> iteratorPostOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      postorder (0, templist);
      return templist.iterator();
   }
   
   protected void postorder (int node, ArrayUnorderedList<T> templist) 
   {
      if (node < tree.length)
         if (tree[node] != null) 
 	    {
            inorder ((node+1)*2-1, templist); 
            inorder ((node+1)*(2+1)-1, templist);
            templist.addToRear(tree[node]);
            
         }


   } 
   
   public Iterator<T> iteratorLevelOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      for (int ct=0; ct<count; ct++)
         templist.addToRear(tree[ct]);
      return templist.iterator();
   }
} 
