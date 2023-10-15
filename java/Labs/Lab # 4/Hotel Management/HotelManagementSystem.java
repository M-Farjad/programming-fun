import java.util.*;

public class HotelManagementSystem {
    public static void main(String[] args) {

    }
}

// HotelManagement class is composed by Employees, Customer, Menu, Order
class HotelManagement {
    private String hotelName;
    private int noOfEmployees;
    private boolean isOpen;
    private List<Employee> employees;
    private List<Customer> customers;
    private List<Menu> menus;
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
        this.menus = new ArrayList<Menu>();
        this.orders = new ArrayList<Order>();
    }

    public List<Employee> getEmployees() {
        return employees;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public List<Menu> getMenus() {
        return menus;
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

    public void addMenu(Menu menu) {
        this.menus.add(menu);
    }

    public void removeMenu(Menu menu) {
        this.menus.remove(menu);
    }

    public void addOrder(Order order) {
        this.orders.add(order);
    }

    public void removeOrder(Order order) {
        this.orders.remove(order);
    }
}

class Employee {
    private String employeeId;
    private String name;
    private String salary;

    public String getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getSalary() {
        return salary;
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(String salary) {
        this.salary = salary;
    }
}

// server class is extending employees class and aggregating chef, Customer
class Server extends Employee {
    private String serverId;
    private Chef chef;
    private Customer customer;

    public String getServerId() {
        return serverId;
    }

    public Chef getChef() {
        return chef;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setServerId(String serverId) {
        this.serverId = serverId;
    }

    public void setChef(Chef chef) {
        this.chef = chef;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }
}

class Chef extends Employee {
    private String chefId;
    private String orderId;

    public String getChefId() {
        return chefId;
    }

    public String getOrderId() {
        return orderId;
    }

    public void setChefId(String chefId) {
        this.chefId = chefId;
    }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }
}

class Customer {
    private int customerId;
    private String customerName;
    private Bill bill;

    public Customer(int customerId, String customerName) {
        this.customerId = customerId;
        this.customerName = customerName;
        this.bill = new Bill();
    }

    public int getCustomerId() {
        return customerId;
    }

    public String getCustomerName() {
        return customerName;
    }

    public Bill getBill() {
        return bill;
    }
}

// Menu class is composing HotelManagement
class Menu {
    private int itemId;
    private String itemName;
    private List<Item> items;
    private HotelManagement hotelManagement;

    public Menu(int menuId, String menuName, HotelManagement hotelManagement) {
        this.itemId = menuId;
        this.itemName = menuName;
        this.hotelManagement = hotelManagement;
        this.items = new ArrayList<>();
    }

    public int getItemId() {
        return itemId;
    }

    public String getItemName() {
        return itemName;
    }

    public List<Item> getItems() {
        return items;
    }

    public HotelManagement getHotelManagement() {
        return hotelManagement;
    }

    public void addItem(Item item) {
        this.items.add(item);
    }

    public void removeItem(Item item) {
        this.items.remove(item);
    }

    public Item getItemById(int itemId) {
        for (Item item : items) {
            if (item.getItemId() == itemId) {
                return item;
            }
        }
        return null;
    }
}

// order class is composing Menu and HotelManagement
class Order {
    private int orderId;
    private Menu menu;
    private HotelManagement hotelManagement;
    private List<Item> items;
    private double totalAmount;

    public Order(int orderId, Menu menu, HotelManagement hotelManagement) {
        this.orderId = orderId;
        this.menu = menu;
        this.hotelManagement = hotelManagement;
        this.items = new ArrayList<>();
        this.totalAmount = 0.0;
    }

    public int getOrderId() {
        return orderId;
    }

    public Menu getMenu() {
        return menu;
    }

    public HotelManagement getHotelManagement() {
        return hotelManagement;
    }

    public List<Item> getItems() {
        return items;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void addItem(int itemId) {
        Item item = menu.getItemById(itemId);
        this.items.add(item);
        this.totalAmount += item.getAmount();
    }

    public void removeItem(int itemId) {
        Item item = menu.getItemById(itemId);
        this.items.remove(item);
        this.totalAmount -= item.getAmount();
    }
}

class Bill {
    private int billId;
    private Customer customer;
    private List<Order> orders;
    private double totalAmount;

    public Bill() {
    }

    public Bill(int billId, Customer customer) {
        this.billId = billId;
        this.customer = customer;
        this.orders = new ArrayList<>();
        this.totalAmount = 0.0;
    }

    public int getBillId() {
        return billId;
    }

    public Customer getCustomer() {
        return customer;
    }

    public List<Order> getOrders() {
        return orders;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void addOrder(Order order) {
        this.orders.add(order);
        this.totalAmount += order.getTotalAmount();
    }

    public void removeOrder(Order order) {
        this.orders.remove(order);
        this.totalAmount -= order.getTotalAmount();
    }
}

class Item {
    private int itemId;
    private String itemName;
    private double amount;

    public Item(int itemId, String itemName, double amount) {
        this.itemId = itemId;
        this.itemName = itemName;
        this.amount = amount;
    }

    public int getItemId() {
        return itemId;
    }

    public String getItemName() {
        return itemName;
    }

    public double getAmount() {
        return amount;
    }
}

abstract class Payment {
    private int paymentId;
    private double amount;
    private PaymentStatus status;

    public Payment(int paymentId, double amount) {
        this.paymentId = paymentId;
        this.amount = amount;
        this.status = PaymentStatus.PENDING;
    }

    public int getPaymentId() {
        return paymentId;
    }

    public double getAmount() {
        return amount;
    }

    public PaymentStatus getStatus() {
        return status;
    }

    public void setStatus(PaymentStatus status) {
        this.status = status;
    }

    public abstract void processPayment();
}

enum PaymentStatus {
    PENDING,
    SUCCESSFUL,
    FAILED
}

class Card extends Payment {
    private String cardNumber;
    private String expirationDate;
    private String cvv;

    public Card(int paymentId, double amount, String cardNumber, String expirationDate, String cvv) {
        super(paymentId, amount);
        this.cardNumber = cardNumber;
        this.expirationDate = expirationDate;
        this.cvv = cvv;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public String getExpirationDate() {
        return expirationDate;
    }

    public String getCvv() {
        return cvv;
    }

    @Override
    public void processPayment() {
        // Connect to credit card processor
        // Process payment
        // Set payment status to SUCCESSFUL
    }
}

class Cash extends Payment {
    private double cashTendered;

    public Cash(int paymentId, double amount, double cashTendered) {
        super(paymentId, amount);
        this.cashTendered = cashTendered;
    }

    public double getCashTendered() {
        return cashTendered;
    }

    @Override
    public void processPayment() {
        // Process payment
        // Set payment status to SUCCESSFUL
    }
}

class Table {

    private int tableNumber;
    private int capacity;
    private boolean isAvailable;

    public Table(int tableNumber, int capacity) {
        this.tableNumber = tableNumber;
        this.capacity = capacity;
        this.isAvailable = true;
    }

    public int getTableNumber() {
        return tableNumber;
    }

    public int getCapacity() {
        return capacity;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailable(boolean isAvailable) {
        this.isAvailable = isAvailable;
    }
}
