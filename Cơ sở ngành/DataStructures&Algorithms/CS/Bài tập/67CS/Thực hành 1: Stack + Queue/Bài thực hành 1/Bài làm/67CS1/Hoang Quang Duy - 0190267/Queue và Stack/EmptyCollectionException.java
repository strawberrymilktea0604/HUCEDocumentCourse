public class EmptyCollectionException extends Exception 
{
    public EmptyCollectionException(String col) 
    {
        super("The " + col + " is empty!");
    }
}
