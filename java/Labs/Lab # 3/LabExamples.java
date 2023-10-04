import java.util.*;

public class LabExamples {
    static double cgpa = 2.0d;
    static Scanner in = new Scanner(System.in);

    public static void oneWay() {
        char grade = 'C';
        if (cgpa < 2.00) {
            grade = 'F';
        }
        System.out.println(grade);
    }

    public static char twoWay() {
        char section = 'C';
        if (section == 'A') {
            System.out.println("this section is learning Java");
        } else {
            System.out.println("this section is learning C++");
        }
        return section;
    }

    public static void compound() {
        int temp;
        System.out.println("Enter the tempreture: ");
        temp = in.nextInt();
        if (temp > 50) {
            if (temp >= 80) {
                System.out.println("Good day for swimming");
            } else {
                System.out.println("Good day for golfing");
            }
        } else {
            System.out.println("Good day for playing tennis");
        }
    }

    public static void switchExample() {
        char grade = 'C';
        switch (grade) {
            case 'A':
                System.out.println(grade);
                break;

            default:
                System.out.println(grade);
                break;
        }
    }

    public static void whileLoop() {
        int i = 10;
        while (i < 20) {
            System.out.println(i);
            i++;
        }
    }

    public static void forLoop() {
        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {
        oneWay();
        twoWay();
        compound();
        switchExample();
        whileLoop();
        forLoop();
    }
}
