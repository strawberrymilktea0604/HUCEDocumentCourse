
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.Buffer;
import java.text.DecimalFormat; //for number formatting
import java.util.Scanner; //for keyboard input
//ADD AN IMPORT STATEMENT HERE //for using files

public class StatsDemo {
    public static void main(String[] args) throws IOException
    // CLAUSE HERE
    {
        double sum = 0; // the sum of the numbers
        int count = 0; // the number of numbers added
        double mean = 0; // the average of the numbers
        double stdDev = 0; // the standard deviation of the
        // numbers
        String line; // a line from the file
        double difference; // difference between the value
        // and the mean
        // create an object of type Decimal Format
        DecimalFormat threeDecimals = new DecimalFormat("0.000");
        // create an object of type Scanner
        Scanner keyboard = new Scanner(System.in);
        String filename; // the user input file name
        // Prompt the user and read in the file name
        System.out.println("This program calculates statistics"+ "on a file containing a series of numbers");
        System.out.print("Enter the file name: ");
        filename = keyboard.nextLine();
        FileReader fr= new FileReader("Numbers.txt");
        BufferedReader br =new BufferedReader(fr);
        line= br.readLine();
        while (line!=null) {
            line= br.readLine();
            double nun= Double.parseDouble(line);  
        }
        br.close();
        fr.close();
        // ADD LINES FOR TASK #4 HERE
        // Create a FileReader object passing it the filename
        // Create a BufferedReader object passing it the
        // FileReader object.
        // priming read to read the first line of the file
        // create a loop that continues until you are at the
        // end of the file
        // convert the line to double value, add the value to
        // the sum
        // increment the counter
        // read a new line from the file
        // close the input file
        // store the calculated mean
        // ADD LINES FOR TASK #5 HERE
        
        FileReader f= new FileReader("Numbers.txt");
        BufferedReader b =new BufferedReader(f);
        line= b.readLine();
        while (line!=null) {
            line= b.readLine();
            double nun= Double.parseDouble(line);
            sum=sum+nun;
            count++;  
        }
        b.close();
        f.close();
        mean=sum/count;sum=0;
        FileReader j= new FileReader("Numbers.txt");
        BufferedReader k =new BufferedReader(j);
        line= k.readLine();
        while (line!=null) {
            line= k.readLine();
            double nun= Double.parseDouble(line);
            difference=nun-mean;
            sum+=Math.pow(difference, 2);
        }
        stdDev=Math.sqrt(sum/(count-1));
        // create a FileReader object passing it the filename
        // create a BufferedReader object passing it the
        // FileReader object.
        // reinitialize the sum of the numbers
        // reinitialize the number of numbers added
        // priming read to read the first line of the file
        // loop that continues until you are at the end of the
        // file
        // convert the line into a double value and subtract
        // the mean
        // add the square of the difference to the sum
        // increment the counter
        // read a new line from the file
        // close the input file
        // store the calculated standard deviation
        // ADD LINES FOR TASK #3 HERE
        FileWriter fw = new FileWriter("Results.txt");
            //fw.append("Xin chao");
            PrintWriter pw = new PrintWriter(fw);
            pw.println(stdDev);

            pw.close();
            fw.close();
        // create an object of type FileWriter using
        // "Results.txt"
        // create an object of PrintWriter passing it the
        // FileWriter object.
        // print the results to the output file
        // close the output file
    }
}
