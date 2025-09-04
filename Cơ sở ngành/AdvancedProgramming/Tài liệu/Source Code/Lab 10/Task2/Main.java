package Task2;

import java.io.BufferedReader;
import java.io.FileReader;

public class Main {
    public static void main(String[] args) throws Exception{
            
            //Doc file secret.txt
            FileReader fr = new FileReader("C:\\Users\\Wayari\\Desktop\\Học đại\\Năm 1 - Kỳ 2\\Lập trình nâng cao\\lab10\\Task2\\secret.txt");
            BufferedReader br = new BufferedReader(fr);
            StringBuffer str = new StringBuffer(100);
            int i;
            while ((i = br.read()) != -1) {
                //Them ki tu vao doi tuong str
                str.append((char) i);
            }
            fr.close();
            br.close();
            //In ra noi dung goc
            System.out.println(str.toString());

            //Tao [] token tu doi tuong str
            String[] tokenOfSecret = str.toString().split(" ");
            StringBuffer captain = new StringBuffer(10);
            for(int j = 0; j < tokenOfSecret.length; j++) {
                if (j % 5 == 0)
                //Them vao doi tuong captain
                    captain.append(tokenOfSecret[j].charAt(0));
            }
            //In ket qua
            System.out.print("Result is: " + captain.toString());
            
    
    }
}
