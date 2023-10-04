import java.util.*;

public class LinkedListTasks {
    static LinkedList<String> cars = new LinkedList<String>();

    public static void printList(LinkedList<String> list) {
        // Create a LinkedList object called cars
        // Add elements to LinkedList
        cars.add("Volvo");
        cars.add("BMW");
        cars.add("Ford");
        cars.add("BMW");
        cars.add("Mazda");
        System.out.print(cars);
        System.out.println();
        for (String value : cars) {
            System.out.printf(value + ',');
        }
        System.out.println();
    }

    public static void getValue(String value) {
        System.out.print(cars.contains(value));
        System.out.println();
    }

    public static void clearList() {
        cars.clear();
    }

    public static void sizeList() {
        System.out.print(cars.size());
        System.out.println();

    }

    public static void loopList() {
        for (String i : cars) {
            System.out.print(i + ',');
        }
        System.out.println();
    }

    public static void addFirst(String value) {
        cars.addFirst(value);
    }

    public static void addLast(String value) {
        cars.addLast(value);
    }

    public static void removeFirst() {
        cars.removeFirst();
    }

    public static void removeLast() {
        cars.removeLast();
    }

    public static void removeIndex(int index) {
        cars.remove(index);
    }

    public static void removeValue(String value) {
        cars.remove(value);
    }

    public static void setIndex(int index, String value) {
        cars.set(index, value);
    }

    public static void getIndex(int index) {
        System.out.print(cars.get(index));
        System.out.println();
    }

    public static void getFirst() {
        System.out.print(cars.getFirst());
        System.out.println();
    }

    public static void getLast() {
        System.out.print(cars.getLast());
        System.out.println();
    }

    public static void main(String[] args) {
        // printList(cars);
        // getValue("Volvo");
        loopList();
        addFirst("Toyota");
        addLast("Honda");
        addLast("Audi");
        loopList();
        // loopList();
        // removeFirst();
        // removeLast();
        // loopList();
        removeIndex(2);
        loopList();
        removeValue("BMW");
        // loopList();
        // setIndex(1, "Audi");
        // loopList();
        // getIndex(1);
        // getFirst();
        // getLast();
        // clearList();
        // sizeList();
    }
}
