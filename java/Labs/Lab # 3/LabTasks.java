import java.io.*;
import java.util.*;

public class LabTasks {
    // Task 1 - Sum from file
    public static void sumFromfile() throws FileNotFoundException {
        Scanner in = null;
        PrintWriter out = null;
        in = new Scanner(new File("numbers.txt"));
        out = new PrintWriter(new File("out.txt"));
        int evenTotal = 0;
        int oddTotal = 0;
        while (in.hasNext()) {
            int num = in.nextInt();
            if (num % 2 == 0) {
                evenTotal += num;
            } else {
                oddTotal += num;
            }
        }
        out.println("Even Total: " + evenTotal);
        out.println("Odd Total: " + oddTotal);
        in.close();
        out.close();
    }

    // Task 1 - Fibonacci
    public static void fibonacci(int length) {
        int x = 0, y = 1, total;
        System.out.print(x + "," + y + ",");
        for (int i = 2; i < length; i++) {
            total = x + y;
            System.out.print(total + ",");
            x = y;
            y = total;
        }
    }

    // task 2
    public static void markUpCalc(double price, double markUpPercent, double taxRate) {
        double markUpPrice = price * (markUpPercent / 100);
        double sellingPrice = price + markUpPrice;
        double tax = sellingPrice * (taxRate / 100);
        double finalPrice = sellingPrice + tax;
        System.out.println("Original Price: " + price + "\nMark Up Percentage: " + markUpPercent + "\nSelling Price: "
                + sellingPrice + "\nTax Rate: " + taxRate + "\nTax: " + tax + "\nFinal Price: "
                + finalPrice);
    }

    // task 3
    public static void job(double hourlyPayRate, double noOfHoursPerWeek) {
        double income = hourlyPayRate * noOfHoursPerWeek * 5;
        double tax = income * 0.14;
        double netIncome = income - tax;
        double clothes = netIncome * 0.1;
        double schoolSupplies = netIncome * 0.01;
        double savingsBonds = (netIncome - clothes - schoolSupplies) * 0.25;
        double parentsSavingsBonds = savingsBonds * 0.5;
        System.out.println("Income before tax: " + income);
        System.out.println("Income after tax: " + netIncome);
        System.out.printf("Clothes: %.2f\n", clothes);
        System.out.printf("Supplies: %.2f\n", schoolSupplies);
        System.out.printf("Savings bonds: %.2f\n", savingsBonds);
        System.out.printf("Parent Savings bonds: %.2f", parentsSavingsBonds);
    }

    public static void main(String[] args) throws FileNotFoundException {
        // File Handling
        sumFromfile();

        // Fibonacci
        // fibonacci(10);

        // Store
        // markUpCalc(200, 22, 7);

        // Summer Job
        // job(4, 38);
    }
}
