import java.util.Scanner;
import java.sql.*;

/**
  This program lets the user search for coffees
  priced at a minimum value.
*/

public class CoffeeMinPrice
{
   public static void main(String[] args)
   {
      double minPrice;        // To hold the minimum price
      int coffeeCount = 0;    // To count coffees that qualify

      // Create a named constant for the URL.
      // NOTE: This value is specific for Java DB.
      final String DB_URL = "jdbc:derby:CoffeeDB";

      // Create a Scanner object for keyboard input.
      Scanner keyboard = new Scanner(System.in);

      // Get the minimum price from the user.
      System.out.print("Enter the minimum price: ");
      minPrice = keyboard.nextDouble();

      try
      {
         // Create a connection to the database.
         Connection conn = DriverManager.getConnection(DB_URL);

         // Create a Statement object.
         Statement stmt = conn.createStatement();

         // Create a string containing a SELECT statement.
         // Note that we are incorporating the user's input
         // into the string.
         String sqlStatement =
            "SELECT * FROM Coffee WHERE Price >= " +
            Double.toString(minPrice);

         // Send the statement to the DBMS.
         ResultSet result = stmt.executeQuery(sqlStatement);

         // Display the contents of the result set.
         // The result set will have three columns.
         while (result.next())
         {
            // Display a row from the result set.
            System.out.printf("%25s %10s %5.2f\n",
                              result.getString("Description"),
                              result.getString("ProdNum"),
                              result.getDouble("Price"));

            // Increment the counter.
            coffeeCount++;
         }

         // Display the number of qualifying coffees.
         System.out.println(coffeeCount + " coffees found.");

         // Close the connection.
         conn.close();
      }
      catch(Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }
}
