public class ArrayTasks {
    public static int[] reverse(int[] arr) {
        int[] reversed = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            reversed[i] = arr[arr.length - i - 1];
        }
        return reversed;
    }

    public static int[] rotate(int[] arr, int n) {
        int[] rotated = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            rotated[(i + n) % arr.length] = arr[i];
        }
        return rotated;
    }

    public static int[] sort(int[] arr) {
        int[] sorted = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            int min = Integer.MAX_VALUE;
            int minIndex = 0;
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] < min) {
                    minIndex = j;
                    min = arr[j];
                }
            }
            sorted[i] = min;
            arr[minIndex] = Integer.MAX_VALUE;
        }
        return sorted;
    }

    public static void display(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i != arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
    }

    public static void multiDimensionalArray() {
        int[][] myNumbers = { { 1, 2, 3, 4 }, { 5, 6, 7 } };
        for (int i = 0; i < myNumbers.length; ++i) {
            for (int j = 0; j < myNumbers[i].length; ++j) {
                System.out.print(myNumbers[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        display(arr);
        display(reverse(arr));
        display(rotate(arr, 2));
        display(sort(arr));
        multiDimensionalArray();
    }
}