import java.util.LinkedList;
import java.util.Scanner;

class GraphClass {

    /* Graph components */
    Scanner sc = new Scanner(System.in);

    private LinkedList<Integer> AdjacentList[];
    private LinkedList<Integer> In_Degree[];
    private LinkedList<Integer> Out_Degree[];

    int numberOfNodes, numberOfEdges;
    // ____________________________________________

    GraphClass(int nodes, int edges) {
        numberOfNodes = nodes;
        numberOfEdges = edges;

        AdjacentList = new LinkedList[numberOfNodes + 1];
        In_Degree = new LinkedList[numberOfNodes + 1];
        Out_Degree = new LinkedList[numberOfNodes + 1];

        initialize();
    }

    private void initialize() {
        for (int i = 0; i <= numberOfNodes; i++) {
            AdjacentList[i] = new LinkedList<>();
            In_Degree[i] = new LinkedList<>();
            Out_Degree[i] = new LinkedList<>();
        }
    }

    void createDirectedGraph() {
        System.out.println("\nEnter edges...");
        for (int i = 1; i <= numberOfEdges; i++) {

            System.out.print("\n" + i + ". Node1 - Node2 : ");
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();

            AdjacentList[node1].add(node2);

            In_Degree[node2].add(node1);
            Out_Degree[node1].add(node2);

        }
    }

    void createUnDirectedGraph() {
        System.out.println("\nEnter edges...");
        for (int i = 1; i <= numberOfEdges; i++) {

            System.out.print("\n" + i + ". Node1 - Node2 : ");
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();

            AdjacentList[node1].add(node2);
            AdjacentList[node2].add(node1);

            In_Degree[node2].add(node1);
            Out_Degree[node1].add(node2);

        }
    }

    void printGraph() {
        System.out.println("\nConstructed Graph : ");
        for (int i = 1; i <= numberOfNodes; i++) {
            System.out.println("Node " + i + " : " + AdjacentList[i]);
        }
    }

}

public class GraphRepresentation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of nodes and edges : ");
        GraphClass ob = new GraphClass(sc.nextInt(), sc.nextInt());

        // ob.createDirectedGraph();
        ob.createUnDirectedGraph();
        ob.printGraph();
    }
}
