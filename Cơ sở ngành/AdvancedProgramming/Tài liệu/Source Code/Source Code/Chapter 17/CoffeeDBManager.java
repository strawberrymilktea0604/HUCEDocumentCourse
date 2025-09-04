import java.sql.*;

/**
   The CoffeeDBManager class performs operations on
   the CoffeeDB database.
*/

public class CoffeeDBManager
{
   // Constant for database URL.
   public final String DB_URL =
               "jdbc:derby:CoffeeDB";

   // Field for the database connection
   private Connection conn;

   /**
      Constructor
   */

   public CoffeeDBManager() throws SQLException
   {
      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);
   }

   /**
       The getCoffeeNames method returns an array
       of Strings containing all the coffee names.
   */

   public String[] getCoffeeNames()
                   throws SQLException
   {
      // Create a Statement object for the query.
      Statement stmt =
         conn.createStatement(
                 ResultSet.TYPE_SCROLL_SENSITIVE,
                 ResultSet.CONCUR_READ_ONLY);

      // Execute the query.
      ResultSet resultSet = stmt.executeQuery(
                       "SELECT Description FROM Coffee");

      // Get the number of rows
      resultSet.last();                 // Move to last row
      int numRows = resultSet.getRow(); // Get row number
      resultSet.first();                // Move to first row

      // Create an array for the coffee names.
      String[] listData = new String[numRows];

      // Populate the array with coffee names.
      for (int index = 0; index < numRows; index++)
      {
         // Store the coffee name in the array.
         listData[index] = resultSet.getString(1);

         // Go to the next row in the result set.
         resultSet.next();
      }

      // Close the connection and statement objects.
      conn.close();
      stmt.close();

      // Return the listData array.
      return listData;
   }

   /**
       The getProdNum method returns a specific
       coffee's product number.
		 @param coffeeName The specified coffee.
   */

   public String getProdNum(String coffeeName)
                            throws SQLException
   {
      String prodNum = ""; // Product number

      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);

      // Create a Statement object for the query.
      Statement stmt = conn.createStatement();

      // Execute the query.
      ResultSet resultSet = stmt.executeQuery(
                          "SELECT ProdNum " +
                          "FROM Coffee " +
                          "WHERE Description = '" +
                          coffeeName + "'");

      // If the result set has a row, go to it
      // and retrieve the product number.
      if (resultSet.next())
         prodNum = resultSet.getString(1);

      // Close the Connection and Statement objects.
      conn.close();
      stmt.close();

      // Return the product number.
      return prodNum;
   }

   /**
       The getCoffeePrice method returns the price
       of a coffee.
		 @param prodNum The specified product number.
   */

   public double getCoffeePrice(String prodNum)
                                throws SQLException
   {
      double price = 0.0;  // Coffee price

      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);

      // Create a Statement object for the query.
      Statement stmt = conn.createStatement();

      // Execute the query.
      ResultSet resultSet = stmt.executeQuery(
                          "SELECT Price " +
                          "FROM Coffee " +
                          "WHERE ProdNum = '" +
                          prodNum + "'");

      // If the result set has a row, go to it
      // and retrieve the price.
      if (resultSet.next())
         price = resultSet.getDouble(1);

      // Close the connection and statement objects.
      conn.close();
      stmt.close();

      // Return the price.
      return price;
   }

   /**
       The getCustomerNames method returns an array
       of Strings containing all the customer names.
   */

   public String[] getCustomerNames() throws SQLException
   {
      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);

      // Create a Statement object for the query.
      Statement stmt =
         conn.createStatement(
                 ResultSet.TYPE_SCROLL_SENSITIVE,
                 ResultSet.CONCUR_READ_ONLY);

      // Execute the query.
      ResultSet resultSet =
          stmt.executeQuery("SELECT Name FROM Customer");

      // Get the number of rows
      resultSet.last();                 // Move last row
      int numRows = resultSet.getRow(); // Get row number
      resultSet.first();                // Move to first row

      // Create an array for the customer names.
      String[] listData = new String[numRows];

      // Populate the array with customer names.
      for (int index = 0; index < numRows; index++)
      {
         // Store the customer name in the array.
         listData[index] = resultSet.getString(1);

         // Go to the next row in the result set.
         resultSet.next();
      }

      // Close the connection and statement objects.
      conn.close();
      stmt.close();

      // Return the listData array.
      return listData;
   }

   /**
       The getCustomerNum method returns a specific
       customer's number.
		 @param name The specified customer's name.
   */

   public String getCustomerNum(String name)
                                throws SQLException
   {
      String customerNumber = "";

      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);

      // Create a Statement object for the query.
      Statement stmt = conn.createStatement();

      // Execute the query.
      ResultSet resultSet =
        stmt.executeQuery("SELECT CustomerNumber " +
                          "FROM Customer " +
                          "WHERE Name = '" + name + "'");

      if (resultSet.next())
         customerNumber = resultSet.getString(1);

      // Close the connection and statement objects.
      conn.close();
      stmt.close();

      // Return the customer number.
      return customerNumber;
   }

   /**
       The submitOrder method submits an order to
       the UnpaidOrder table in the CoffeeDB database.
		 @param custNum The customer number.
		 @param prodNum The product number.
		 @param quantity The quantity ordered.
		 @param price The price.
		 @param orderDate The order date.
   */

   public void submitOrder(String custNum, String prodNum,
                           int quantity, double price,
                           String orderDate) throws SQLException
   {
      // Calculate the cost of the order.
      double cost = quantity * price;

      // Create a connection to the database.
      conn = DriverManager.getConnection(DB_URL);

      // Create a Statement object for the query.
      Statement stmt = conn.createStatement();

      // Execute the query.
      stmt.executeUpdate("INSERT INTO UnpaidOrder VALUES('" +
                         custNum + "', '" +
                         prodNum + "', '" + orderDate + "', " +
                         quantity + ", " + cost + ")");

      // Close the connection and statement objects.
      conn.close();
      stmt.close();
   }
}