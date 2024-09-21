import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

class ClassForQuestionSolve {
    Scanner sc = new Scanner(System.in);

    private LinkedList<Integer> AdjacentList[];
    private LinkedList<Integer> weightOfEdge[];
    private int costOfNode[];

    private int totalNode, totalEdge;

    private int colorOf[], white = 1, grey = 0, black = -1;

    private int parentOf[];
    private int parentForPathOf[];

    private int parentForComponent[];

    private int component = 0;

    private boolean hasCycleOrNot;

    ClassForQuestionSolve(int n, int e) {
        totalNode = n;
        totalEdge = e;

        initializeGraphComponents();
    }

    private void initializeGraphComponents() {
        colorOf = new int[totalNode];
        parentOf = new int[totalNode];
        costOfNode = new int[totalNode];
        parentForPathOf = new int[totalNode];
        parentForComponent = new int[totalNode];

        Arrays.fill(colorOf, white);
        Arrays.fill(parentOf, -1);
        Arrays.fill(costOfNode, Integer.MAX_VALUE);
        Arrays.fill(parentForPathOf, -1);

        AdjacentList = new LinkedList[totalNode];
        weightOfEdge = new LinkedList[totalNode];

        for (int i = 0; i < totalNode; i++) {
            AdjacentList[i] = new LinkedList<>();
            weightOfEdge[i] = new LinkedList<>();
            parentForComponent[i] = i;
        }

        constructTheGraph();
    }

    private void constructTheGraph() {
        System.out.println("\nConstructing the graph ... ");
        for (int i = 0; i < totalEdge; i++) {
            System.out.print("\nEdge " + (i + 1) + ") Node1 - Node2 - weight : ");
            int node1 = sc.nextInt();
            int node2 = sc.nextInt();
            int weight = sc.nextInt();

            AdjacentList[node1].add(node2);
            AdjacentList[node2].add(node1);

            weightOfEdge[node1].add(weight);
            weightOfEdge[node2].add(weight);

            union(node1, node2);

        }
        System.out.println();
    }

    void QuestionOnePrintGraph() {
        System.out.println("\nThe graph ... ");
        for (int i = 0; i < totalNode; i++) {
            System.out.print("\nNode " + i + "__ adjacency list : " + AdjacentList[i]);
        }
        System.out.println();
    }

    void QuestionTwoDetectingCycle() {

        for (int i = 0; i < totalNode; i++) {
            if (colorOf[i] == white) {
                traverseDFS(i, -1);
            }
        }
        if (hasCycleOrNot) {
            System.out.println("The graph has a cycle");
        } else {
            System.out.println("The graph has no cycle");
        }
    }

    private void traverseDFS(int currentNode, int parentOfCurrentNode) {
        colorOf[currentNode] = grey;

        for (int i = 0; i < AdjacentList[currentNode].size(); i++) {
            int nextAdjacentNode = AdjacentList[currentNode].get(i);
            if (colorOf[nextAdjacentNode] == white) {

                parentOf[nextAdjacentNode] = currentNode;
                traverseDFS(nextAdjacentNode, currentNode);
            } else if (colorOf[currentNode] == grey && nextAdjacentNode != currentNode) {
                hasCycleOrNot = true;
            }
        }

        colorOf[currentNode] = black;
    }

    private static class Node implements Comparable<Node> {

        int node, costOfNode;

        Node(int n, int w) {
            node = n;
            costOfNode = w;
        }

        @Override
        public int compareTo(Node n) {
            return Integer.compare(this.costOfNode, n.costOfNode);
        }

    }

    void QuestionThreeShortestPathAndMinimumCost(int sourceNode) {

        PriorityQueue<Node> Q = new PriorityQueue<>();

        costOfNode[sourceNode] = 0;

        Q.add(new Node(sourceNode, costOfNode[sourceNode]));

        while (!Q.isEmpty()) {
            int currentNode = Q.peek().node;
            Q.remove();

            for (int i = 0; i < AdjacentList[currentNode].size(); i++) {
                int nextAdjacent = AdjacentList[currentNode].get(i);

                if (costOfNode[currentNode] + weightOfEdge[currentNode].get(i) < costOfNode[nextAdjacent]) {
                    costOfNode[nextAdjacent] = costOfNode[currentNode] + weightOfEdge[currentNode].get(i);
                    parentForPathOf[nextAdjacent] = currentNode;
                    Q.add(new Node(nextAdjacent, costOfNode[nextAdjacent]));
                }
            }
        }

        minimumCostForEachNode(sourceNode);

        System.out.print("\n\nShortest path : ");
        printMinimumPath(0, 3);
        System.out.println();
    }

    private void minimumCostForEachNode(int sourceNode) {
        System.out.println("\nCost for each node ... ");
        for (int i = 0; i < totalNode; i++) {
            System.out.print("\n" + sourceNode + " - " + i + " cost__: " + costOfNode[i]);
        }
        System.out.println();
    }

    private void printMinimumPath(int sourceNode, int destinationNode) {
        if (sourceNode == destinationNode) {
            System.out.print("-> " + destinationNode);
        } else if (parentForPathOf[destinationNode] == -1) {
            System.out.print("-> No path");
        } else {
            printMinimumPath(sourceNode, parentForPathOf[destinationNode]);
            System.out.print("-> " + destinationNode);
        }
    }

    void QuestionFourComponents() {
        for (int i = 0; i < totalNode; i++) {
            if (i == parentForComponent[i]) {
                component++;
            }
        }

        System.out.println("\nTotal component : " + component);
    }

    private void union(int source, int destination) {
        int parentOfSource = findParentOf(source);
        int parentOfDestination = findParentOf(destination);

        if (parentOfSource != parentOfDestination) {
            parentForComponent[parentOfDestination] = parentOfSource;
        }
    }

    private int findParentOf(int node) {
        if (node == parentForComponent[node]) {
            return node;
        } else {
            return findParentOf(parentForComponent[node]);
        }
    }
}

public class QuestionSolve {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\n\nEnter number of nodes and edges : ");
        ClassForQuestionSolve ob = new ClassForQuestionSolve(sc.nextInt(), sc.nextInt());

        ob.QuestionOnePrintGraph();
        ob.QuestionTwoDetectingCycle();
        ob.QuestionThreeShortestPathAndMinimumCost(0);
        ob.QuestionFourComponents();

    }
}
