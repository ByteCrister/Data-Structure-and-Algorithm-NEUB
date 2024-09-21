import java.util.Scanner;

class KnapsackComponents {
    Scanner sc = new Scanner(System.in);
    int values[], weights[], numberOfItems;
    int Table[][], row, column;

    KnapsackComponents(int n, int w) {
        numberOfItems = n;
        row = numberOfItems + 1;
        column = w + 1;

        Table = new int[row][column];
        values = new int[numberOfItems];
        weights = new int[numberOfItems];

        enterValues();
    }

    private void enterValues() {
        for (int i = 0; i < numberOfItems; i++) {
            System.out.print("\nValue - Weight : ");
            values[i] = sc.nextInt();
            weights[i] = sc.nextInt();
        }
        constructTable();
    }

    private void constructTable() {
        for (int i = 0; i < row; i++) {
            Table[i][0] = 0;
        }
        for (int i = 0; i < column; i++) {
            Table[0][i] = 0;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (j - weights[i - 1] < 0) {
                    Table[i][j] = Table[i - 1][j];

                } else {

                    Table[i][j] = Math.max(Table[i - 1][j], values[i - 1] + Table[i - 1][j - weights[i - 1]]);
                }
            }
        }
        
        printTable();
    }

    private void printTable(){
        System.out.println();
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                System.out.print(Table[i][j]+" ");
            }
            System.out.println();
        }

        printItems();
    }

    private void printItems(){
        int i = row - 1, j = column -1;
        System.out.println();

        while(i>0 && j>0){
            if(Table[i][j] == Table[i-1][j]){
              i--;
            }else{
                System.out.print("\nItem : "+i);
                j-=weights[i-1];
                i--;
            }
        }
    }

}

public class Knapsack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of items and capacity: ");
        new KnapsackComponents(sc.nextInt(), sc.nextInt());
    }
}
