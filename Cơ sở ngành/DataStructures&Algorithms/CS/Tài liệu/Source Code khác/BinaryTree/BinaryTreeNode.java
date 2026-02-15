public class BinaryTreeNode<T> {

   protected T element;
   protected BinaryTreeNode<T> left, right;


   BinaryTreeNode (T obj) 
   {
      element = obj;
      left = null;
      right = null;
   }
   public int numChildren() 
   {

      int children = 0;

      if (left != null)
         children = 1 + left.numChildren();

      if (right != null)
         children = children + 1 + right.numChildren();

      return children;

   }  
   
}  