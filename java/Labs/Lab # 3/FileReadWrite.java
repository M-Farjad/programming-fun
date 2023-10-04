import java.util.*;
import java.io.*;

public class FileReadWrite {
    // FileReadWrite() throws IOException {
    //     in = new Scanner(new File("employeeData.txt"));
    //     out = new PrintWriter(new FileWriter("prog.out"));
    // }
    // ~FileReadWrite() {
    //     in.close();
    //     out.close();
    // }
    static Scanner in;
    static PrintWriter out;
    static void FileHandle() throws IOException {
        Scanner in = null;
        in = new Scanner(new File("employeeData.txt"));
        String firstName, lastName;
        double hoursWorked, payRate, wages;

        firstName = in.next();
        lastName = in.next();

        System.out.println("Name: " + firstName + " " + lastName);

        hoursWorked = in.nextDouble();
        payRate = in.nextDouble();

        wages = hoursWorked * payRate;

        in.close();

        PrintWriter out = new PrintWriter(new FileWriter("prog.out"));
        out.println("The pay Check is: $"+wages);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        FileHandle();
    }
}
