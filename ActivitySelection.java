import java.util.Scanner;

public class ActivitySelection {
    static class AC {
        int start, finish;
    }

    static void Merge(AC[] mainArray, int low, int mid, int high) {
        AC mergeArray[] = new AC[high - low + 1];

        int index_1 = low, index_2 = mid + 1, mergeIndex = 0;

        while (index_1 <= mid && index_2 <= high) {
            if (mainArray[index_1].finish < mainArray[index_2].finish) {
                mergeArray[mergeIndex++] = mainArray[index_1++];
            } else {
                mergeArray[mergeIndex++] = mainArray[index_2++];
            }
        }

        while (index_1 <= mid) {
            mergeArray[mergeIndex++] = mainArray[index_1++];
        }

        while (index_2 <= high) {
            mergeArray[mergeIndex++] = mainArray[index_2++];
        }

        for (int i = 0; i < mergeArray.length; i++) {
            mainArray[i + low] = mergeArray[i];
        }
    }

    static void MergeSort(AC mainArray[], int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;

            MergeSort(mainArray, low, mid);
            MergeSort(mainArray, mid + 1, high);

            Merge(mainArray, low, mid, high);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter number of Activities : ");
        int numberOfActivity = sc.nextInt();

        AC Activity[] = new AC[numberOfActivity];

        for (int i = 0; i < Activity.length; i++) {
            Activity[i] = new AC();

            System.out.print("\nActivity [" + (i + 1) + "] - start and finish time : ");
            Activity[i].start = sc.nextInt();
            Activity[i].finish = sc.nextInt();

        }

        MergeSort(Activity, 0, Activity.length - 1);
        for (int i = 0; i < Activity.length; i++) {
            System.out.print("\n " + Activity[i].start + " - " + Activity[i].finish);
        }
        System.out.println("\n");

        AC solutionArray[] = new AC[numberOfActivity];
        int solutionIndex = 0;

        solutionArray[solutionIndex] = Activity[solutionIndex];

        for (int i = 1; i < numberOfActivity; i++) {
            if (Activity[i].start >= solutionArray[solutionIndex].finish) {
                solutionArray[++solutionIndex] = Activity[i];
            }
        }

        System.out.println();
        for (int i = 0; i <= solutionIndex; i++) {
            System.out.print("\n " + solutionArray[i].start + " - " + solutionArray[i].finish);
        }
    }
}