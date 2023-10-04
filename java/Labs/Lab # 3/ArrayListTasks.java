import java.util.*;

public class ArrayListTasks {
    private static ArrayList<String> cars = new ArrayList<String>();
    private int size;

    public ArrayListTasks() {
        cars.add("Volvo");
        cars.add("BMW");
        cars.add("Ford");
        cars.add("Mazda");
        size = cars.size();
    }

    public void printSet() {
        System.out.print("print Set: ");
        for (int i = 0; i < size; i++) {
            System.out.print(cars.get(i) + ',');
        }
        System.out.println();

    }

    public void getValue(String value) {
        System.out.print("Get Value " + value + ": " + cars.contains(value));
        System.out.println();

    }

    public void loopSet() {
        System.out.print("Loop Set: ");
        for (String i : cars) {
            System.out.print(i + ',');
        }
        System.out.println();
    }

    public static void getSorted() {
        ArrayList<String> sortedCars = new ArrayList<String>();
        sortedCars.addAll(0, cars);
        System.out.print("Sorted: ");

        Collections.sort(sortedCars);
        for (String car : sortedCars) {
            System.out.printf(car + ',');
        }
        System.out.println();

    }

    public static void main(String[] args) {
        ArrayListTasks cars = new ArrayListTasks();
        cars.printSet();
        cars.getValue("Volvo");
        cars.loopSet();
        getSorted();
    }
}
