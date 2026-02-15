// Chương trình Java thực hiện hàng chờ bằng mảng

import java.util.*;

class Queue {
    static private int front, rear, capacity;
    static private int queue[];
 
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int[capacity];
    }
 
    // hàm để thêm nguyên tử vào
    // ở phía sau hàng đợi
    static void queueEnqueue(int data)
    {
        // kiểm tra xem hàng đợi đầy hay rỗng
        if (capacity == rear) {
            System.out.printf("\nHang cho da day\n");
            return;
        }
 
        // thêm nguyên tử ở phía sau hàng đợi
        else {
            queue[rear] = data;
            rear++;
        }
        return;
    }
 
    // hàm để xóa nguyên tử
    // ở vị trị phía trước của hàng chờ
    static void queueDequeue()
    {
        // nếu hàng chờ trống
        if (front == rear) {
            System.out.printf("\nHang cho trong rong\n");
            return;
        }
 
        // Chuyển tất cả các nguyên tử từ chỉ số 2 sang phía sau
        // bên phải từng cái một
        else {
            for (int i = 0; i < rear - 1; i++) {
                queue[i] = queue[i + 1];
            }
 
            // Lưu trữ 0 ở phía sau cho biết hàng chờ không có phần tử
            if (rear < capacity)
                queue[rear] = 0;
 
            // giảm nguyên tử ở phía sau
            rear--;
        }
        return;
    }
 
    // in phần tử lên hàng chờ
    static void queueDisplay()
    {
        int i;
        if (front == rear) {
            System.out.printf("\nHang cho trong rong\n");
            return;
        }
 
        // Đi ngang từ phía trước ra phía sau và in các nguyên từ
        for (i = front; i < rear; i++) {
            System.out.printf(" %d <-- ", queue[i]);
        }
        return;
    }
 
    // in vị trí phía trước của hàng chờ
    static void queueFront()
    {
        if (front == rear) {
            System.out.printf("\nHang cho trong rong\n");
            return;
        }
        System.out.printf("\nO vi tri phia truoc cua hang cho ta co so: %d",
                          queue[front]);
        return;
    }
}
 
public class bai31 {
 
    // Chương trình chính
    public static void main(String[] args)
    {

        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap so luong hang cho can dien vao: ");
        int n = sc.nextInt();
        int[] array1 = new int[n];

        Queue q = new Queue(n);

        for(int i = 0; i < array1.length; i++){
            System.out.println("Nhap nguyen tu: ");
            int value = sc.nextInt();              
            q.queueEnqueue(value);
        }

        q.queueEnqueue(70);
        System.out.println("Hang cho chua cac so sau:");
        q.queueDisplay();

        q.queueDequeue();
        q.queueDequeue();
        System.out.println("\nHang cho sau khi xoa nguyen tu la:");


        q.queueDisplay();
        q.queueFront();

    }
}