import javax.swing.JOptionPane;

/**
   This program demonstrates different types of
   dialog boxes.
*/

public class TestAverageDialog
{
   public static void main(String[] args)
   {
      String input;                // User input
      int score1, score2, score3;  // test scores
      double average; // Average test score
      int repeat;     // Confirm dialog button clicked
      
      do
      {
         // Get the three test scores.
         input = JOptionPane.showInputDialog(null, 
                          "Enter score #1.");
         score1 = Integer.parseInt(input);

         input = JOptionPane.showInputDialog(null, 
                          "Enter score #2.");
         score2 = Integer.parseInt(input);

         input = JOptionPane.showInputDialog(null,
                          "Enter score #3.");
         score3 = Integer.parseInt(input);

         // Calculate and display the average test score.
         average = (score1 + score2 + score3) / 3.0;
         JOptionPane.showMessageDialog(null,
                         "The average is " + average);

         // Does the user want to average another set?
         repeat = JOptionPane.showConfirmDialog(null, 
                  "Would you like to average another " +
                  "set of test scores?", "Please Confirm",
                  JOptionPane.YES_NO_OPTION);

      } while (repeat == JOptionPane.YES_OPTION);

      System.exit(0);
   }
}
