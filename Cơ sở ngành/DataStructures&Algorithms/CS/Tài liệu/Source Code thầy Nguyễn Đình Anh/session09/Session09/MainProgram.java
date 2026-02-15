import java.util.Iterator;

public class MainProgram {
    public static void main(String[] args)
    {
        Graph<Integer> myGraph = new Graph<Integer>();
        myGraph.addVertex(1);
        myGraph.addVertex(2);
        myGraph.addVertex(3);
        myGraph.addVertex(4);
        myGraph.addVertex(5);
        myGraph.addEdge(1, 2);
        myGraph.addEdge(1, 3);
        myGraph.addEdge(2, 3);
        myGraph.addEdge(2, 4);
        myGraph.addEdge(3, 5);
        myGraph.addEdge(4, 5);

        Iterator<Integer> it = myGraph.iteratorBFS(1);

        while(it.hasNext())
        {
            Integer result = it.next();
            System.out.print(result + " ");
        }

        System.out.println();
        Iterator<Integer> it2 = myGraph.iteratorDFS(1);

        while(it2.hasNext())
        {
            Integer result = it2.next();
            System.out.print(result + " ");
        }
    }
}
