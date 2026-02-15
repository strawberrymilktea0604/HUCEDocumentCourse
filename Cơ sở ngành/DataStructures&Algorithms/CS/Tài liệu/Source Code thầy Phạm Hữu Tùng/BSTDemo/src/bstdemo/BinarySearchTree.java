package bstdemo;
class BinarySearchTree {
        private Node root;
        
        public BinarySearchTree() {
        root = null;
        }
        public Node getRoot() { 
            return root;
        }
        
        // inorder
        public void inorder(Node node) {
            if (node == null) return;
            inorder(node.left);
            System.out.print(node.key + " ");
            inorder(node.right);
        }
        // Preorder
        public void preorder(Node node) {
        if (node == null) return;
        System.out.print(node.key + " ");
        preorder(node.left);
        preorder(node.right);
    }
        // Postorder
        public void postorder(Node node) {
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        System.out.print(node.key + " ");
        }
        //insert
        public void insertRecursive(int key) {
            root = insertRecursive(root, key);
        }
        private Node insertRecursive(Node node, int key) {
            if (node == null) return new Node(key);
            if (key < node.key) 
                node.left = insertRecursive(node.left, key);
            else if (key > node.key) 
                node.right = insertRecursive(node.right, key);
            return node;
        }
        //delete
        public void delete(int key) {
        root = deleteNode(root, key);
        }

        private Node deleteNode(Node node, int key) {
            if (node == null) return null;
            if (key < node.key) {
                node.left = deleteNode(node.left, key);
            } else if (key > node.key) {
                node.right = deleteNode(node.right, key);
            } else {
                // Node cần xóa
                if (node.left == null) return node.right;
                if (node.right == null) return node.left;

                // Node có 2 con: tìm inorder successor
                Node temp = node.right;
                while (temp.left != null) temp = temp.left;
                node.key = temp.key;
                node.right = deleteNode(node.right, temp.key);
            }
            return node;
        }

        // --- Search ---
        public boolean search(int key) {
            Node current = root;
            while (current != null) {
                if (key == current.key) return true;
                current = key < current.key ? current.left : current.right;
            }
            return false;
        }
        
        
        
    }