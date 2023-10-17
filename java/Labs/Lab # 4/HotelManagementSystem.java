import java.util.*;

public class HotelManagementSystem {
    static void showMenu() {
        System.out.println("1) Manage Employees");
        System.out.println("2) Manage Customer");
        System.out.println("3) Manage Order");
        System.out.println("4) Manage Menu");
        System.out.println("5) Generate Bill");
        System.out.println("6) Exit");
        System.out.print("Enter your choice: ");
    }

    static void showEmployeeMenu() {
        System.out.println("1) Add Employee");
        System.out.println("2) Remove Employee");
        System.out.println("3) Show Employees");
        System.out.println("4) Exit");
        System.out.print("Enter your choice: ");
    }

    static void showCustomerMenu() {
        System.out.println("1) Add Customer");
        System.out.println("2) Remove Customer");
        System.out.println("3) Show Customers");
        System.out.println("4) Exit");
        System.out.print("Enter your choice: ");
    }

    static void showMenuMenu() {
        System.out.println("1) Add Menu");
        System.out.println("2) Remove Menu");
        System.out.println("3) Show Menus");
        System.out.println("4) Exit");
        System.out.print("Enter your choice: ");
    }

    static void showOrderMenu() {
        System.out.println("1) Add Order");
        System.out.println("2) Remove Order");
        System.out.println("3) Show Orders");
        System.out.println("4) Exit");
        System.out.print("Enter your choice: ");
    }

