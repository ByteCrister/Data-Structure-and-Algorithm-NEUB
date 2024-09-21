import java.util.*;

class Disjoin_Set {

    private static int parentOfNodes[];

    Disjoin_Set(int nodes) {
        parentOfNodes = new int[nodes + 1];

        for (int i = 1; i < parentOfNodes.length; i++) {
            parentOfNodes[i] = i;
        }
    }

    public void Union(int a, int b) {
        int node1 = findRepresentative(a);
        int node2 = findRepresentative(b);

        if (node1 == node2) {
            System.out.println("They are already friends");
        } else {
            parentOfNodes[node1] = node2;
        }
    }

    public int findRepresentative(int node) {
        if (parentOfNodes[node] == node) {
            return node;
        } else {
            return findRepresentative(parentOfNodes[node]);
        }

    }


    public void printParent(){
        for(int i=1; i<parentOfNodes.length; i++){
            System.out.print("\nNode "+i+" parent-> "+parentOfNodes[i]);
        }
    }
}

public class DisjoinNodes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of nodes and number of relations: ");

        int Nodes = sc.nextInt();
        Disjoin_Set set = new Disjoin_Set(Nodes);
        int relations = sc.nextInt();

        
        for(int i=1; i<=relations; i++){
            System.out.print("\nRelation "+i+" : ");
            set.Union(sc.nextInt(), sc.nextInt());
        }


        //Finding components
        int components=0;
        for(int i=1; i<=Nodes; i++){
            if(set.findRepresentative(i) == i){
                components++;
            }
        }

        System.out.print("\nNumber of components : "+components);
        set.printParent();
    }
}
