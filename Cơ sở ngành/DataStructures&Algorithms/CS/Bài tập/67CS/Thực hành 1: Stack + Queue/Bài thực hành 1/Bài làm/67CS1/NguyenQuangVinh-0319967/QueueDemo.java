public class QueueDemo 
{
    public static void main(String[] args) throws EmptyCollectionException 
    {
        ArrayQueue<Integer> queue = new ArrayQueue<>();

        for(int i = 0; i < 10; i++) 
        {
            queue.enqueue(i);
        }

        System.out.println(queue.size());
        int size = queue.size();

        for(int i = 0; i < size; i++) 
            System.out.println(queue.dequeue());


        System.out.println(queue.size());
        System.out.println(queue.isEmpty());
    }   
}