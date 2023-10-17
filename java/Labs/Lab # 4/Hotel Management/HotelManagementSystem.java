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
                            hotelManagement.addCustomer(new Customer(customerId, customerName));
                            break;
                        case 2:
                            // Remove Customer
                            System.out.print("Enter Customer Id: ");
                            int customerIdToRemove = sc.nextInt();
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
                case 3:
                    // Handle Order
                    int flag2;
                    showOrderMenu();
                    flag2 = sc.nextInt();
                    switch (flag2) {
                        case 1:
                            // Add Order
                            System.out.print("Enter Order Id: ");
                            int orderId = sc.nextInt();
                            System.out.print("Enter Menu Id: ");
                            int menuId = sc.nextInt();
                            hotelManagement
                                    .addOrder(new Order(orderId, hotelManagement.getMenus().get(menuId - 1)));
                            break;
                        case 2:
                            // Remove Order
                            System.out.print("Enter Order Id: ");
                            int orderIdToRemove = sc.nextInt();
                            for (Order order : hotelManagement.getOrders()) {
                                if (order.getOrderId() == orderIdToRemove) {
                                    hotelManagement.removeOrder(order);
                                    break;
                                }
                            }
                            break;
                        case 3:
                            // Show Orders
                            if (hotelManagement.getOrders().isEmpty()) {
                                System.out.println("No Orders");
                                break;
                            }
                            for (Order order : hotelManagement.getOrders()) {
                                System.out.print("Order Id: " + order.getOrderId());
                                System.out.print(", Menu Id: " + order.getMenu().getItemId());
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
                case 4:
                    // Handle Menu
                    int flag3;
                    showMenuMenu();
                    flag3 = sc.nextInt();
                    switch (flag3) {
                        case 1:
                            // Add Menu
                            System.out.print("Enter Menu Id: ");
                            int menuId = sc.nextInt();
                            System.out.print("Enter Menu Name: ");
                            String menuName = sc.next();
                            hotelManagement.addMenu(new Menu(menuId, menuName));
                            break;
                        case 2:
                            // Remove Menu
                            System.out.print("Enter Menu Id: ");
                            int menuIdToRemove = sc.nextInt();
                            for (Menu menu : hotelManagement.getMenus()) {
                                if (menu.getItemId() == menuIdToRemove) {
                                    hotelManagement.removeMenu(menu);
                                    break;
                                }
                            }
                            break;
                        case 3:
                            // Show Menus
                            if (hotelManagement.getMenus().isEmpty()) {
                                System.out.println("No Menus");
                                break;
                            }
                            for (Menu menu : hotelManagement.getMenus()) {
                                System.out.print("Menu Id: " + menu.getItemId());
                                System.out.print(", Menu Name: " + menu.getItemName());
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
                case 5:
                    // Genereate Bill
                    System.out.print("Enter Customer Id: ");
                    int customerId = sc.nextInt();
                    System.out.print("Enter Bill Id: ");
                    int billId = sc.nextInt();
                    Bill bill = new Bill(billId, hotelManagement.getCustomers().get(customerId - 1));
                    System.out.print("Enter Order Id: ");
                    int orderId = sc.nextInt();
                    for (Order order : hotelManagement.getOrders()) {
                        if (order.getOrderId() == orderId) {
                            bill.addOrder(order);
                            break;
                        }
                    }
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
