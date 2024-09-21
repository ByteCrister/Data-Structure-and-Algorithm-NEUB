import java.util.Scanner;

public class MaximumChain {

    static int parent[];
    static int chainLength[];

    static int findParent(int node) {
        if (node == parent[node]) {
            return node;
        } else {
            return parent[node] = findParent(parent[node]);
        }
    }

    static void union(int src, int des) {
        int srcParent = findParent(src);
        int desParent = findParent(des);

        if (srcParent == desParent) {
            // They are already in the same chain
            chainLength[srcParent]++;
        } else {
            // Combine two chains
            parent[desParent] = srcParent;
            chainLength[srcParent] += chainLength[desParent] + 1;
        }
    }

    static int getMaxChainLength(int nodes) {
        int maxLength = 0;
        for (int i = 0; i < nodes; i++) {
            maxLength = Math.max(maxLength, chainLength[i]);
        }
        return maxLength;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of creatures and predator-prey relations: ");
        int creatures = sc.nextInt();
        int relations = sc.nextInt();

        parent = new int[creatures];
        chainLength = new int[creatures];

        for (int i = 0; i < creatures; i++) {
            parent[i] = i;
            chainLength[i] = 0;
        }

        for (int i = 0; i < relations; i++) {
            System.out.print("\nEnter predator and prey: ");
            union(sc.nextInt(), sc.nextInt());
        }

        int maxLength = getMaxChainLength(creatures);
        System.out.println("Size of the largest alimentary chain: " + maxLength);
    }
}
