//wide casting
/*public class cstng {
    public static void main(String[] args) {
        int myInt = 9;
        double myDouble = myInt; // Automatic casting: int to double
    
        System.out.println(myInt);
        System.out.println(myDouble);
    }
    
}*/

//narrow casting
public class ExplicitCast {
    public static void main(String[] args) {
        double myDouble = 9.78d;
        int myInt = (int) myDouble; // Explicit casting: double to int

        System.out.println(myDouble);
        System.out.println(myInt);
    }
}
