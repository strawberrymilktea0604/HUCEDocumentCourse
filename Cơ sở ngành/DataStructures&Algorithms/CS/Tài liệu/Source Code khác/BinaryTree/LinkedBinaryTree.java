import java.util.Iterator;
import exceptions.*;

public class LinkedBinaryTree<T> implements BinaryTreeADT<T> 
{

   protected int count;
   protected BinaryTreeNode<T> root; 

   public LinkedBinaryTree() 
   {
      count = 0;
      root = null;
   }

   public LinkedBinaryTree (T element) 
   {
      count = 1;
      root = new BinaryTreeNode<T> (element);
   }
   
   public LinkedBinaryTree (T element, LinkedBinaryTree<T> leftSubtree,
                                 LinkedBinaryTree<T> rightSubtree) 
   {

	 root = new BinaryTreeNode<T> (element);
	 count = 1;
	 if (leftSubtree != null)
	 {
		count = count + leftSubtree.size();
		root.left = leftSubtree.root;
	 }
	 else
		root.left = null;
	 if (rightSubtree !=null)
	 {
		count = count + rightSubtree.size(); 
	 	root.right = rightSubtree.root;
	 }
	 else
		root.right = null;
 
   } 
   public void removeLeftSubtree() 
   {
      if (root.left != null)
		count = count - root.left.numChildren() - 1;
      root.left = null;
   }

   public void removeRightSubtree() 
   {
      if (root.right != null)
		count = count - root.right.numChildren() - 1; 
      root.right = null;
   }

   public void removeAllElements() 
   {
      count = 0;
      root = null;
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

      T temp;
      boolean found = false;

      try 
	 {
         temp = find (targetElement);
         found = true;
      }
  
      catch (Exception ElementNotFoundException) 
	 {
         found = false;
      }

      return found;

   }


   public T find(T targetElement) throws ElementNotFoundException {
     BinaryTreeNode<T> current = findagain( targetElement, root );
     if( current == null )
       throw new ElementNotFoundException("binarytree");
     return (current.element);
   }
   
   private BinaryTreeNode<T> findagain(T targetElement, BinaryTreeNode<T> next) {
     if (next == null) {
       return null;
     }
     if (next.element.equals(targetElement)) {
       return next;
     }
     BinaryTreeNode<T> temp = findagain(targetElement, next.left);
     if (temp == null) {
       temp = findagain(targetElement, next.right);
     }
     return temp;
   }
   
   public String toString() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      preorder (root, templist);
      return templist.toString();
   }
   
   public Iterator<T> iteratorInOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      inorder (root, templist);
      return templist.iterator();
   }
   
   protected void inorder (BinaryTreeNode<T> node, ArrayUnorderedList<T> templist) 
   {

      if (node != null) 
 	 {
         inorder (node.left, templist);
         templist.addToRear(node.element);
         inorder (node.right, templist);
      }

   }
   
   public Iterator<T> iteratorPreOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      preorder (root, templist);
      return templist.iterator();
   }
   
   protected void preorder (BinaryTreeNode<T> node, ArrayUnorderedList<T> templist) 
   {

      if (node != null) 
	 {
         templist.addToRear(node.element);
         preorder (node.left, templist);
         preorder (node.right, templist);
      }

   }
   
   public Iterator<T> iteratorPostOrder() 
   {
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      postorder (root, templist);
      return templist.iterator();
   }
   
   protected void postorder (BinaryTreeNode<T> node, ArrayUnorderedList<T> templist) 
   {

      if (node != null) 
	 {
         postorder (node.left, templist);
         postorder (node.right, templist);
         templist.addToRear(node.element);
      }

   }
   
   public Iterator<T> iteratorLevelOrder() 
   {

      ArrayUnorderedList<T> nodes = new ArrayUnorderedList<T>();
      ArrayUnorderedList<T> templist = new ArrayUnorderedList<T>();
      BinaryTreeNode<T> current;

      nodes.addToRear (root.element);

      while (! nodes.isEmpty()) 
	 {
         current = (BinaryTreeNode<T>)nodes.removeFirst();

         if (current != null) 
	    {
            templist.addToRear(current.element);
            nodes.addToRear (current.left.element);
            nodes.addToRear (current.right.element);
         }
         else
            templist.addToRear(null);
      }
      return templist.iterator();
   } 
} 
