public class Demo{
    public static void main(String[] args) {
        ArrayQueue<Integer> queue = new ArrayQueue<>();
        for (int i = 0; i < 30; i++){
            queue.enqueue(i);
        }
    }
}