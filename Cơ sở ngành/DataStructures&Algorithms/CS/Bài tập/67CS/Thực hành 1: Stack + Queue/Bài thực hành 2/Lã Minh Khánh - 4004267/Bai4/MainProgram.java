public class MainProgram {
    public static void main(String[] args) {


        LinkedQueue<String> queue = new LinkedQueue<String>();

        queue.enqueue("A");
        queue.enqueue("B");
        queue.enqueue("C");

        System.out.println(queue.dequeue());        
        System.out.println(queue.dequeue());                
        System.out.println(queue.dequeue());
        
        

        ArrayQueue<String> aqueue = new ArrayQueue<String>();
        aqueue.enqueue("D");
        aqueue.enqueue("T");
        aqueue.enqueue("A");

        System.out.println(aqueue.dequeue());        
        System.out.println(aqueue.dequeue());                
        System.out.println(aqueue.dequeue());

    }
}