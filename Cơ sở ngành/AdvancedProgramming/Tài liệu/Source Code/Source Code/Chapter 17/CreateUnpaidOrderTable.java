import java.sql.*;   // Needed for JDBC classes

/**
  This program creates an UnpaidOrder
  table in the CoffeeDB database.
*/

public class CreateUnpaidOrderTable
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

         // Get a Statement object.
         Statement stmt = conn.createStatement();

         // Make an SQL statement to create the table.
         String sql = "CREATE TABLE UnpaidOrder " +
				"( CustomerNumber CHAR(10) NOT NULL REFERENCES Customer(CustomerNumber), "+
				"  ProdNum CHAR(10) NOT NULL REFERENCES Coffee(ProdNum),"+
				"  OrderDate CHAR(10),"+
				"  Quantity DOUBLE,"+
				"  Cost DOUBLE )";

         // Execute the statement.
         stmt.execute(sql);

         // Add some rows to the new table.
         sql = "INSERT INTO UnpaidOrder VALUES" +
               "('101', '16-001', '3/15/2006', 5, 49.75)";
         stmt.executeUpdate(sql);
			
			sql = "INSERT INTO UnpaidOrder VALUES" +
               "('101', '14-001', '3/17/2006', 7, 62.65)";
         stmt.executeUpdate(sql);

         sql = "INSERT INTO UnpaidOrder VALUES" +
               "('102', '18-002', '3/20/2006', 10, 184.50)";
         stmt.executeUpdate(sql);

         sql = "INSERT INTO UnpaidOrder VALUES" +
               "('103', '17-004', '3/21/2006', 3, 35.85)";
         stmt.executeUpdate(sql);

         sql = "INSERT INTO UnpaidOrder VALUES" +
               "('103', '16-002', '3/22/2006', 6, 59.70)";
         stmt.executeUpdate(sql);

         // Close the connection.
         conn.close();
      }
      catch (Exception ex)
      {
         System.out.println("ERROR: " + ex.getMessage());
      }
   }
}
