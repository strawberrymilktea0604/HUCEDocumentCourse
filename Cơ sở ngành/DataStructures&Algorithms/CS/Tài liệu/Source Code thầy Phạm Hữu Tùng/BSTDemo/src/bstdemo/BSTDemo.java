package bstdemo;
public class BSTDemo {
    public static void main(String[] args) {
         BinarySearchTree bst = new BinarySearchTree();
        // Insert
        int[] values = {50, 30, 70, 20, 40, 60, 80};
        for (int v : values) 
            bst.insertRecursive(v);
        // Duyệt cây
        System.out.print("Inorder: ");   
        bst.inorder(bst.getRoot());  
        System.out.println();
        System.out.print("Preorder: ");  
        bst.preorder(bst.getRoot()); 
        System.out.println();
        System.out.print("Postorder: "); 
        bst.postorder(bst.getRoot());
        System.out.println();

        // Test search
        System.out.println("Search 40 → " + bst.search(40));  // true
        System.out.println("Search 90 → " + bst.search(90));  // false    
        
        //Delete Test
        System.out.println("\nDelete 20");
        bst.delete(20);
        System.out.print("Inorder: ");
        bst.inorder(bst.getRoot());

        System.out.println("\nDelete 30");
        bst.delete(30);
        System.out.print("Inorder: ");
        bst.inorder(bst.getRoot());

        System.out.println("\nDelete 50");
        bst.delete(50);
        System.out.print("Inorder: ");
        bst.inorder(bst.getRoot());
    }   
}
