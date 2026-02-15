//chương trình Java cài đặt Stack bằng danh sách liên kết


import java.util.*;

/**
 *Trong trường hợp danh sách liên kết đơn trống
 */

class LinkedListEmptyException extends RuntimeException{
    public LinkedListEmptyException(){
        super();
    }
    
    public LinkedListEmptyException(String message){
        super(message);
    }  
}

/**
 *Trong trường hợp ngăn xếp trống
 */

class StackEmptyException extends RuntimeException {
 
    public StackEmptyException(){
        super();
    }

    public StackEmptyException(String message){
        super(message);
    }
}

/**
 *Tạo lớp vị trí vào
 */
class Node {
    public int data; // dữ liệu tại vị trí đó.
    public Node next; // vị trí tiếp theo trong danh sách.

    /**
     * Cấu trúc
     */
    public Node(int data){
        this.data = data;
    }

    /**
     * Hiển thị
     */
    public void displayNode() {
        System.out.print( data + " ");
    }
}


/**
 * Lớp LinkedList
 */
class LinkedList {
    private Node first; // Tham chiếu đến danh sách đầu tiên trong danh sách

    /**
     * Cấu trúc danh sách
     */
    public LinkedList(){
        first = null;
    }

    /**
     * Chèn vị trí  đầu tiên
     */
    public void insertFirst(int data) {
        Node newNode = new Node(data);  //Tạo vị trí mới.
        newNode.next = first;   //newLink ---> vị trí thứ nhất cũ
        first = newNode;    //đầu tiên ---> newNode
    }

    /**
     * Xóa dữ liệu ở vị trí đầu tiên
     */
    
    public Node deleteFirst()
    {
        if(first==null){    //Khi danh sách liên kết đơn trống?               
            throw new LinkedListEmptyException("Danh sach lien ket don khong co du lieu");
        }
        Node tempNode = first; // lưu tham chiếu đến vị trí đầu tiên, từ đó ta quay lại trả về vị trí tham chiếu đã lưu 
        first = first.next; // xóa dữ liệu đầu tiên (khi đó ta sẽ tạo vị trí đầu tiên ngay bên cạnh)
        return tempNode; // trả về giá trị tempNode (vị trí đó đã bị xóa!)
    }

        
    /**
     * Hiển thị LinkedList
     */
    public void displayLinkedList() {
        Node tempDisplay = first; // bắt đầu ở đầu danh sách liên kết
        while (tempDisplay != null){ // Thực thi cho đến khi nào không tìm thấy kết thúc danh sách.
            tempDisplay.displayNode();
            tempDisplay = tempDisplay.next; // chuyển sang vị trí thứ 2
        }
        System.out.println();   
    }
}


/**
 * Bắt đầu thực hiện ngăn xếp bằng danh sách liên kết. Lớp StackLinkedList dùng để tham chiếu danh sách liên kết đơn
 */

class StackLinkedList{

    LinkedList linkedList = new LinkedList(); // tạo danh sách

    /**
     * Thêm dữ liệu ở Stack, xếp thứ tự từ cao xuống thấp.
     */
    public void push(int value){
        linkedList.insertFirst(value);
    }

    /**
     * Xóa dữ liệu ngăn xếp, khuyết vị trí nào, đẩy vị trí dưới lên.
     */
    public void pop() throws StackEmptyException {
        try{
            linkedList.deleteFirst();
        }catch(LinkedListEmptyException llee){
            throw new StackEmptyException("Stack trong!");
        }
    }

    /**
     * Hiển thị stack.
     */
    public void displayStack() {
        linkedList.displayLinkedList();
    }
}


/**
 * Chương trình chính.
 */
public class bai2 {
    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            StackLinkedList stackLinkedList=new StackLinkedList();


            System.out.print("Nhap so luong ngan xep: ");
  
            int number1 = sc.nextInt();
            int[] array1 = new int[number1];

            for(int i = 0; i < array1.length; i++){
                System.out.println("Nhap nguyen tu: ");
                int value = sc.nextInt();              
                stackLinkedList.push(value);
            }

            System.out.print("Danh sach ngan xep: ");

            stackLinkedList.displayStack();

            stackLinkedList.pop();
            stackLinkedList.pop();

            System.out.print("Danh sach ngan xep sau khi lay ra: ");

            stackLinkedList.displayStack();
        }


    }
}