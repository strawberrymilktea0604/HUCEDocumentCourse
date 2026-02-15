package BTthuchanh;

public class linkedlist_stack {
    static stacknode root; // tạo một linked list rỗng

    public static class stacknode {
        int value;
        stacknode next;

        stacknode(int x) {
            this.value = x;
        }
    }

    public void push(int value) {
        stacknode newnode = new stacknode(value);
        if (root == null) {
            root = newnode;
        } else {
            stacknode temp = root; // tạo 1 linked list phụ, gán bằng với linked list gốc
            root = newnode; // gán giá trị cần thêm vào cho linked gốc
            newnode.next = temp; // cho phần con trỏ của newnode trỏ vào phần linked list gốc
        }
    }

    public void printstacknode() {
        if (root == null) {
            System.out.println("Stack is empty");
        } else {
            System.out.print("[");
            stacknode temp = root;
            while (temp != null) {
                System.out.print(temp.value);
                temp = temp.next;
                if (temp != null) {
                    System.out.print(", ");
                } else {
                    System.out.println("]");
                }
            }
        }
    }

    public static void main(String[] args) {
        linkedlist_stack stack = new linkedlist_stack();
        stack.push(0);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        stack.printstacknode();
    }
}
