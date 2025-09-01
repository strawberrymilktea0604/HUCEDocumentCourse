import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class DemoFile {
    public static void writeFile() throws IOException {
        //ghi file
        FileWriter fw = new FileWriter("names.txt", false); //tạo file mới
        //fw.append("Xin chao");
        PrintWriter pw = new PrintWriter(fw);
        pw.println("Xin chao");
        pw.printf("%-4d %4.1f %10s", 1, 1.254, "abcd");

        pw.close();
        fw.close();

        //đọc file
        File myFile = new File("names1.txt");
        Scanner inputFile = new Scanner(myFile); 
        // String test = inputFile.nextLine();
        // inputFile.close();

        while (inputFile.hasNext())
        {
            String str = inputFile.nextLine();
            System.out.println(str);
        }
        inputFile.close();// close the file when done.
    }

    public static void main(String[] args) {
        try {
            writeFile();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
