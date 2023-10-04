/*public class frlp {
    public static void main(String[] args) {
        for (int i = 0; i <= 10; i = i + 2) {
          System.out.println(i);
    }
    }
    
}*/

//nested for
/*public class frlp {
  public static void main(String[] args) {
    // Outer loop.
    for (int i = 1; i <= 2; i++) {
      System.out.println("Outer: " + i); // Executes 2 times
      
      // Inner loop
      for (int j = 1; j <= 3; j++) {
        System.out.println(" Inner: " + j); // Executes 6 times (2 * 3)
        }
    }
}
}*/


public class LoopBreak {
    public static void main(String[] args) {
      for (int i = 0; i < 10; i++) {
        if (i == 4) {
          break;
        }
        System.out.println(i);
    }
    }
  }