    public static void main(String[] args) {
        HotelManagement hotelManagement = new HotelManagement("Grand Hotel");
        // hotelManagement.addEmployee(new Employee("1", "Employee 1", "10000"));
        // hotelManagement.addEmployee(new Employee("2", "Employee 2", "20000"));
        // hotelManagement.addEmployee(new Employee("3", "Employee 3", "30000"));
        // hotelManagement.addMenu(new Menu(1, "Menu 1"));
        // hotelManagement.addMenu(new Menu(2, "Menu 2"));
        // hotelManagement.addMenu(new Menu(3, "Menu 3"));
        // hotelManagement.addCustomer(new Customer(1, "Customer 1"));
        // hotelManagement.addCustomer(new Customer(2, "Customer 2"));
        // hotelManagement.addCustomer(new Customer(3, "Customer 3"));
        // hotelManagement.addOrder(new Order(1, hotelManagement.getMenus().get(0)));
        // hotelManagement.addOrder(new Order(2, hotelManagement.getMenus().get(1)));
        // hotelManagement.addOrder(new Order(3, hotelManagement.getMenus().get(2)));
        // hotelManagement.getOrders().get(0).addItem(1);
        // hotelManagement.getOrders().get(0).addItem(2);
        // hotelManagement.getOrders().get(1).addItem(3);
        // take input from user
        Scanner sc = new Scanner(System.in);
        int cond;
        do {
            showMenu();
            cond = sc.nextInt();
            switch (cond) {
                case 1:
                    // Handle Employees
                    int flag;
                    showEmployeeMenu();
                    flag = sc.nextInt();
                    switch (flag) {
                        case 1:
                            // Add Employee
                            System.out.print("Enter Employee Id: ");
                            String employeeId = sc.next();
                            System.out.print("Enter Employee Name: ");
                            String employeeName = sc.next();
                            System.out.print("Enter Employee Salary: ");
                            String employeeSalary = sc.next();
                            hotelManagement.addEmployee(new Employee(employeeId, employeeName, employeeSalary));
                            break;
                        case 2:
                            // Remove Employee
                            System.out.print("Enter Employee Id: ");
                            String employeeIdToRemove = sc.next();
                            for (Employee employee : hotelManagement.getEmployees()) {
                                if (employee.getEmployeeId().equals(employeeIdToRemove)) {
                                    hotelManagement.removeEmployee(employee);
                                    break;
                                }
                            }
                            break;
                        case 3:
                            // Show Employees
                            if (hotelManagement.getEmployees().isEmpty()) {
                                System.out.println("No Employees");
                                break;
                            }
                            for (Employee employee : hotelManagement.getEmployees()) {
                                System.out.print("Employee Id: " + employee.getEmployeeId());
                                System.out.print(", Employee Name: " + employee.getName());
                                System.out.print(", Employee Salary: " + employee.getSalary());
                                System.out.println();
                            }
                            break;
                        case 4:
                            // Exit
                            break;
                        default:
                            System.out.println("Invalid Choice");
                    }
                    break;
                case 2:
                    // Handle Customer
                    int flag1;
                    showCustomerMenu();
                    flag1 = sc.nextInt();
                    switch (flag1) {
                        case 1:
                            // Add Customer
                            System.out.print("Enter Customer Id: ");
                            int customerId = sc.nextInt();
                            System.out.print("Enter Customer Name: ");
                            String customerName = sc.next();
                            // hotelManagement.addCustomer(new Customer(customerId, customerName));
                            break;
                        case 2:
                            // Remove Customer
                            System.out.print("Enter Customer Id: ");
                            String customerIdToRemove = sc.next();
                            for (Customer customer : hotelManagement.getCustomers()) {
                                if (customer.getCustomerId() == customerIdToRemove) {
                                    hotelManagement.removeCustomer(customer);
                                    break;
                                }
                            }
                            break;
                        case 3:
                            // Show Customers
                            if (hotelManagement.getCustomers().isEmpty()) {
                                System.out.println("No Customers");
                                break;
                            }
                            for (Customer customer : hotelManagement.getCustomers()) {
                                System.out.print("Customer Id: " + customer.getCustomerId());
                                System.out.print(", Customer Name: " + customer.getCustomerName());
                                System.out.println();
                            }
                            break;
                        case 4:
                            // Exit
                            break;
                        default:
                            System.out.println("Invalid Choice");
                    }
                    break;
                // case 3:
                // // Handle Order
                // int flag2;
                // showOrderMenu();
                // flag2 = sc.nextInt();
                // switch (flag2) {
                // case 1:
                // // Add Order
                // System.out.print("Enter Order Id: ");
                // int orderId = sc.nextInt();
                // System.out.print("Enter Menu Id: ");
                // int menuId = sc.nextInt();
                // hotelManagement
                // .addOrder(new Order(orderId, hotelManagement.getMenus().get(menuId - 1)));
                // break;
                // case 2:
                // // Remove Order
                // System.out.print("Enter Order Id: ");
                // int orderIdToRemove = sc.nextInt();
                // for (Order order : hotelManagement.getOrders()) {
                // if (order.getOrderId() == orderIdToRemove) {
                // hotelManagement.removeOrder(order);
                // break;
                // }
                // }
                // break;
                // case 3:
                // // Show Orders
                // if (hotelManagement.getOrders().isEmpty()) {
                // System.out.println("No Orders");
                // break;
                // }
                // for (Order order : hotelManagement.getOrders()) {
                // System.out.print("Order Id: " + order.getOrderId());
                // System.out.print(", Menu Id: " + order.getMenu().getItemId());
                // System.out.println();
                // }
                // break;
                // case 4:
                // // Exit
                // break;
                // default:
                // System.out.println("Invalid Choice");
                // }
                // break;
                // case 4:
                // // Handle Menu
                // int flag3;
                // showMenuMenu();
                // flag3 = sc.nextInt();
                // switch (flag3) {
                // case 1:
                // // Add Menu
                // System.out.print("Enter Menu Id: ");
                // int menuId = sc.nextInt();
                // System.out.print("Enter Menu Name: ");
                // String menuName = sc.next();
                // hotelManagement.addMenu(new Menu(menuId, menuName));
                // break;
                // case 2:
                // // Remove Menu
                // System.out.print("Enter Menu Id: ");
                // int menuIdToRemove = sc.nextInt();
                // for (Menu menu : hotelManagement.getMenus()) {
                // if (menu.getItemId() == menuIdToRemove) {
                // hotelManagement.removeMenu(menu);
                // break;
                // }
                // }
                // break;
                // case 3:
                // // Show Menus
                // if (hotelManagement.getMenus().isEmpty()) {
                // System.out.println("No Menus");
                // break;
                // }
                // for (Menu menu : hotelManagement.getMenus()) {
                // System.out.print("Menu Id: " + menu.getItemId());
                // System.out.print(", Menu Name: " + menu.getItemName());
                // System.out.println();
                // }
                // break;
                // case 4:
                // // Exit
                // break;
                // default:
                // System.out.println("Invalid Choice");
                // }
                // break;

                case 5:
                    // Genereate Bill
                    System.out.print("Enter Customer Id: ");
                    int customerId = sc.nextInt();
                    System.out.print("Enter Bill Id: ");
                    int billId = sc.nextInt();
                    Bill bill = new Bill(billId, hotelManagement.getCustomers().get(customerId - 1),
                            hotelManagement.getOrders().get(customerId - 1));
                    System.out.print("Enter Order Id: ");
                    int orderId = sc.nextInt();
                    System.out.print("Enter Item Id: ");
                    int itemId = sc.nextInt();
                    Item item = hotelManagement.getMenus().get(orderId - 1).getItemById(itemId);
                    bill.getOrder().addItem(item);
                    bill.calculate_bill();
                    System.out.println("Total Amount: " + bill.getTotalAmount());

                    System.out.print("Enter Payment Id: ");
                    int paymentId = sc.nextInt();
                    System.out.print("Enter Payment Amount: ");
                    double paymentAmount = sc.nextDouble();
                    System.out.print("Enter Payment Type (1 for Card, 2 for Cash): ");
                    int paymentType = sc.nextInt();
                    Payment payment;
                    if (paymentType == 1) {
                        System.out.print("Enter Card Number: ");
                        String cardNumber = sc.next();
                        System.out.print("Enter Expiration Date: ");
                        String expirationDate = sc.next();
                        System.out.print("Enter CVV: ");
                        String cvv = sc.next();
                        payment = new Card(paymentId, paymentAmount, cardNumber, expirationDate, cvv);
                    } else {
                        System.out.print("Enter Cash Tendered: ");
                        double cashTendered = sc.nextDouble();
                        payment = new Cash(paymentId, paymentAmount, cashTendered);
                    }
                    payment.processPayment();
                    break;
            }
        } while (cond != 6);
        sc.close();
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

    Employee(String employeeId, String name, String salary) {
        this.employeeId = employeeId;
        this.name = name;
        this.salary = salary;
    }

    Employee() {
    }

    void employeeDetails() {
        System.out.println("Employee Id: " + employeeId);
        System.out.println("Employee Name: " + name);
        System.out.println("Employee Salary: " + salary);
    }

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

class Server extends Employee {
    // private String serverId;
    private String orderId;

    // public String getServerId() {
    // return serverId;
    // }

    // public void setServerId(String serverId) {
    // this.serverId = serverId;
    // }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }

    public String getOrderId() {
        return orderId;
    }
}

class Chef extends Employee {
    // private String chefId;
    private String orderId;
    private Server server;

    // public String getChefId() {
    // return chefId;
    // }

    public String getOrderId() {
        return orderId;
    }

    // public void setChefId(String chefId) {
    // this.chefId = chefId;
    // }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }

    public void setServer(Server server) {
        this.server = server;
    }

    public Server getServer() {
        return server;
    }
}

class Table {
    private int tableNumber;
    private boolean occupiedStatus;
    private String serverId;
    private int customerId;

    public Table(int tableNumber, boolean occupiedStatus, String serverId, int customerId) {
        this.tableNumber = tableNumber;
        this.occupiedStatus = occupiedStatus;
        this.serverId = serverId;
        this.customerId = customerId;
    }

    public boolean getAvailabilityStatus() {
        return occupiedStatus;
    }

    public int getTableNumber() {
        return tableNumber;
    }

    public String getServerId() {
        return serverId;
    }

    public int getCustomerId() {
        return customerId;
    }
}

class Customer {
    private String customerId;
    private String customerName;
    private String billId;
    private String orderId;
    private String paymentId;

    private Server server;

    public Customer(String customerId, String customerName, Server server, Order order) {
        this.customerId = customerId;
        this.customerName = customerName;
        this.server = server;
        this.billId = order.getBill().getBillId();
        this.orderId = order.getOrderId();
        this.paymentId = order.getBill().getPayment().getPaymentId();
    }

    public boolean paymentStatus() {
        return bill.getPayment().getStatus() == PaymentStatus.SUCCESSFUL;
    }

    public String getCustomerId() {
        return customerId;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void customerDetails() {
        System.out.println("Customer Id: " + customerId);
        System.out.println("Customer Name: " + customerName);
    }

    public void orderedItems() {
        System.out.println("Ordered Items: ");
        for (Item item : bill.getOrder().getItems()) {
            System.out.print("Item Id: " + item.getItemId());
            System.out.print(", Item Name: " + item.getItemName());
            System.out.print(", Item Amount: " + item.getAmount());
            System.out.println();
        }
    }

    public Bill getBill() {
        return bill;
    }

    public Server getServer() {
        return server;
    }

    public void setServer(Server server) {
        this.server = server;
    }
}

class Menu {
    private int itemId;
    private String itemName;
    private List<Item> items;

    public Menu(int menuId, String menuName) {
        this.itemId = menuId;
        this.itemName = menuName;
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

class Order {
    private int orderId;
    private String customerId;
    private List<Item> items;
    private double totalAmount;

    public Order(int orderId, Menu menu) {
        this.orderId = orderId;
        this.items = new ArrayList<>();
        this.totalAmount = 0.0;
    }

    public void addItem(Item item) {
        this.items.add(item);
        this.totalAmount += item.getAmount();
    }

    public String getOrderId() {
        return orderId;
    }

    public List<Item> getItems() {
        return items;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public Bill getBill() {
        return new Bill(orderId, new Customer(customerId), this);
    }

}

class Bill {
    private int billId;
    private Customer customer;
    private Order order;
    private double totalAmount;
    private Payment payment;

    public Bill() {
    }

    public Bill(int billId, Customer customer, Order order) {
        this.billId = billId;
        this.customer = customer;
        this.order = order;
        this.totalAmount = 0.0;
    }

    public String getBillId() {
        return billId;
    }

    public Customer getCustomer() {
        return customer;
    }

    public Order getOrder() {
        return order;
    }

    public void setOrder(Order orders) {
        this.order = orders;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public Payment getPayment() {
        return payment;
    }

    public void setPayment() {
        Payment payment = new Payment(1, totalAmount) {
            @Override
            public void processPayment() {
                System.out.println("Payment done");
            }
        };
    }

    public void calculate_bill() {
        for (Item item : order.getItems()) {
            totalAmount += item.getAmount();
        }
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

    public String getPaymentId() {
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
        System.out.println("Payment through Card done");
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
        System.out.println("Payment through Cash done");
    }
}
