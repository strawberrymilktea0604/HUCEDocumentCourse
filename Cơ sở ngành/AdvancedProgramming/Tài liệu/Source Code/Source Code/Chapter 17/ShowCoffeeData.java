import java.sql.*;   // Needed for JDBC classes

/**
  This program displays all of the columns in the
  Coffee table of the CoffeeDB database.
*/

public class ShowCoffeeData
{
   public static void main(String[] args)
   {
      // Create a named constant for the URL.
      // NOTE: This value is specific for Java DB.
      final String DB_URL = "jdbc:derby:CoffeeDB";
      
      try
      {
         // Create a connection to the database.
         Connection conn = DriverManager.getConnection(DB_URL);
         
         // Create a Statement object.
         Statement stmt = conn.createStatement();
         
         // Create a string with a SELECT statement.
         String sqlStatement = "SELECT * FROM Coffee";
         
         // Send the statement to the DBMS.
         ResultSet result = stmt.executeQuery(sqlStatement);
         
         // Display the contents of the result set.
         // The result set will have three columns.
         while (result.next())
         {
            System.out.printf("%25s %10s %5.2f\n",
                              result.getString("Description"),
                              result.getString("ProdNum"),
                              result.getDouble("Price"));
         }
         
         // Close the connection.
         conn.close();
      }
      catch(Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }
}
