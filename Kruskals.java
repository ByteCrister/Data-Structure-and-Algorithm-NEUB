import java.util.*;

class KruskalsClass {

    Scanner sc = new Scanner(System.in);

    private int sumOfWeight = 0, minimumEdges = 0;
    private int numberOfVertex, numberOfEdges;
    private int parentOf[];

    private LinkedList<Edge> Graph = new LinkedList<>();

    KruskalsClass(int v, int e) {

        numberOfVertex = v;
        numberOfEdges = e;

    }

    static class Edge implements Comparable<Edge> {
        private int source, destination, weight;

        Edge(int s, int d, int w) {
            source = s;
            destination = d;
            weight = w;
        }

        @Override
        public int compareTo(Edge NODE) {
            return Integer.compare(this.weight, NODE.weight);
        }

    }

    private void initializeParent() {

        parentOf = new int[numberOfVertex + 1];
        for (int i = 0; i < parentOf.length; i++) {
            parentOf[i] = i;
        }
    }

    private int FindParent(int node) {
        if (node == parentOf[node]) {
            return node;
        } else {
            return FindParent(parentOf[node]);
        }
    }

    void runKruskal() {
        initializeParent();
        Graph.sort(Comparator.naturalOrder());

        for (int i = 0; i < numberOfEdges; i++) {
            int parentOfSource = FindParent(Graph.get(i).source);
            int parentOfDestination = FindParent(Graph.get(i).destination);

            if (parentOfDestination != parentOfSource) {
                parentOf[parentOfDestination] = parentOfSource;
                sumOfWeight += Graph.get(i).weight;
                ++minimumEdges;
            }

            if (minimumEdges == numberOfVertex - 1) {
                break;
            }
        }

        System.out.print("\nMinimum cost : " + sumOfWeight);
    }

    void UnDirected() {
        System.out.println("\nCreating Undirected Graph ... ");

        for (int i = 1; i <= numberOfEdges; i++) {
            System.out.print("\n"+i+ ") Node1 - Node2 - weight : ");
            Graph.add(new Edge(sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
        System.out.println();
    }

    void printGraph() {
        System.out.println("\nYour constructed Graph ... ");
        for (int i = 0; i < numberOfEdges; i++) {
            System.out.print(
                    "\n" + Graph.get(i).source + " -- " + Graph.get(i).destination + " -> " + Graph.get(i).weight);
        }
        System.out.println();
    }
}

public class Kruskals {
    public static void main(String[] args) {

        System.out.print("\nEnter number of vertex and edges : ");
        Scanner sc = new Scanner(System.in);

        KruskalsClass ob = new KruskalsClass(sc.nextInt(), sc.nextInt());
        ob.UnDirected();
        ob.printGraph();
        ob.runKruskal();


    }
}
