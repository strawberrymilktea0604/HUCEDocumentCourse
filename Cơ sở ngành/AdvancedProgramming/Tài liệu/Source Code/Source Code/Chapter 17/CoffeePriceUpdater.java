import java.util.Scanner;
import java.sql.*;

/**
  This program lets the user change the price of a
  coffee in the CoffeeDB database's Coffee table.
*/

public class CoffeePriceUpdater
{
   public static void main(String[] args)
   {
      String prodNum;      // To hold the product number
      double price;        // To hold the price

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
            // Get the new price.
            System.out.print("Enter the new price: ");
            price = keyboard.nextDouble();

            // Update the coffee with the new price.
            updatePrice(stmt, prodNum, price);
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
     The updatePrice method updates a specified coffee's price.
     @param stmt A Statement object for the database.
     @param prodNum The product number for the desired coffee.
     @param price The product's new price.
   */

   public static void updatePrice(Statement stmt, String prodNum,
                                  double price) throws SQLException
   {
      // Create an UPDATE statement to update the price
      // for the specified product number.
      String sqlStatement = "UPDATE Coffee " +
                            "SET Price = " + Double.toString(price) +
                            "WHERE ProdNum = '" + prodNum + "'";

      // Send the UPDATE statement to the DBMS.
      int rows = stmt.executeUpdate(sqlStatement);

      // Display the results.
      System.out.println(rows + " row(s) updated.");
   }
}