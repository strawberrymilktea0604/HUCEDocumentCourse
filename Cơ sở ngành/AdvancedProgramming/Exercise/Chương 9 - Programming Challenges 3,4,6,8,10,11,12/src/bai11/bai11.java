package bai11;

import java.util.*;
import java.text.*;
import java.io.*;
public class bai11
{
    static File file = new File("C:\\Users\\minhk\\Downloads\\chuong9 baitap\\src\\bai11\\SalesData.txt");
    static DecimalFormat df = new DecimalFormat("#,###.00");
    static Scanner sc;

    public static void main(String [] args) throws IOException
    {

         try {
             sc = new Scanner(file);

             int count = 1, allWeeksTotal = 0,
                     num1 = 0, num2 = 0;

             double greatestSale = 0, lowestSales = Double.MAX_VALUE;

             while (sc.hasNext()) {
                 String[] parts = sc.nextLine().split(",");
                 double total = 0;
                 System.out.println("\n Tuan #" + count);
                 System.out.println();

                 for (int i = 0; i < 7; i++) {
                     double sales = Double.parseDouble(parts[i]);
                     System.out.println("Ngay #" + (i + 1) + ": " + df.format(sales));
                     total += sales;

                 }
                 allWeeksTotal += total;

                 if(total > greatestSale) {
                     greatestSale = total;
                     num1 = count;
                 }

                 if(total < greatestSale) {
                     lowestSales = total;
                     num2 = count;
                 }

                 System.out.println("\nTong: " + df.format(total)
                         + "\nTrung binh tong: " + df.format(total/7));

                 count++;



             }
             System.out.println("\nTong so tien tat ca cac tuan: " + df.format(allWeeksTotal)
                     + "\nTrung binh tong so tien tat ca cac tuan: " + df.format(allWeeksTotal/3)
                     + "\nBan gia dat nhat: " + df.format(greatestSale) + "\tWeek #" + num1
                     + "\nBan gia re nhat: " + df.format(lowestSales) + "\tWeek #" + num2);

         } catch (Exception e) {
             System.out.println(e.toString());
         }
    }


}