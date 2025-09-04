import java.sql.*;
import javax.swing.*;

/**
    The CustomerPanel class is a custom JPanel that
    shows a list of customers in a JList.
*/

public class CustomerPanel extends JPanel
{
   private final int NUM_ROWS = 5; // Number of rows to display
   private JList customerList;     // A list for customer names
   String[] names;                 // To hold customer names
   
   /**
       Constructor
   */

   public CustomerPanel()
   {
      try
      {
         // Create a CoffeeDBManager object.
         CoffeeDBManager dbManager = new CoffeeDBManager();
         
         // Get a list of customer names as a String array.
         names = dbManager.getCustomerNames();
         
         // Create a JList object to hold customer names.
         customerList = new JList(names);
         
         // Set the number of visible rows.
         customerList.setVisibleRowCount(NUM_ROWS);
         
         // Put the JList object in a scroll pane.
         JScrollPane scrollPane =
                        new JScrollPane(customerList);
         
         // Add the scroll pane to the panel.
         add(scrollPane);
         
         // Add a titled border to the panel.
         setBorder(BorderFactory.createTitledBorder(
                                   "Select a Customer"));
      }
      catch (SQLException ex)
      {
         ex.printStackTrace();
         System.exit(0);
      }
   }

   /**
       The getCustomer method returns the customer
       name selected  by the user.
   */
   
   public String getCustomer()
   {
      // The JList class's getSelectedValue method returns
      // an Object reference, so we will cast it to a String.
      return (String) customerList.getSelectedValue();
   }
}