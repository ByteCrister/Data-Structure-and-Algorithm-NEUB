import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class ClassForLevelFind {
    Scanner sc = new Scanner(System.in);

    private LinkedList<Integer> AdjacentList[];
    private int totalNode, totalEdge;

    private int visited[];

    private int outDegrees[];

    ClassForLevelFind(int n, int e) {
        totalNode = n;
        totalEdge = e;

        initialize();
    }

    private void initialize() {
        AdjacentList = new LinkedList[totalNode];
        visited = new int[totalNode];
        outDegrees = new int[totalNode];

        Arrays.fill(visited, -1);
        Arrays.fill(outDegrees, 0);

        for (int i = 0; i < totalNode; i++) {
            AdjacentList[i] = new LinkedList<>();
        }

        // UnDirected();
        Directed();

    }

    private void UnDirected() {
        System.out.println("\n Create graph ... ");
        for (int i = 0; i < totalEdge; i++) {
            System.out.print("\nNode " + i + " ) node1 - node2 : ");
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();

            AdjacentList[node1].add(node2);
            AdjacentList[node2].add(node1);

            ++outDegrees[node1];
        }
        System.out.println();
        // printGraph();
        // BFStoFindLevel(0);
    }

    private void Directed() {
        System.out.println("\n Create graph ... ");
        for (int i = 0; i < totalEdge; i++) {
            System.out.print("\nNode " + i + " ) node1 - node2 : ");
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();

            AdjacentList[node1].add(node2);

            ++outDegrees[node1];

        }
        System.out.println();
        printGraph();
        BFStoFindLevel(0);
        FindLeaf();

    }

    private void BFStoFindLevel(int sourceNode) {

        int totalLevel = 0;

        System.out.println("\nTraversed nodes ... ");
        Queue<Integer> Q = new LinkedList<>();
        visited[sourceNode] = sourceNode;
        Q.add(sourceNode);
        Q.add(-1);
        System.out.print(sourceNode + " ");
        System.out.println("\nLevel _" + (totalLevel) + "_");

        while (!Q.isEmpty()) {
            int currentNode = Q.peek();
            Q.remove();

            if (currentNode == -1) {
                if (Q.isEmpty()) {
                    break;
                } else {
                    System.out.println("\nLevel _" + (++totalLevel) + "_");
                    Q.add(-1);
                }
            } else {
                for (int i = 0; i < AdjacentList[currentNode].size(); i++) {
                    int nextAdjacent = AdjacentList[currentNode].get(i);
                    if (visited[nextAdjacent] != nextAdjacent) {
                        Q.add(nextAdjacent);
                        visited[nextAdjacent] = nextAdjacent;
                        System.out.print(nextAdjacent + " ");
                    }
                }
            }
        }
        System.out.println();

    }

    private void printGraph() {
        System.out.println("\nConstructed graph ... ");
        for (int i = 0; i < totalNode; i++) {
            System.out.println("Node " + i + " ) : " + AdjacentList[i]);
        }
        System.out.println();
    }

    private void FindLeaf() {
        System.out.print("\nLeaf nodes : ");
        for (int i = 0; i < totalNode; i++) {
            if (outDegrees[i] == 0) {
                System.out.print(" " + i);
            }
        }
        System.out.println();
    }

}

public class LevelAndLeafFind {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter number of nodes and edges : ");

        new ClassForLevelFind(sc.nextInt(), sc.nextInt());

    }
}
