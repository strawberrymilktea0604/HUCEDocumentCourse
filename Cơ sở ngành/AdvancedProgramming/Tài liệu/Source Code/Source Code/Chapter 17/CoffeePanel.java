import java.sql.*;
import javax.swing.*;

/**
   The CoffeePanel class is a custom JPanel that
   shows a list of coffees in a JList.
*/

public class CoffeePanel extends JPanel
{
   private final int NUM_ROWS = 5; // Number of rows to display
   private JList coffeeList;       // A list for coffee descriptions
   String[] coffeeNames;           // To hold coffee names
   
   /**
       Constructor
   */

   public CoffeePanel()
   {
		try
		{
	      // Create a CoffeeDBManager object.
	      CoffeeDBManager dbManager = new CoffeeDBManager();
	      
	      // Get a list of coffee names as a String array.
	      coffeeNames = dbManager.getCoffeeNames();
	
	      // Create a JList object to hold the coffee names.
	      coffeeList = new JList(coffeeNames);
	      
	      // Set the number of visible rows.
	      coffeeList.setVisibleRowCount(NUM_ROWS);
	      
	      // Put the JList object in a scroll pane.
	      JScrollPane scrollPane = new JScrollPane(coffeeList);
	      
	      // Add the scroll pane to the panel.
	      add(scrollPane);
	      
	      // Add a titled border to the panel.
	      setBorder(BorderFactory.createTitledBorder(
	                                 "Select a Coffee"));
		}
      catch (SQLException ex)
      {
         ex.printStackTrace();
         System.exit(0);
      }
   }

   /**
       The getCoffee method returns the coffee
       description selected  by the user.
   */
   
   public String getCoffee()
   {
      // The JList class's getSelectedValue method returns
      // an Object reference, so we will cast it to a String.
      return (String) coffeeList.getSelectedValue();
   }
}