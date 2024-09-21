import java.util.*;

class DijkstraClass {

    Scanner sc = new Scanner(System.in);
    private LinkedList<Integer> AdjacentListOf[];
    private LinkedList<Integer> costOfEdge[];

    private int weightOf[];
    private int parentOf[];

    private int numberOfNodes;
    private int numberOfEdges;

    DijkstraClass(int nodes, int edges) {

        numberOfNodes = nodes;
        numberOfEdges = edges;

        AdjacentListOf = new LinkedList[numberOfNodes + 1];
        costOfEdge = new LinkedList[numberOfNodes + 1];

        initialize();
    }

    private void initialize() {

        for (int i = 0; i <= numberOfNodes; i++) {
            AdjacentListOf[i] = new LinkedList<>();
            costOfEdge[i] = new LinkedList<>();
        }

        weightOf = new int[numberOfNodes + 1];
        parentOf = new int[numberOfNodes + 1];

    }

    void createDirectedGraph() {

        System.out.println("\nCreating Directed Graph ... ");

        for (int i = 1; i <= numberOfEdges; i++) {

            System.out.print("\nNode " + i + " )  Node1 - Node2 - cost : ");

            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            int cost = sc.nextInt();

            AdjacentListOf[node1].add(node2);
            costOfEdge[node1].add(cost);

        }
    }

    void createUnDirectedGraph() {

        System.out.println("\nCreating UnDirected Graph ... ");

        for (int i = 1; i <= numberOfEdges; i++) {

            System.out.print("\nNode " + i + " )  Node1 - Node2 - cost : ");

            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            int cost = sc.nextInt();

            AdjacentListOf[node1].add(node2);
            AdjacentListOf[node2].add(node1);
            costOfEdge[node1].add(cost);
            costOfEdge[node2].add(cost);

        }
    }

    /*********************************************/

    static class Node implements Comparable<Node> {

        int node, weight;

        Node(int n, int w) {
            node = n;
            weight = w;
        }

        @Override
        public int compareTo(Node NODE) {
            return Integer.compare(this.weight, NODE.weight);
        }

    }

    void runDijkstra(int sourceNode) {

        PriorityQueue<Node> Q = new PriorityQueue<>();

        Arrays.fill(weightOf, Integer.MAX_VALUE);
        Arrays.fill(parentOf, -1);

        Q.add(new Node(sourceNode, 0));
        weightOf[sourceNode] = 0;

        int currentNode, adjacentNode;

        while (!Q.isEmpty()) {

            currentNode = Q.peek().node;
            Q.remove();

            for (int i = 0; i < AdjacentListOf[currentNode].size(); i++) {

                adjacentNode = AdjacentListOf[currentNode].get(i);

                if (weightOf[currentNode] + costOfEdge[currentNode].get(i) < weightOf[adjacentNode]) {

                    weightOf[adjacentNode] = weightOf[currentNode] + costOfEdge[currentNode].get(i);

                    parentOf[adjacentNode] = currentNode;

                    Q.add(new Node(adjacentNode, weightOf[adjacentNode]));

                }

            }
        }
    }

    void printGraph() {
        System.out.println("\nYour constructed Graph ... ");

        for (int i = 1; i <= numberOfNodes; i++) {

            for (int j = 0; j < AdjacentListOf[i].size(); j++) {

                System.out.print("\n Node " + i + " - Node " + (AdjacentListOf[i].get(j)) + " - cost : " + costOfEdge[i].get(j));

            }
        }
        System.out.println();
    }

    void print_Path(int s, int d) {
        System.out.println("\nShortest path from " + s + " - " + d + " : ");
        Find_Path(s, d);
    }

    private void Find_Path(int source, int destination) {

        if (source == destination) {
            System.out.print(" -> " + destination);
        } else if (parentOf[destination] == -1) {
            System.out.print(" No path exits ");
        } else {
            Find_Path(source, parentOf[destination]);
            System.out.print(" -> " + destination);
        }

    }

}

public class Dijkstra {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of nodes and edges : ");
        DijkstraClass ob = new DijkstraClass(sc.nextInt(), sc.nextInt());

        // ob.createDirectedGraph();
        ob.createUnDirectedGraph();
        ob.printGraph();
        ob.runDijkstra(1);
        ob.print_Path(1, 6);

    }
}
