import java.util.*;


public class TopologicalSortWithDFS_1 {
    static Scanner sc = new Scanner(System.in);
    static LinkedList<Integer>AdjacentList[] ;
    static LinkedList<Integer>SortedTaskList = new LinkedList<>();
    static int numberOfEdges;
    static int numberOfNodes;

    static int white = 0;
    static int grey=1;
    static int black=-1;
    static int color[] ;

    static void initialization(int nodes, int edges){
        numberOfNodes = nodes;
        numberOfEdges = edges;
        
        color = new int[numberOfNodes+1];
        Arrays.fill(color, white);

        AdjacentList = new LinkedList[numberOfNodes+1];
        for(int i=0; i<=numberOfNodes; i++){
            AdjacentList [i]= new LinkedList<>();
        }

        for(int i=1; i<=numberOfEdges; i++){
            System.out.print("\n Edge_"+i+" node 1- node 2 : ");
            AdjacentList[sc.nextInt()].add(sc.nextInt());
        }
    }

    static void DFS(int currentNode){

        color[currentNode] = grey;
        for(int i=0; i<AdjacentList[currentNode].size(); i++){
            int nextAdjacentNode = AdjacentList[currentNode].get(i);
            if(color[nextAdjacentNode]== white){
                DFS(nextAdjacentNode);
            }
        }

        color[currentNode] = black;
        SortedTaskList.add(currentNode);
    }


    static void TopologicalSort(){

        for(int i=1; i<=numberOfNodes; i++){
            if(color[i] ==white){
                DFS(i);
            }
        }

        Collections.reverse(SortedTaskList);
        System.out.print("\nThe task list : "+SortedTaskList);

        
    }

    public static void main(String[] args) {

        
        System.out.print("\nEnter number of nodes and edges : ");
        initialization(sc.nextInt(), sc.nextInt());

        TopologicalSort();
    }

}
