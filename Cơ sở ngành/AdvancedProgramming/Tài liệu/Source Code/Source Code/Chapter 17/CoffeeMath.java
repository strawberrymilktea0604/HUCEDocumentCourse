import java.sql.*;

/**
  This program demonstrates some of the SQL math functions.
*/

public class CoffeeMath
{
   public static void main(String[] args)
   {
      // Variables to hold the lowest, highest, and
      // average prices of coffee.
      double lowest = 0.0,
             highest = 0.0,
             average = 0.0;

      // Create a named constant for the URL.
      // NOTE: This value is specific for Java DB.
      final String DB_URL = "jdbc:derby:CoffeeDB";

      try
      {
         // Create a connection to the database.
         Connection conn = DriverManager.getConnection(DB_URL);

         // Create a Statement object.
         Statement stmt = conn.createStatement();

         // Create SELECT statements to get the lowest, highest,
         // and average prices from the Coffee table.
         String minStatement = "SELECT MIN(Price) FROM Coffee";
         String maxStatement = "SELECT MAX(Price) FROM Coffee";
         String avgStatement = "SELECT AVG(Price) FROM Coffee";

         // Get the lowest price.
         ResultSet minResult = stmt.executeQuery(minStatement);
         if (minResult.next())
            lowest = minResult.getDouble(1);

         // Get the highest price.
         ResultSet maxResult = stmt.executeQuery(maxStatement);
         if (maxResult.next())
            highest = maxResult.getDouble(1);

         // Get the average price.
         ResultSet avgResult = stmt.executeQuery(avgStatement);
         if (avgResult.next())
            average = avgResult.getDouble(1);

         // Display the results.
         System.out.printf("Lowest price: $%.2f\n", lowest);
         System.out.printf("Highest price: $%.2f\n", highest);
         System.out.printf("Average price: $%.2f\n", average);

         // Close the connection.
         conn.close();
      }
      catch(Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }
}
