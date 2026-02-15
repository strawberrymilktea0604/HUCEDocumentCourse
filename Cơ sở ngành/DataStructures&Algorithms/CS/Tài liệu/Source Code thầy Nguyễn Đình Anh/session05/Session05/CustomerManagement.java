public class CustomerManagement {
    public static void main(String[] agrs)
    {

        Customer[] list = new Customer[5];
        list[0] = new Customer("Quang", 20);
        list[1] = new Customer("Bao",25);
        list[2] = new Customer("Anh",15);
        list[3] = new Customer("Bao",19);
        list[4] = new Customer("Quan", 25);
        
        Customer aCustomer = new Customer("Quan",25);

        System.out.println("Tim kiem tuyen tinh:");
        if (Searching.linearSearch(list, 0, list.length-1, aCustomer))
            System.out.println("Khach hang da ton tai trong CSDL");
        else
            System.out.println("Day la khach hang moi");

        System.out.println("------------------------------");
        System.out.println("Tim kiem nhi phan:");         
        Customer[] list2 = new Customer[5];
        list2[0] = new Customer("Anh", 15);
        list2[1] = new Customer("Bao",19);
        list2[2] = new Customer("Bao",25);
        list2[3] = new Customer("Quan",25);
        list2[4] = new Customer("Quang", 20);

        if (Searching.binarySearch(list2, 0, list.length-1, aCustomer))
            System.out.println("Khach hang da ton tai trong CSDL");
        else
            System.out.println("Day la khach hang moi");


        System.out.println("Danh sach trupc khi duoc sap xep la:");
        for(int i=0; i<list.length; i++)
            System.out.println(list[i]);

        // Sorting.selectionSort(list);
        // Sorting.insertionSort(list);
        // Sorting.bubbleSort(list);
        // Sorting.quickSort(list, 0, list.length-1);
        Sorting.mergeSort(list, 0, list.length-1);
        System.out.println("Danh sach sau khi duoc sap xep la:");
        for(int i=0; i<list.length; i++)
            System.out.println(list[i]);

    }
}
