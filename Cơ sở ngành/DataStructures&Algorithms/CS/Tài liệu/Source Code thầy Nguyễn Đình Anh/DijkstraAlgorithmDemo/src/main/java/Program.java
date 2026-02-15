public class Program {
    public static void main(String[] args) {
        Graph graph = new Graph(5);

        // Adding edges with weights
        graph.addEdge(0, 1, 10);
        graph.addEdge(0, 4, 5);
        graph.addEdge(1, 2, 1);
        graph.addEdge(2, 3, 4);
        graph.addEdge(3, 4, 2);
        graph.addEdge(4, 1, 3);
        graph.addEdge(4, 2, 9);

        // Running Dijkstra's algorithm from vertex 0 with path tracing
        graph.dijkstraWithPath(0);//xuat phat tu dinh 0
    }
}
