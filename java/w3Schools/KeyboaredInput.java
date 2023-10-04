import java.util.*;

public class KeyboaredInput {
    static Scanner input = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter a number: ");
        int number = input.nextInt();
        System.out.println("You entered " + number);
    }
}
