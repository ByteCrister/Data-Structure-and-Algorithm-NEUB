
class Run_LCS {
    String X, Y;
    int row, column;
    int LCS[][];
    int Direction[][], diagonal = 1, left = 2, up = 3;

    Run_LCS(String x, String y) {
        X = x;
        Y = y;

        row = X.length() + 1;
        column = Y.length() + 1;

        LCS = new int[row][column];
        Direction = new int[row][column];

        Find_LCS();
    }

    private void Find_LCS() {
        for (int i = 0; i < column; i++) {
            LCS[0][i] = 0;
        }
        for (int i = 0; i < row; i++) {
            LCS[i][0] = 0;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (X.charAt(i - 1) == Y.charAt(j - 1)) {
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                    Direction[i][j] = diagonal;
                } else {
                    if (LCS[i][j - 1] > LCS[i - 1][j]) {
                        LCS[i][j] = LCS[i][j - 1];
                        Direction[i][j] = left;
                    } else if (LCS[i][j - 1] < LCS[i - 1][j]) {
                        LCS[i][j] = LCS[i - 1][j];
                        Direction[i][j] = up;
                    } else {
                        LCS[i][j] = LCS[i - 1][j];
                        Direction[i][j] = up;

                    }
                }
            }
        }

        System.out.println();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                System.out.print(LCS[i][j] + " ");
            }
            System.out.println();
        }

        Find_Sequence(row - 1, column - 1);
    }

    void Find_Sequence(int i, int j) {

        if (i == 0 || j == 0) 
            return;

         else if (Direction[i][j] == diagonal) {
            Find_Sequence(i - 1, j - 1);
            System.out.println(X.charAt(i - 1));
        } else if (Direction[i][j] == left) {
            Find_Sequence(i, j - 1);
        } else {
            Find_Sequence(i-1, j );
        }

    }

}

public class LCS {
    public static void main(String[] args) {

        new Run_LCS("ACADB", "CBDA");

    }
}
