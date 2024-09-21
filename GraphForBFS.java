import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class GraphClassForBFS {
    /* Graph components */
    Scanner sc = new Scanner(System.in);

    private LinkedList<Integer> AdjacentList[];
    private LinkedList<Integer> In_Degree[];
    private LinkedList<Integer> Out_Degree[];

    int numberOfNodes, numberOfEdges;
    // ____________________________________________

    GraphClassForBFS(int nodes, int edges) {
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

    /********** BFS components **********/
    private int parentOf[];
    private int nodeVisitedOrNot[];
    private int distanceFromSourceTo[];

    void runBFS(int sourceNode) {
        parentOf = new int[numberOfNodes + 1];
        nodeVisitedOrNot = new int[numberOfNodes + 1];
        distanceFromSourceTo = new int[numberOfNodes + 1];

        System.out.println("\nRunning DFS....");

        Arrays.fill(parentOf, 0);
        Arrays.fill(nodeVisitedOrNot, 0);
        Arrays.fill(distanceFromSourceTo, 0);

        Queue<Integer> Q = new LinkedList<>();

        Q.add(sourceNode);
        nodeVisitedOrNot[sourceNode] = 1;

        int currentNode, adjacentNode;
        System.out.print("Visited nodes : ");
        while (!Q.isEmpty()) {

            currentNode = Q.peek();
            Q.remove();
            System.out.print(currentNode + " ");


            for (int i = 0; i < AdjacentList[currentNode].size(); i++) {

                adjacentNode = AdjacentList[currentNode].get(i);
                if (nodeVisitedOrNot[adjacentNode] == 0) {

                    Q.add(adjacentNode);

                    nodeVisitedOrNot[adjacentNode] = 1;

                    parentOf[adjacentNode] = currentNode;

                    distanceFromSourceTo[adjacentNode] = distanceFromSourceTo[currentNode] + 1;
                }
            }
        }
    }

    void printPath(int s, int d) {
        System.out.print("\nPrinting DFS Path : ");
        print_BFS_Path(s, d);
    }

    void print_BFS_Path(int source, int destination) {

        if (source == destination) {
            System.out.print(" -> " + destination);
        } else if (parentOf[destination] == 0) {
            System.out.print(" No path exits");
        } else {
            print_BFS_Path(source, parentOf[destination]);
            System.out.print(" -> " + destination);
        }
    }

    void printCostOfNodes() {
        System.out.println("\nCost of every nodes ...");
        for (int i = 1; i <= numberOfNodes; i++) {
            System.out.println(i + " : " + distanceFromSourceTo[i]);
        }
    }
    // ____________________________________________________

}

public class GraphForBFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of nodes and edges : ");
        GraphClassForBFS ob = new GraphClassForBFS(sc.nextInt(), sc.nextInt());

        // ob.createDirectedGraph();
        ob.createUnDirectedGraph();
        ob.printGraph();
        ob.runBFS(1);
        ob.printPath(1, 6);
        ob.printCostOfNodes();

    }
}
