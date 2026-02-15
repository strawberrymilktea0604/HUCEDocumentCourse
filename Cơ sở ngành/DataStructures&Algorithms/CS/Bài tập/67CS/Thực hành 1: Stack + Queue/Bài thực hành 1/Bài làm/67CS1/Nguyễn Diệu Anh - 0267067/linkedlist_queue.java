package BTthuchanh;

public class linkedlist_queue {
    queuenode root;

    public static class queuenode {
        int value;
        queuenode next;

        queuenode(int x) {
            this.value = x;
        }
    }

    public void push(int value) {
        queuenode newnode = new queuenode(value);
        if (root == null) {
            root = newnode;
        } else {
            queuenode temp = root;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newnode;
        }
    }

    public void printstacknode() {
        if (root == null) {
            System.out.println("Stack is empty");
        } else {
            System.out.print("[");
            queuenode temp = root;
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
        linkedlist_queue queue = new linkedlist_queue();
        queue.push(0);
        queue.push(1);
        queue.push(2);
        queue.push(3);

        queue.printstacknode();
    }
}
