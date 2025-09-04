import java.util.Scanner;
import java.sql.*;

/**
  This program lets the user delete a coffee
  from the CoffeeDB database's Coffee table.
*/

public class CoffeeDeleter
{
   public static void main(String[] args)
   {
      String prodNum;   // To hold the product number
      String sure;      // To make sure the user wants to delete

      // Create a named constant for the URL.
      // NOTE: This value is specific for Java DB.
      final String DB_URL = "jdbc:derby:CoffeeDB";

      // Create a Scanner object for keyboard input.
      Scanner keyboard = new Scanner(System.in);

      try
      {
         // Create a connection to the database.
         Connection conn = DriverManager.getConnection(DB_URL);

         // Create a Statement object.
         Statement stmt = conn.createStatement();

         // Get the product number for the desired coffee.
         System.out.print("Enter the product number: ");
         prodNum = keyboard.nextLine();

         // Display the coffee's current data.
         if (findAndDisplayProduct(stmt, prodNum))
         {
            // Make sure the user wants to delete this product.
            System.out.print("Are you sure you want to delete " +
                             "this item? (y/n): ");
            sure = keyboard.nextLine();

            if (Character.toUpperCase(sure.charAt(0)) == 'Y')
            {
               // Delete the specified coffee.
               deleteCoffee(stmt, prodNum);
            }
            else
            {
               System.out.println("The item was not deleted.");
            }
         }
         else
         {
            // The specified product number was not found.
            System.out.println("That product was not found.");
         }

         // Close the connection.
         conn.close();
      }
      catch(Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }

   /**
     The findAndDisplayProduct method finds a specified coffee's
     data and displays it.
     @param stmt A Statement object for the database.
     @param prodNum The product number for the desired coffee.
     @return true or false to indicate whether the product was found.
   */

   public static boolean findAndDisplayProduct(Statement stmt,
                                               String prodNum)
                                               throws SQLException
   {
      boolean productFound; // Flag

      // Create a SELECT statement to get the specified
      // row from the Coffee table.
      String sqlStatement =
         "SELECT * FROM Coffee WHERE ProdNum = '" +
         prodNum + "'";

      // Send the SELECT statement to the DBMS.
      ResultSet result = stmt.executeQuery(sqlStatement);

      // Display the contents of the result set.
      if (result.next())
      {
            // Display the product.
            System.out.println("Description: " +
                               result.getString("Description"));
            System.out.println("Product Number: " +
                              result.getString("ProdNum"));
            System.out.println("Price: $" +
                              result.getDouble("Price"));

            // Set the flag to indicate the product was found.
            productFound = true;
      }
      else
      {
         // Indicate the product was not found.
         productFound = false;
      }

      return productFound;
   }

   /**
     The deleteCoffee method deletes a specified coffee.
     @param stmt A Statement object for the database.
     @param prodNum The product number for the desired coffee.
   */

   public static void deleteCoffee(Statement stmt, String prodNum)
                                   throws SQLException
   {
      // Create a DELETE statement to delete the
      // specified product number.
      String sqlStatement = "DELETE FROM Coffee " +
                            "WHERE ProdNum = '" + prodNum + "'";

      // Send the DELETE statement to the DBMS.
      int rows = stmt.executeUpdate(sqlStatement);

      // Display the results.
      System.out.println(rows + " row(s) deleted.");
   }
}