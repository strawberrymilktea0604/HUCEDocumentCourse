import java.util.Scanner;
import java.sql.*;

/**
  This program lets the user insert a row into the
  CoffeeDB database's Coffee table.
*/

public class CoffeeInserter
{
   public static void main(String[] args)
   {
      String description;  // To hold the coffee description
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
         
         // Get the data for the new coffee.
         System.out.print("Enter the coffee description: ");
         description = keyboard.nextLine();
         System.out.print("Enter the product number: ");
         prodNum = keyboard.nextLine();
         System.out.print("Enter the price: ");
         price = keyboard.nextDouble();
         
         // Create a Statement object.
         Statement stmt = conn.createStatement();
         
         // Create a string with an INSERT statement.
         String sqlStatement = "INSERT INTO Coffee " +
                      "(ProdNum, Price, Description) " +
                      "VALUES ('" +
                      prodNum + "', " +
                      price + ", '" +
                      description + "')";
         
         // Send the statement to the DBMS.
         int rows = stmt.executeUpdate(sqlStatement);
         
         // Display the results.
         System.out.println(rows + " row(s) added to the table.");
         
         // Close the connection.
         conn.close();
      }
      catch(Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }
}
