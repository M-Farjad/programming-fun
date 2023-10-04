import java.time.*;
import java.time.format.DateTimeFormatter;

public class Date {
    public static void getLocalDate() {
        LocalDate myObj = LocalDate.now(); // Create a date object
        System.out.println("Local Date: " + myObj); // Display the current date
    }

    public static void getLocalTime() {
        LocalTime myObj = LocalTime.now(); // Create a date object
        System.out.println("Local Time: " + myObj); // Display the current date
    }

    public static void getLocalDateTime() {
        LocalDateTime myObj = LocalDateTime.now(); // Create a date object
        System.out.println("Local Date Time: " + myObj); // Display the current date
    }

    public static void getFormattedDate() {
        LocalDateTime myDateObj = LocalDateTime.now();
        System.out.println("Before formatting: " + myDateObj);
        DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("d-M-yy H:m:s");

        String formattedDate = myDateObj.format(myFormatObj);
        System.out.println("After formatting: " + formattedDate);
    }

    public static void getMonth() {
        Month month = Month.from(LocalDate.now());
        System.out.println("Month: " + month);
    }

    public static void getDayOfWeek() {
        DayOfWeek day = DayOfWeek.from(LocalDate.now());
        System.out.println("Day: " + day);
    }

    public static void getYear() {
        Year year = Year.from(LocalDate.now());
        System.out.println("Year: " + year);
    }

    public static void getPeriod() {
        LocalDate today = LocalDate.now();
        LocalDate birthday = LocalDate.of(2002, 12, 20);
        Period p = Period.between(birthday, today);
        System.out.println("Age: " + p.getYears());
    }

    public static void getDuration() {
        LocalTime time = LocalTime.now();
        Duration twoHours = Duration.ofHours(2);
        LocalTime later = time.plus(twoHours);
        Duration duration = Duration.between(time, later);
        System.out.println("Duration: " + duration);
    }

    public static void main(String[] args) {
        getLocalDate();
        getLocalTime();
        getLocalDateTime();
        getFormattedDate();
        getMonth();
        getDayOfWeek();
        getYear();
        getPeriod();
        getDuration();
    }
}
