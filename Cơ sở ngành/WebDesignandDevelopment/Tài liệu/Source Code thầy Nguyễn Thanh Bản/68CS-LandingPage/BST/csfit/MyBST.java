package csfit;

import org.example.Node;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MyBST {
    public MyNode root;

    public MyBST() {
        root = null;
    }

    //insert new node into the BST
    public void insertNode(int value) {
        root = _insertNodeUsingLoop(root, value);
    }

    private MyNode _insertNode(MyNode root, int value) {
        if (root == null) {
            return new MyNode(value);
        }
        //cay da ton tai node root
        if (value < root.value) {
            //chen node moi vao cay con ben trai
            root.left = _insertNode(root.left, value);
        }
        if (value > root.value) {
            root.right = _insertNode(root.right, value);
        }
        return root;
    }

    //insert a newnode into the root of the tree
    private MyNode _insertNodeUsingLoop(MyNode root, int value) {
        MyNode newNode = new MyNode(value);
        if (root == null) {
            return newNode;
        } else {
            MyNode temp = root;
            while (true) {
                if (value < temp.value) {
                    if (temp.left == null) {
                        temp.left = newNode;
                        break;
                    } else {
                        temp = temp.left;
                    }
                } else {
                    if (temp.right == null) {
                        temp.right = newNode;
                        break;
                    } else {
                        temp = temp.right;
                    }
                }
            }
        }
        return root;
    }

    public boolean searchNode(int value) {
        //Tim kiem xem 1 node nao do co ton tai trong cay hay khong
        return _searchNode(root, value);
    }

    private boolean _searchNode(MyNode current, int value) {
        if (current == null) {
            return false;
        }
        if (value == current.value) {
            return true;
        } else if (value < current.value) {
            return _searchNode(current.left, value);
        } else {
            return _searchNode(current.right, value);
        }
    }

    //traversal tree using in-order
    public void inOrder(){
        _inOrderWithoutRecursion(root);
    }
    private void _inOrder(MyNode current){
        if(current!=null){
            _inOrder(current.left);
            System.out.print(current.value + " ");
            _inOrder(current.right);
        }
    }
    private void _inOrderWithoutRecursion(MyNode root){
        //khai bao stack de luu cac node da duyet qua
        Stack<MyNode> stack = new Stack<>();
        MyNode current  = root;
        while(current != null || !stack.isEmpty()){
            //code here
            while (current!=null){
                stack.push(current);
                current = current.left;
            }
            MyNode top = stack.pop();
            System.out.print(top.value+" ");
            current = top.right;
        }
    }
    //BTVN
    //pre-order; post-order; delete node???
    //delete a node
    //hanh dong xoa:
    //tra ve mot tree moi, sau khi bo node do ra khoi cay
    public void deleteNode(int value){
       root = _deleteNode(root, value);
    }
    private MyNode _deleteNode(MyNode current, int value){
        //code
        if(current == null){
            return null;
        }
        if(value < current.value){
          current.left = _deleteNode(current.left,value);
          return  current;
        }else if(value>current.value){
            current.right=_deleteNode(current.right,value);
            return current;
        }else{
            //tim duoc node can xoa
            //value == current.value
            //TH1. Node can xoa la chinh node la
            if(current.left==null && current.right==null){
                return null;
            }
            //TH2: Node can xoa co cay con trai hoac cay con phai.
            if(current.right==null){
                return current.left;
            }
            if(current.left==null){
                return current.right;
            }
            //TH3. Node can xoa co ca cay con trai va phaix
            //B1. Tim node trai cung cay con phai
            MyNode smallestNode = _findSmallestNode(current.right);
            //B2. Thay node can xoa bang node trai cung
            current.value = smallestNode.value;
            //B3. Xoa xoa node trai cung di.
            current.right = _deleteNode(current.right, smallestNode.value);
            return current;
        }
    }
    private MyNode _findSmallestNode(MyNode node){
        if(node.left==null){
            return node;
        }else{
            return _findSmallestNode(node.left);
        }
    }
//traversal breadth first search
    public void breadthFirstSearch(){
        if(root!=null){
            //khai bao hang doi
            Queue<MyNode> listNodes = new LinkedList<>();
            listNodes.add(root);
            while (!listNodes.isEmpty()){
                MyNode current = listNodes.remove();
                System.out.print(current.value+" ");
                if(current.left!=null){
                    listNodes.add(current.left);
                }
                if(current.right!=null){
                    listNodes.add(current.right);
                }
            }
        }
    }
    //get max depth
    public int maxDepth(){
        return _maxDepth(root);
    }
    private int _maxDepth(MyNode current){
        if(current==null){
            return -1;
        }else{
            int leftDepth = _maxDepth(current.left);
            int rightDepth = _maxDepth(current.right);
            if(leftDepth>rightDepth){
                return leftDepth+1;
            }else{
                return rightDepth+1;
            }
        }
    }








}









