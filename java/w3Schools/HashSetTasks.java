import java.util.*;

public class HashSetTasks {
    static HashSet<String> cars = new HashSet<String>();

    public static void printSet(HashSet<String> set) {
        // Create a HashSet object called cars
        // Add elements to HashSet
        cars.add("Volvo");
        cars.add("BMW");
        cars.add("Ford");
        cars.add("BMW");
        cars.add("Mazda");
        System.out.println(cars);
        for (String value : cars) {
            System.out.println(value);
        }
    }

    public static void getValue(String value) {
        System.out.println(cars.contains(value));
    }

    public static void removeValue(String value) {
        cars.remove(value);
    }

    public static void clearSet() {
        cars.clear();
    }

    public static void sizeSet() {
        System.out.println(cars.size());
    }

    public static void loopSet() {
        for (String i : cars) {
            System.out.println(i);
        }
    }

    public static void cloneSet() {
        HashSet<String> newCars = new HashSet<String>();
        newCars = (HashSet<String>) cars.clone();
        System.out.println(newCars);
    }

    public static void addValue(String value) {
        cars.add(value);
    }

    public static void addAllValues(HashSet<String> set) {
        cars.addAll(set);
    }

    public static void retainAllValues(HashSet<String> set) {
        cars.retainAll(set);
    }

    public static void main(String[] args) {
        printSet(cars);
        getValue("Volvo");
        loopSet();
        cloneSet();
        retainAllValues(cars);
        loopSet();
    }
}
