import java.util.*;

public class Student {

    static Scanner input = new Scanner(System.in);

    final double PASSING_GPA = 2.5;

    public static void main(String[] args) {

        String name;

        int roll_no;
        char section;

        double cgpa;

        System.out.println("Enter Student Name:");
        name = input.next();

        System.out.println("Enter Roll Number: ");
        roll_no = input.nextInt();
        System.out.println("Enter Section: ");
        section = input.next().charAt(0);
        System.out.println("Enter CGPA: ");
        cgpa = input.nextDouble();

        System.out.println("STUDENT INFORMATION");
        System.out.println("Name: " + name);
        System.out.println("Roll#" + roll_no);
        System.out.println("Section: " + section);
        System.out.println("CGPA: " + cgpa);
    }
}