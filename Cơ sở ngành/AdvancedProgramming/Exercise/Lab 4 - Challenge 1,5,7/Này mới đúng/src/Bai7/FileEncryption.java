package Bai7;

import java.util.*;
import java.io.*;

public class FileEncryption {

    public static void main(String agrs[]) {
        try{

            String file1 = "C:\\Users\\minhk\\Downloads\\Chapter11\\src\\Bai7\\test.txt";
            String file2 = "C:\\Users\\minhk\\Downloads\\Chapter11\\src\\Bai7\\test2.txt";

            Scanner keyboard = new Scanner(new File(file1));
            StringBuilder sb = new StringBuilder();

            while(keyboard.hasNext()) {
                sb.append(keyboard.nextLine());  
            }

            String line = "";

            for(int i = 0; i < sb.length(); i++) {
                char ch = sb.toString().charAt(i);
                line += ((char) (ch + 10));
            }

            System.out.println("Original text: " + sb.toString()
            +"\nEncrypted text: " + line);


            FileWriter fw = new FileWriter(file2);
            fw.write(line);

            fw.close();

        }catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
