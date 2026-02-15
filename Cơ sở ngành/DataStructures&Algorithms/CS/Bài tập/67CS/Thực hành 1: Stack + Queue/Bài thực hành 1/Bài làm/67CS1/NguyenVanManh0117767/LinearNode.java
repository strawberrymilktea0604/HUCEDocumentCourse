public class LinearNode<T>
{
    T data; 
    LinearNode<T> next; 

    LinearNode() 
    {
        data = null; 
        next = null;
    }

    public LinearNode(T data) 
    {
        this.data = data; 
        next = null;
    }
}