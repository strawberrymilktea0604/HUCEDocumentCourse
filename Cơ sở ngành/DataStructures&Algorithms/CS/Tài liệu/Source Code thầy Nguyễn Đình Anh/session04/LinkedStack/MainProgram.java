public class MainProgram {
    public static void main(String[] args) {
        LinkedStack<String> stack = new LinkedStack<String>();
        stack.push("A");
        stack.push("B");
        stack.push("C");

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());


        LinkedQueue<String> queue = new LinkedQueue<String>();

        queue.enqueue("A");
        queue.enqueue("B");
        queue.enqueue("C");

        System.out.println(queue.dequeue());        
        System.out.println(queue.dequeue());                
        System.out.println(queue.dequeue());        
    }
}