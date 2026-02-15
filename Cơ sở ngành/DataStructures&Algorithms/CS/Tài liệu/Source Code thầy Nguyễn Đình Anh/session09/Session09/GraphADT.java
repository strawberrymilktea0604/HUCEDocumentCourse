import java.util.Iterator;

public interface GraphADT<T> {
    public void addVertex(T vertex);
    public void removeVertex(T vertex);
    public void addEdge(T vertex1, T vertex2);
    public void removeEdge(T vertex1, T vertex2);
    public Iterator<T> iteratorBFS(T startVertex);
    public Iterator<T> iteratorDFS(T startVertex);
    public boolean isEmpty();
    // public boolean isConnected();
    public int size();
}
