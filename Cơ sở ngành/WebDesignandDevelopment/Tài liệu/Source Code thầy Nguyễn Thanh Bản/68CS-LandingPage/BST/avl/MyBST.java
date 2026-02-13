package avl;

public class MyBST {
    public MyNode root;

    public MyBST() {
        root = null;
    }


    //function return height of node
    private int height(MyNode node) {
        if (node == null) {
            return -1;
        } else {
            return node.height;
        }
    }

    //update height of node
    private void updateHeight(MyNode node) {
        node.height = Math.max(height(node.left), height(node.right)) + 1;
    }

    //get balance of node
    private int getBalance(MyNode node) {
        if (node == null) {
            return 0;
        } else {
            return height(node.right) - height(node.left);
        }
    }

    //insert new node into the BST
    public void insertNode(int value) {
        root = _insertNode(root, value);
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
        return reBalance(root);
    }

    private MyNode reBalance(MyNode node) {
        updateHeight(node);
        //get balance factor
        int balance = getBalance(node);
        if (balance > 1) {//lech phai
            //xac dinh xem cay lech ve ben phai
            //neu lech hoan toan ben phair ->>xoay trai cay
            if (height(node.right.right) > height(node.right.left)) {
                //hoan toan lech phai
                //xoay trai.
                node = _rotateLeft(node);
            } else {
                //xoay phai
                node.right = _rotateRight(node.right);

                //xoay trai
                node = _rotateLeft(node);
            }
            //hay bi lech ve ben trai->xoay phai->xoay trai


        } else if (balance < -1) {//lech trai
            if (height(node.left.left) > height(node.left.right)) {
                //xoay phai
                node = _rotateRight(node);
            } else {
                //xoay trai (cho node 50 theo vi du)
                    node.left = _rotateLeft(node.left);

                //xoay phai.
                node = _rotateRight(node);
            }
        }
        return node;
    }

    //Rotate left
    private MyNode _rotateLeft(MyNode y) {
        MyNode x = y.right;
        MyNode z = x.left;
        x.left = y;
        y.right = z;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    //Rotate right
    private MyNode _rotateRight(MyNode y) {
        MyNode x = y.left;
        MyNode z = x.right;
        x.right = y;
        y.left = z;
        updateHeight(y);
        updateHeight(x);
        return x;
    }


    //traversal tree using in-order
    public void inOrder() {
        _inOrder(root);
    }

    private void _inOrder(MyNode current) {
        if (current != null) {
            _inOrder(current.left);
            System.out.print(current.value + " ");
            _inOrder(current.right);
        }
    }

}









