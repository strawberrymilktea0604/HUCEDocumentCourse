// Chương trình Java thiết lập hàng chờ bằng danh sách liên kết đơn 
  
// Vị trí danh sách được nối kết để lưu trữ mục nhập hàng chờ

import java.util.Scanner;

class QNode { 
    int key; 
    QNode next; 
  
    // cấu trúc để tạo ra một vị trí danh sách mới
    public QNode(int key) 
    { 
        this.key = key; 
        this.next = null; 
    } 
} 
  
// Một lớp để đại diện cho một hàng đợi 
// Hàng đợi, phía trước vị trí lưu trữ phía trước của danh sách và phía sau 
// Vị trí cuối cùng của danh sách 
class Queue { 
    QNode front, rear; 
  
    public Queue() 
    { 
        this.front = this.rear = null; 
    } 
  
    // Thêm nguyên tử vào hàng chờ. 
    void enqueue(int key) 
    { 
  
        // Tạo ra 1 vị trí danh sách mới 
        QNode temp = new QNode(key); 
  
        // Nếu hàng chờ trống, sau đấy 1 vị trí sẽ xuất hiện ở cả phía trước lẫn phía sau 
        if (this.rear == null) { 
            this.front = this.rear = temp; 
            return; 
        } 
  
        // Thêm vị trí cuối cùng vào phần cuối của hàng chờ và thay đổu giá trị phía sau 
        this.rear.next = temp; 
        this.rear = temp; 
    } 
  
    // Xóa nguyên tử khỏi hàng chờ. 
    void dequeue() 
    { 
        // Nếu hàng chờ trống, trả về số 0. 
        if (this.front == null) 
            return; 
  
        // Lưu trữ giá trị phía trước trước đó và di chuyển về phía trước một vị trí đằng trước 
        QNode temp = this.front; 
        this.front = this.front.next; 
  
        // Nếu giá trị phía trước = 0, thì phía sau giá trị cũng là 0
        if (this.front == null) 
            this.rear = null; 
    }
} 
  
// Chương trình chính 
public class bai32 { 
    public static void main(String[] args) 
    { 
        Queue q = new Queue();


        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Nhap so luong hang cho: ");
  
            int number1 = sc.nextInt();
            int[] array1 = new int[number1];

                for(int i = 0; i < array1.length; i++){
                    System.out.println("Nhap nguyen tu: ");
                    int value = sc.nextInt();              
                    q.enqueue(value);
                }
        }


        q.enqueue(70);
        q.dequeue();
        q.dequeue(); 


        System.out.println("Vi tri phia truoc hang cho cho la con so: " + q.front.key); 
        System.out.println("Vi tri phia sau hang cho cho la con so: " + q.rear.key); 
    } 
} 
