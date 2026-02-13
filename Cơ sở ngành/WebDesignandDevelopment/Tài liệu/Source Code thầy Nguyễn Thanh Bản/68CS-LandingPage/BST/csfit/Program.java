package csfit;

import java.util.ArrayList;

public class Program {
    public static void main(String[] args) {
        MyBST myBST = new MyBST();
        myBST.insertNode(8);
        myBST.insertNode(3);
        myBST.insertNode(10);
        myBST.insertNode(1);
        myBST.insertNode(6);
        myBST.insertNode(4);
        myBST.insertNode(7);
        myBST.insertNode(14);
        myBST.insertNode(13);

//        System.out.println("Tim so 13: "+myBST.searchNode(13));
//        System.out.println("Cay truoc khi xoa");
//        myBST.inOrder();
//        myBST.deleteNode(3);
//        System.out.println();
//        System.out.println("Cay sau khi xoa node 4");
//        myBST.inOrder();
//        myBST.traversalBreadthFirst();
//        System.out.println("Max depth of the tree: "+ myBST.maxDepth());
//        System.out.println("Traversal tree using Breadth first search:");
//        myBST.breadthFirstSearch();
        System.out.println("Max depth: "+myBST.maxDepth());

    }

}
