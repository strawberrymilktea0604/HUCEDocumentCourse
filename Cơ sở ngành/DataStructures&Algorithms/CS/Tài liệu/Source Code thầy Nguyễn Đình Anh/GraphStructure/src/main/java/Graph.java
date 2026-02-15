import java.util.*;

public class Graph {
    private int numVertices;
    private List<List<Integer>> adjacencyList;
    //danh sach cac dinh va ket noi giua cac dinh
    // Constructor to initialize the graph
    //
    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjacencyList = new ArrayList<>(numVertices);

        // Initialize each adjacency list for each vertex
        for (int i = 0; i < numVertices; i++) {
            adjacencyList.add(new LinkedList<>());
        }
    }

    // Method to add an edge between two vertices
    public void addEdge(int source, int destination) {
        adjacencyList.get(source).add(destination);
        adjacencyList.get(destination).add(source); // For undirected graph
    }

    // Breadth-First Search (BFS) algorithm starting from a given source vertex
    public void breadthFirstSearch(int startVertex) {
        // Boolean array to keep track of visited vertices
        boolean[] visited = new boolean[numVertices];

        // Queue for BFS
        Queue<Integer> queue = new LinkedList<>();

        // Mark the start vertex as visited and enqueue it
        visited[startVertex] = true;
        queue.add(startVertex);

        System.out.print("BFS Traversal starting from vertex " + startVertex + ": ");

        while (!queue.isEmpty()) {
            // Dequeue a vertex from the queue
            int currentVertex = queue.poll();
            System.out.print(currentVertex + " ");

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex has not been visited, mark it as visited and enqueue it
            for (int neighbor : adjacencyList.get(currentVertex)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        System.out.println();
    }

    // Method to display the graph
    public void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            System.out.print("Vertex " + i + " is connected to: ");
            for (Integer v : adjacencyList.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        //Mô tả mạng XH gồm 5 người dùng.
        Graph graph = new Graph(5);
    //Phương thức: thêm mới 1 đỉnh vào đồ thị

        // Add edges
        graph.addEdge(0, 1);
        //nguoi so 0 ket ban với ng 1
        graph.addEdge(0, 4);
        //nguoi so 0 ket ban voi nguoi 4
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);

        // Display the graph
        graph.printGraph();

        // Perform BFS starting from vertex 0
    //    graph.breadthFirstSearch(0);
    }
}
