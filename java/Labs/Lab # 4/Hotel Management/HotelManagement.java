import java.util.*;

public class HotelManagement {
    private String hotelName;
    private int noOfEmployees;
    private boolean isOpen;
    private List<Employee> employees;
    private List<Customer> customers;
    private Menu menu;
    private List<Order> orders;

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
        isOpen = true;
    }

    public void close() {
        isOpen = false;
    }

    public HotelManagement(String hotelName) {
        this.hotelName = hotelName;
        this.isOpen = true;
        this.employees = new ArrayList<Employee>();
        this.customers = new ArrayList<Customer>();
        this.menu = new Menu();
        this.orders = new ArrayList<Order>();
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
        this.orders.add(order);
    }

    public void removeOrder(Order order) {
        this.orders.remove(order);
    }
}
