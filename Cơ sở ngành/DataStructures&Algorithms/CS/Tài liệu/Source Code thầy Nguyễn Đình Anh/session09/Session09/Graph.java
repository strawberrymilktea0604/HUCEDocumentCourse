import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class Graph<T> implements GraphADT<T> 
{
    protected int numVertices;
    protected boolean[][] adjMatrix;
    protected T[] vertices;
    protected int DEFAULT_CAPACITY = 10;
    
    @SuppressWarnings("unchecked")
    public Graph()
    {
        numVertices = 0;
        adjMatrix = new boolean[DEFAULT_CAPACITY][DEFAULT_CAPACITY];
        vertices = (T[])(new Object[DEFAULT_CAPACITY]);
    }

    @Override
    public void addEdge(T vertex1, T vertex2) 
    {
        addEdge(getIndex(vertex1), getIndex(vertex2));
    }

    private void addEdge(int index1, int index2)
    {
        if (indexIsValid(index1) && indexIsValid(index2))
        {
            adjMatrix[index1][index2] = true;
            adjMatrix[index2][index1] = true;
        }
    }

    @Override
    public void removeEdge(T vertex1, T vertex2) 
    {
        removeEdge(getIndex(vertex1), getIndex(vertex2));
    }

    public void removeEdge(int index1, int index2)
    {
        if (indexIsValid(index1) && indexIsValid(index2))
        {
            adjMatrix[index1][index2] = false;
            adjMatrix[index2][index1] = false;
        }
    }

    @Override
    public void addVertex(T vertex) {
        if (numVertices == vertices.length)
            expandCapacity();
        
        vertices[numVertices] = vertex;
        for(int i=0; i<numVertices; i++)
        {
            adjMatrix[numVertices][i] = false;
            adjMatrix[i][numVertices] = false;
        }

        numVertices++;
    }

    @Override
    public void removeVertex(T vertex)
    {
        removeVertex(getIndex(vertex));
    }

    private void removeVertex(int index)
    {
        if(indexIsValid(index))
        {
            numVertices--;
            for(int i=index;i<numVertices;i++)
                vertices[i] = vertices[i+1];
            
            for(int i = index; i<numVertices; i++)
                for(int j = 0; j<=numVertices; j++)
                    adjMatrix[i][j] = adjMatrix[i+1][j];
            
            for(int i = index; i<numVertices; i++)
                for(int j = 0; j<=numVertices; j++)
                    adjMatrix[j][i] = adjMatrix[j][i+1];

        }
    }

    @Override
    public boolean isEmpty() 
    {
        return (numVertices == 0);
    }

    @Override
    public int size() 
    {
        return numVertices;
    }

    @Override
    public Iterator<T> iteratorBFS(T startVertex) 
    {
        return iteratorBFS(getIndex(startVertex));
    }

    private Iterator<T> iteratorBFS(int startIndex)
    {
        LinkedQueue<Integer> traversalQueue = new LinkedQueue<Integer>();
        ArrayList<T> resultList = new ArrayList<T>();
        boolean[] visited = new boolean[numVertices];

        if (!indexIsValid(startIndex))
            return resultList.iterator();
        
        for(int i=0;i<numVertices;i++)
            visited[i] = false;

        traversalQueue.enqueue(startIndex);
        visited[startIndex] = true;

        while(!traversalQueue.isEmpty())
        {
            Integer x=traversalQueue.dequeue();
            resultList.add(vertices[x]);

            for(int i=0;i<numVertices;i++)
            {
                if(adjMatrix[x.intValue()][i] && !visited[i])
                {
                    traversalQueue.enqueue(i);
                    visited[i] = true;
                }
            }
        }

        return resultList.iterator();
    }

    @Override
    public Iterator<T> iteratorDFS(T startVertex) 
    {
        return iteratorDFS(getIndex(startVertex));
    }

    private Iterator<T> iteratorDFS(int startIndex)
    {
        LinkedStack<Integer> traversalStack = new LinkedStack<Integer>();
        ArrayList<T> resultList = new ArrayList<T>();
        boolean[] visited = new boolean[numVertices];

        if (!indexIsValid(startIndex))
        return resultList.iterator();
    
        for(int i=0;i<numVertices;i++)
            visited[i] = false;

        traversalStack.push(startIndex);
        resultList.add(vertices[startIndex]);
        visited[startIndex] = true;
        
        while(!traversalStack.isEmpty())
        {
            Integer x = traversalStack.peek();
            boolean found = false;
            for(int i=0; i<numVertices && !found; i++)
            {
                if (adjMatrix[x.intValue()][i] && !visited[i])
                {
                    traversalStack.push(i);
                    resultList.add(vertices[i]);
                    visited[i] = true;
                    found = true;
                }
            }
            if (!found && !traversalStack.isEmpty())
            traversalStack.pop();            
        }
        return resultList.iterator();
    }

    private boolean indexIsValid(int index)
    {
        return (index<numVertices && index>=0);
    }

    private int getIndex(T vertex)
    {
        for(int i=0; i<numVertices; i++)
        {
            if (vertices[i].equals(vertex))
                return i;
        }
        return -1;
    }

    private void expandCapacity()
    {
        vertices = Arrays.copyOf(vertices, vertices.length * 2);
        boolean[][] largerAdjMatrix = new boolean[vertices.length*2][vertices.length*2];

        for(int i=0;i<numVertices;i++)
            for(int j=0;j<numVertices;j++)
            {
                largerAdjMatrix[i][j] = adjMatrix[i][j];
            }

        adjMatrix = largerAdjMatrix;
    }
}
