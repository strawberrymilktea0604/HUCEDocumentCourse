package bai10;

import java.io.*;
import java.util.*;


public class bai10
{
    private static String line;


    public static void main(String[] args) throws Exception
    {
        int count = 0;


        Scanner in = new Scanner(System.in);
        System.out.print("Nhap file: ");
        String filename = in.nextLine();
        System.out.println("Dang mo file " + filename);

        try
        {
            FileReader fileReader = new FileReader(filename);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null)
            {
                String words[] = line.split(" ");
                count = count + words.length;
            }
            System.out.println("So chu trong file la " + count);
            bufferedReader.close();
        }
        catch(FileNotFoundException ex)
        {
            System.out.println("Khong mo duoc file '" + filename + "'");
        }
        catch(IOException ex)
        {
            System.out.println("Loi mo file '" + filename + "'");
        }
    }

}