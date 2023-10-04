public class ArrayTasks {
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
        multiDimensionalArray();
    }
}
