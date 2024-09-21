import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

class GraphClassForDFS {

    /* Graph components */
    Scanner sc = new Scanner(System.in);

    private LinkedList<Integer> AdjacentList[];
    private LinkedList<Integer> In_Degree[];
    private LinkedList<Integer> Out_Degree[];

    int numberOfNodes, numberOfEdges;
    // ____________________________________________

    GraphClassForDFS(int nodes, int edges) {
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
    // _____________________________________________________________

    /*********** DFS components **********/
    private int white = 0, gray = 1, black = -1;
    private int colorOf[];
    private int distanceFromSourceTo[], parentOf[];
    private int time = -1, startTimeOf[], endTimeOf[];
    private LinkedList<Integer> orderOfTasks;
    private boolean hasCycleOrNot;

    void runDFS() {
        System.out.println("DFS running ... ");

        colorOf = new int[numberOfNodes + 1];
        parentOf = new int[numberOfNodes + 1];
        distanceFromSourceTo = new int[numberOfNodes + 1];
        startTimeOf = new int[numberOfNodes + 1];
        endTimeOf = new int[numberOfNodes + 1];
        orderOfTasks = new LinkedList<>();

        Arrays.fill(colorOf, white);
        Arrays.fill(parentOf, -1);
        Arrays.fill(distanceFromSourceTo, 0);
        // hasCycleOrNot = false;

        for (int i = 1; i <= numberOfNodes; i++) {
            if (colorOf[i] == white)
                traverseOfAdjacent(i, -1); // -1 for initial null parent
        }

        if (hasCycleOrNot) {
            System.out.println("\nHas a cycle in the graph");
        } else {
            System.out.println("\nNo cycles exits in the graph");
        }

        for (int i = 1; i <= numberOfNodes; i++) {
            System.out.print("\n Node " + i + ")  start : " + startTimeOf[i] + "  -   end : " + endTimeOf[i]);
        }
        System.out.println();

        Collections.reverse(orderOfTasks);
        System.out.print("\nOrder of Tasks : " + orderOfTasks);

    }

    private void traverseOfAdjacent(int currentNode, int parentOfCurrentNode) {

        startTimeOf[currentNode] = ++time;
        colorOf[currentNode] = gray;

        for (int i = 0; i < AdjacentList[currentNode].size(); i++) {

            int adjacentNode = AdjacentList[currentNode].get(i);

            if (colorOf[adjacentNode] == white) {

                traverseOfAdjacent(adjacentNode, currentNode);

                distanceFromSourceTo[adjacentNode] = distanceFromSourceTo[currentNode] + 1;

                parentOf[adjacentNode] = currentNode;

            } else if (colorOf[adjacentNode] == gray && adjacentNode != parentOfCurrentNode) {

                hasCycleOrNot = true;
            }
        }

        endTimeOf[currentNode] = ++time;
        colorOf[currentNode] = black;
        orderOfTasks.add(currentNode);
        System.out.println("-> " + currentNode);
    }

    void print_Path(int s, int d) {
        System.out.print("\nDFS path : ");
        print_DFS_Path(s, d);
    }

    private void print_DFS_Path(int source, int destination) {
        if (source == destination) {
            System.out.print("-> " + destination);
        } else if (parentOf[destination] == -1) {
            System.out.print("-> No path exits");
        } else {
            print_DFS_Path(source, parentOf[destination]);
            System.out.print("-> " + destination);
        }
    }

}
// _______________________________________________

public class GraphForDFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of nodes and edges : ");
        GraphClassForDFS ob = new GraphClassForDFS(sc.nextInt(), sc.nextInt());

        // ob.createDirectedGraph();
        ob.createUnDirectedGraph();
        ob.printGraph();
        ob.runDFS();
        // ob.print_Path(1,6);
    }
}
