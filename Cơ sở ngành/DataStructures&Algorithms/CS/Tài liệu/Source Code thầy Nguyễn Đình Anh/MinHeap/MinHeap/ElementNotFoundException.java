public class ElementNotFoundException extends RuntimeException {
    public ElementNotFoundException(String collection)
    {
        super("The element is not found in " + collection);
    }
}
