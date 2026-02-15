public class MyArrQueue implements IStackAndQueue {
    private int [] arr;
    private int SIZE;
    private int head;
    private int tail;
    public MyArrQueue(int size) {
       arr = new int[size];
       SIZE = size;
       head = tail = -1;
    }
    @Override
    public boolean push(int value) {
        if(!isFull()) {
            if(isEmpty()) {
                head++;
            }
            tail++;
            arr[tail] = value;
            return true;
        }
        return false;
    }
    @Override
    public int pop() {
        int value = -1;
        if(!isEmpty()) {
            value = arr[head];
            head++;
            if(head > tail) {
                head = tail = -1;
            }
        }
        return value;
    }

    @Override
    public boolean isFull() {
        return tail == SIZE - 1;
    }

    @Override
    public boolean isEmpty() {
        return (head == -1 ) && (tail == -1);
    }

    public int count() {
        if(isEmpty()) 
            return 0;
        return tail - head + 1;
    }
    @Override
    public void show() {
        if(isEmpty()) {
            System.out.println("Queue is Empty!");
        }else {
            for (int i = head; i <= tail; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }
}
