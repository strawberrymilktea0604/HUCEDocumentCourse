import exceptions.*;

public class LinkedBinarySearchTree<T>  extends LinkedBinaryTree<T> implements BinarySearchTreeADT<T> {

   public LinkedBinarySearchTree() 
   {
      super();
   }
   public LinkedBinarySearchTree (T element) 
   {
      super (element);
   }
   
   
   public void addElement (T element) 
   {

      BinaryTreeNode<T> temp = new BinaryTreeNode<T> (element);
      Comparable<T> comparableElement = (Comparable<T>)element;

      if (isEmpty())
         root = temp;
      else 
      {
         BinaryTreeNode<T> current = root;
         boolean added = false;

         while (!added) 
         {
            if (comparableElement.compareTo(current.element) < 0)

               if (current.left == null) 
               {
                  current.left = temp;
                  added = true;
               } 
               else
                  current = current.left;
            else
               if (current.right == null) 
               {
                  current.right = temp;
                  added = true;
               } 
               else
                  current = current.right;
         }
      }

      count++;

   } 

   public T removeElement (T targetElement) throws
   ElementNotFoundException 
   { 

      T result = null;

      if (!isEmpty())

         if (((Comparable)targetElement).equals(root.element)) 
         {
            result =  root.element;
            root = replacement (root);
            count--;
         } 
        else 
        {
            BinaryTreeNode<T> current, parent = root;
            boolean found = false;

            if (((Comparable)targetElement).compareTo(root.element) < 0)
               current = root.left;
            else
               current = root.right;

            while (current != null && !found) 
            {
               if (targetElement.equals(current.element)) 
               {
                  found = true;
                  count--;
                  result =  current.element;
          
                  if (current == parent.left)
                  {
                     parent.left = replacement (current);
                  }
                  else
                  {
                     parent.right = replacement (current);
                  }
               }
              else 
              {
                  parent = current;
         
                  if (((Comparable)targetElement).compareTo(current.element) < 0)
                     current = current.left;
                  else
                     current = current.right;
               }
            } 
            if (!found)
               throw new ElementNotFoundException("binary tree");
         }

      return result;

   } 

   public void removeAllOccurrences (T targetElement) throws
   ElementNotFoundException 
   {
      removeElement(targetElement);
      
      try
	 {
	   while (contains( (T) targetElement))
          removeElement(targetElement);
	 }
	 catch (Exception ElementNotFoundException)
	 {
	 }
         
   }

   public T removeMin() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         if (root.left == null) 
         {
            result = root.element;
            root = root.right;
         }
         else 
         {
            BinaryTreeNode<T> parent = root;
            BinaryTreeNode<T> current = root.left;
            while (current.left != null) 
            {
               parent = current;
               current = current.left;
            }
            result =  current.element;
            parent.left = current.right;
         }

         count--;
      }
 
      return result;

   }
   
   public T removeMax() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         if (root.right == null) 
         {
            result =  root.element;
            root = root.left;
         }
         else 
         {
              BinaryTreeNode<T> parent = root;
              BinaryTreeNode<T> current = root.right;

              while (current.right != null) 
              {
                 parent = current;
                 current = current.right;
              }

              result =  current.element;
              parent.right = current.left;
           } 

         count--;
      } 

      return result;

   }
   
   public T findMin() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         BinaryTreeNode<T> current = root;
        
         while (current.left != null)
            current = current.left;
       
         result = current.element;
      }

      return result;

   } 


   public T findMax() throws EmptyCollectionException 
   {
      T result = null;

      if (isEmpty())
           throw new EmptyCollectionException ("binary tree");
      else 
      {
         BinaryTreeNode<T> current = root;
      
         while (current.right != null)
            current = current.right;

        result = current.element;
      }
 
      return result;

   } 

   public T find (T targetElement) throws ElementNotFoundException 
   {

	 BinaryTreeNode<T> current = root; 
	 BinaryTreeNode<T> temp = current;

   
      if (!(current.element.equals(targetElement)) && (current.left !=null)&&(((Comparable)current.element).compareTo(targetElement) > 0))
		current = findagain( targetElement, current.left);

      else if (!(current.element.equals(targetElement)) && (current.right != null)) 
		current = findagain( targetElement, current.right); 

      if (!(current.element.equals(targetElement)))
         throw new ElementNotFoundException ("binarytree");

      return current.element;

   } 
   
   private BinaryTreeNode<T> findagain (T targetElement, BinaryTreeNode<T> next) 
   {
	 BinaryTreeNode<T> current = next;
      if (!(next.element.equals(targetElement)) && (next.left !=null) &&(((Comparable)next.element).compareTo(targetElement) > 0))
 		next = findagain( targetElement, next.left); 
	 else if (!(next.element.equals(targetElement)) && (next.right != null))
 		next = findagain( targetElement, next.right);                     
      
	 return next;

   } 
   
   protected BinaryTreeNode<T> replacement (BinaryTreeNode<T> node) 
   {
      BinaryTreeNode<T> result = null;

      if ((node.left == null)&&(node.right==null))
            result = null;
      else if ((node.left != null)&&(node.right==null))
            result = node.left;
      else if ((node.left == null)&&(node.right != null))
            result = node.right;
      else
      {
            BinaryTreeNode<T> current = node.right;
            BinaryTreeNode<T> parent = node;

            while (current.left != null) 
            {
               parent = current;
               current = current.left;
            }

            if (node.right == current)
               current.left = node.left;
            else
            {
               parent.left = current.right;
               current.right = node.right;
               current.left = node.left;
            }
            result = current;
      }
      return result;


   }
}
