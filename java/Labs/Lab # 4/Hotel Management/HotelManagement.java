import java.util.*;

public class HotelManagement {
    private String hotelName;
    private int noOfEmployees;
    private boolean isOpen;
    private List<Employee> employees;
    private List<Customer> customers;
    private Menu menu;
    private static List<Order> orders;

    public static Order getOrderById(String orderId) {
        for (Order order : orders) {
            if (order.getOrderId() == orderId) {
                return order;
            }
        }
        return null;
    }

    public String getHotelName() {
        return hotelName;
    }

    public int getNumberOfEmployees() {
        return noOfEmployees;
    }

    public boolean isOpen() {
        return isOpen;
    }

    public void open() {
        System.out.println("Hotel is open now.");
        isOpen = true;
    }

    public void close() {
        isOpen = false;
        System.out.println("Hotel is closed now.");
    }

    public HotelManagement(String hotelName) {
        this.hotelName = hotelName;
        this.isOpen = true;
        this.employees = new ArrayList<Employee>();
        this.customers = new ArrayList<Customer>();
        this.menu = new Menu();
        HotelManagement.orders = new ArrayList<Order>();
    }

    public List<Employee> getEmployees() {
        return employees;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public Menu getMenu() {
        return menu;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public void addEmployee(Employee employee) {
        this.employees.add(employee);
        noOfEmployees++;
    }

    public void removeEmployee(Employee employee) {
        this.employees.remove(employee);
        noOfEmployees--;
    }

    public void addCustomer(Customer customer) {
        this.customers.add(customer);
    }

    public void removeCustomer(Customer customer) {
        this.customers.remove(customer);
    }

    public void addOrder(Order order) {
        HotelManagement.orders.add(order);
    }

    public void removeOrder(Order order) {
        HotelManagement.orders.remove(order);
    }
}
