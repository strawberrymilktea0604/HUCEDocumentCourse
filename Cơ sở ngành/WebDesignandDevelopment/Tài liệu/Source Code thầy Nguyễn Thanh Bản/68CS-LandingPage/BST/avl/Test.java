package avl;

public class Test {
    public static void main(String[] args) {
        MyBST myBST = new MyBST();
        myBST.insertNode(44);
        myBST.insertNode(17);
        myBST.insertNode(78);
        myBST.insertNode(32);
        myBST.insertNode(50);
        myBST.insertNode(88);
        myBST.insertNode(48);
        myBST.insertNode(62);
        System.out.println("Cay truoc khi bi them node 54: ");
        myBST.inOrder();
        myBST.insertNode(54);
        System.out.println("Cay sau khi them node 54: ");
        myBST.inOrder();
    }
}
