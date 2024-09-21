import java.util.Scanner;

public class MaximalConnectedSubGraph {
    static int parent[];

    static int findParent(int node) {
        if (node == parent[node]) {
            return node;
        } else {
            return parent[node] = findParent(parent[node]);
        }
    }


    static void union(int src, int des){
        int srcParent = findParent(src);
        int desParent = findParent(des);

        if(srcParent == desParent){
            System.out.println("They are already friends");
        }else{
            parent[desParent] = srcParent;
        }
    }

    static void totalSubGraph(int nodes){
        int components = 0;
        for(int i=0; i<nodes; i++){
            System.out.print("\n"+(i+1)+" : "+findParent(i));

            if(i == findParent(i))
            ++components;

        }
        System.out.println("\nTotal sub graph : "+components);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of nodes and relations : ");
        int node = sc.nextInt();
        int relations = sc.nextInt();

        parent = new int[node];
        for (int i = 0; i < node; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < relations; i++) {
            System.out.print("\n"+(i+1)+" node1 - node2 : ");
            union(sc.nextInt(), sc.nextInt());
        }

        totalSubGraph(node);
    }
}
