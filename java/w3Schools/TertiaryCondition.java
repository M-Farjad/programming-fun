/*public class ifst {
    public static void main(String[] args) {
    int time = 20;
    if (time < 18) {
      System.out.println("Good day.");
    } else {
      System.out.println("Good evening.");
    }
    }

}*/

public class TertiaryCondition {
  public static void main(String[] args) {
    int time = 20;
    String result;
    result = (time < 18) ? "Hello" : "Bye";
    System.out.println(result);
  }
}