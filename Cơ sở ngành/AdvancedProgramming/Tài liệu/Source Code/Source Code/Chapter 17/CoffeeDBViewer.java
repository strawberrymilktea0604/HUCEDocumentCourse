import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
   The CoffeeDBViewer class is a simple database veiwer for
   the CoffeeDB database.
*/

public class CoffeeDBViewer extends JFrame
{
   JPanel queryPanel;       // A panel to hold the query
   JPanel buttonPanel;      // A panel to hold the buttons
   JTextArea queryTextArea; // The user enters a query here
   JButton submitButton;    // To submit a query
   JButton exitButton;      // To quit the application

   /**
       Constructor
   */

   public CoffeeDBViewer()
   {
      // Set the window title.
      setTitle("CoffeeDB Viewer");

      // Specify an action for the close button.
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      // Build the Query Panel.
      buildQueryPanel();

      // Build the Button Panel.
      buildButtonPanel();

      // Add the panels to the content pane.
      add(queryPanel, BorderLayout.NORTH);
      add(buttonPanel, BorderLayout.SOUTH);

      // Pack and display.
      pack();
      setVisible(true);
   }

   /**
       The buildQueryPanel method builds a panel to hold the
       text area that the user will enter a query into.
   */

   private void buildQueryPanel()
   {
      // Create a panel.
      queryPanel = new JPanel();

      // Create a text area, 8 rows by 50 columns.
      queryTextArea = new JTextArea(8, 50);

      // Turn line wrapping on.
      queryTextArea.setLineWrap(true);

      // Add a scroll pane to the text area.
      JScrollPane qaScrollPane =
                    new JScrollPane(queryTextArea);
      qaScrollPane.setHorizontalScrollBarPolicy(
            JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
      qaScrollPane.setVerticalScrollBarPolicy(
            JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

      // Add the text area to the panel.
      queryPanel.add(qaScrollPane);
   }

   /**
       The buildButtonPanel method builds a panel
       to hold the Submit and Exit buttons.
   */

   private void buildButtonPanel()
   {
      // Create a panel.
      buttonPanel = new JPanel();

      // Create the Submit button.
      submitButton = new JButton("Submit");

      // Register an action listener for the Submit button.
      submitButton.addActionListener(new SubmitButtonListener());

      // Create the Exit button.
      exitButton = new JButton("Exit");

      // Register an action listener for the Exit button.
      exitButton.addActionListener(new ExitButtonListener());

      // Add the two buttons to the panel.
      buttonPanel.add(submitButton);
      buttonPanel.add(exitButton);
   }

   /**
       The SubmitButtonListener class is an action listener
       for the Submit button.
   */

   private class SubmitButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         // Get the user's statement.
         String userStatement = queryTextArea.getText();

         // Qualify that it is a SELECT statement.
         if (userStatement.trim().toUpperCase()
                               .startsWith("SELECT"))
         {
            // Create a CoffeeDBQuery object for the query.
            CoffeeDBQuery dbQuery =
                          new CoffeeDBQuery(userStatement);

            // Get the column names.
            String[] colNames = dbQuery.getColumnNames();

            // Get the table data.
            String[][] data = dbQuery.getTableData();

            // Display the results in a table.
            TableFormatter table =
                      new TableFormatter(data, colNames);
         }
         else
         {
            JOptionPane.showMessageDialog(null,
                            "Only enter SELECT statements.");
         }
      }
   }

   /**
       The ExitButtonListener class is an action listener
       for the Exit button.
   */

   private class ExitButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         // End the application.
         System.exit(0);
      }
   }

   /**
       The main method creates an instance of the class.
   */

   public static void main(String[] args)
   {
      new CoffeeDBViewer();
   }
}