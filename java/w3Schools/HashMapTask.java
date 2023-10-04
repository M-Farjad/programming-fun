import java.util.*;

public class HashMapTask {
    static HashMap<String, String> capitalCities = new HashMap<String, String>();

    public static void printMap(Map<String, String> map) {
        // Create a HashMap object called capitalCities
        // Add keys and values (Country, City)
        capitalCities.put("England", "London");
        capitalCities.put("Germany", "Berlin");
        capitalCities.put("Norway", "Oslo");
        capitalCities.put("USA", "Washington DC");
        System.out.println(capitalCities);
    }

    public static void getValue(String key) {
        System.out.println(capitalCities.get(key));
    }

    public static void removeValue(String key) {
        capitalCities.remove(key);
    }

    public static void clearMap() {
        capitalCities.clear();
    }

    public static void sizeMap() {
        System.out.println(capitalCities.size());
    }

    public static void checkKey(String key) {
        System.out.println(capitalCities.containsKey(key));
    }

    public static void checkValue(String value) {
        System.out.println(capitalCities.containsValue(value));
    }

    public static void replaceValue(String key, String value) {
        capitalCities.replace(key, value);
    }

    public static void replaceValue(String key, String oldValue, String newValue) {
        capitalCities.replace(key, oldValue, newValue);
    }

    public static void loopMap() {
        for (String i : capitalCities.keySet()) {
            System.out.println("key: " + i + ", value: " + capitalCities.get(i));
        }
    }

    public static void main(String[] args) {
        printMap(capitalCities);
        getValue("England");
        loopMap();
    }
}