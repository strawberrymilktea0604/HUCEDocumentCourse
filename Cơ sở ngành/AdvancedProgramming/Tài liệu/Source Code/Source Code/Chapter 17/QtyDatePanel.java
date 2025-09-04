import javax.swing.*;
import java.awt.*;

/**
    The QtyDatePanel presents text fields for the
    quantity of coffee being ordered and the order
    date.
*/

public class QtyDatePanel extends JPanel
{
   private JTextField qtyTextField;   // Order quantity
   private JTextField dateTextField;  // order date
   
   /**
       Constructor
   */

   public QtyDatePanel()
   {
      // Create a label prompting the user
      // for a quantity.
      JLabel qtyPrompt = new JLabel("Quantity");
      
      // Create a text field for the quantity.
      qtyTextField = new JTextField(10);

      // Create a label prompting the user
      // for a date.
      JLabel datePrompt = new JLabel("Order Date");
      
      // Create a text field for the date.
      dateTextField = new JTextField(10);
      
      // Create a grid layout manager, 4 rows, 1 column.
      setLayout(new GridLayout(4, 1));
      
      // Add the components to the panel.
      add (qtyPrompt);
      add (qtyTextField);
      add (datePrompt);
      add (dateTextField);
   }
   
   /**
       The getQuantity method returns the quantity
       entered by the user.
       @return The value entered into qtyTextField.
   */
   
   public int getQuantity()
   {
      return Integer.parseInt(qtyTextField.getText());
   }

   /**
       The getDate method returns the quantity
       entered by the user.
       @return The value entered into dateTextField.
   */
   
   public String getDate()
   {
      return dateTextField.getText();
   }

   /**
       The clear method clears the text fields.
   */
   
   public void clear()
   {
      qtyTextField.setText("");
      dateTextField.setText("");
   }
}