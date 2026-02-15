import java.util.*;

class Node implements Comparable<Node> {
    public int vertex;//luu dinh
    public int weight;//trong so

    public Node(int vertex, int weight) {
        this.vertex = vertex;
        this.weight = weight;
    }

    // Comparator for priority queue
    //ham dinh nghia khi so sanh 2 gia tri trong so giua cac dinh.
    public int compareTo(Node other) {
        return Integer.compare(this.weight, other.weight);
    }
}

class Graph {
    private int numVertices;
    private List<List<Node>> adjacencyList;//cai dat dua tren danh sach ke

    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjacencyList = new ArrayList<>(numVertices);

        for (int i = 0; i < numVertices; i++) {
            adjacencyList.add(new ArrayList<>());
        }
    }

    // Method to add an edge to the graph
    public void addEdge(int source, int destination, int weight) {
        adjacencyList.get(source).add(new Node(destination, weight));
        adjacencyList.get(destination).add(new Node(source, weight)); // For undirected graph
    }

    // Dijkstra's algorithm with path tracing
    //Giai thuat nhan vao tham so la dinh bat ky, se tim duong di ngan nhat tu dinh do den tat ca cac dinh cua do thi
    public void dijkstraWithPath(int startVertex) {
        // Distances array to store the minimum distance from startVertex
        int[] distances = new int[numVertices];
        Arrays.fill(distances, Integer.MAX_VALUE);//khoi tao mang trong so tai cac dinh la gia tri rat lon
        distances[startVertex] = 0;//trong so tai dinh xuat phat = 0

        // Array to store the previous vertex for path reconstruction
        int[] previous = new int[numVertices];//Mang luu tru cac dinh duoc chon tren duong di, nham truy vet duong di sau nay
        Arrays.fill(previous, -1); // -1 indicates no predecessor

        // Priority queue to select the node with the smallest distance
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();//Su dung hang doi uu tien de luu cac node, thuan tien cho viec lay ra dinh co trong so nho nhat.
        priorityQueue.add(new Node(startVertex, 0));

        while (!priorityQueue.isEmpty()) {
            // Extract the node with the smallest distance
            Node currentNode = priorityQueue.poll();//lay ra dinh hien tai
            int currentVertex = currentNode.vertex;

            // Explore all adjacent vertices (neighbors)
            //duyet qua tat ca cac dinh lien ke (co duong di tu dinh dang xet)
            for (Node neighbor : adjacencyList.get(currentVertex)) {
                int newDist = distances[currentVertex] + neighbor.weight;

                // If a shorter path is found
                if (newDist < distances[neighbor.vertex]) {//so sanh, neu thay trong so moi < trong so hien tai
                    distances[neighbor.vertex] = newDist;//thay the trong so hien tai
                    previous[neighbor.vertex] = currentVertex; // Update the predecessor (luu lai dinh dang xet)
                    priorityQueue.add(new Node(neighbor.vertex, newDist));//add vao queue
                }
            }
        }

        // Print the shortest distances
        //In ra quang duong di ngan nhat tu dinh xuat phat (startVertex) den tat ca cac dinh con lai tren do thi
        System.out.println("Shortest distances from vertex " + startVertex + ":");
        for (int i = 0; i < distances.length; i++) {
            System.out.println("To vertex " + i + " - Distance: " + distances[i]);
        }

        // Print the shortest paths
        //In ra duong di ngan nhat, dua vao viec truy vet trong mang previous
        System.out.println("\nShortest paths from vertex " + startVertex + ":");
        for (int i = 0; i < numVertices; i++) {
            if (i != startVertex) {
                System.out.print("Path to vertex " + i + ": ");
                printPath(i, previous);
                System.out.println(" (Distance: " + distances[i] + ")");
            }
        }
    }


    // Helper function to print the path from the startVertex to the target vertex
    //Ham truy vet quang duong di, viec nay phai truy vet nguoc lai gia tri trong mang previous
    private void printPath(int targetVertex, int[] previous) {
        if (previous[targetVertex] == -1) {
            System.out.print(targetVertex);
            return;
        }
        printPath(previous[targetVertex], previous);//loi goi de quy ham printPath
        System.out.print(" -> " + targetVertex);
    }

}

