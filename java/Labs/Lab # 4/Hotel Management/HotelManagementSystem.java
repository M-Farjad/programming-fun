import java.util.*;

public class HotelManagementSystem {
    static void showMenu() {
        System.out.println("1) Manage Employees");
        System.out.println("2) Manage Customer");
        System.out.println("3) Manage Menu");
        System.out.println("4) Manage Order");
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
        System.out.println("1) Add Item in Menu");
        System.out.println("2) Remove Item in Menu");
        System.out.println("3) Show Item in Menu");
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
            System.out.print("\033[H\033[2J");
            System.out.flush();
            switch (cond) {
                case 1:
                    // Handle Employees
                    int flag;
                    showEmployeeMenu();
                    flag = sc.nextInt();
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    switch (flag) {
                        case 1:
                            // Add Employee
                            System.out.print("Enter Employee Id: ");
                            String employeeId = sc.next();
                            System.out.print("Enter Employee Name: ");
                            String employeeName = sc.next();
                            System.out.print("Enter Employee Salary: ");
                            String employeeSalary = sc.next();
                            if (employeeId.length() == 0 || employeeName.length() == 0
                                    || employeeSalary.length() == 0) {
                                System.out.println("Invalid Input");
                                break;
                            }
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
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    switch (flag1) {
                        case 1:
                            // Add Customer
                            System.out.print("Enter Customer Id: ");
                            int customerId = sc.nextInt();
                            System.out.print("Enter Customer Name: ");
                            String customerName = sc.next();
                            System.out.print("Enter Customer Order Id: ");
                            String customerOrderId = sc.next();
                            hotelManagement.addCustomer(new Customer(customerId, customerName, customerOrderId));
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
                    // Handle Menu
                    int flag3;
                    showMenuMenu();
                    flag3 = sc.nextInt();
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    switch (flag3) {
                        case 1:
                            // Add Item
                            System.out.print("Enter Item Id: ");
                            int itemId = sc.nextInt();
                            System.out.print("Enter Item Name: ");
                            String itemName = sc.next();
                            System.out.print("Enter Item Price: ");
                            double itemPrice = sc.nextDouble();
                            hotelManagement.getMenu().addItem(new Item(itemId, itemName, itemPrice));
                            System.out.println("Item Added");
                            break;
                        case 2:
                            // Remove Item in Menu
                            System.out.print("Enter Item Id: ");
                            int itemIdToRemove = sc.nextInt();
                            for (Item item : hotelManagement.getMenu().getItems()) {
                                if (item.getItemId() == itemIdToRemove) {
                                    hotelManagement.getMenu().removeItem(item);
                                    break;
                                }
                            }
                            System.out.println("Item Removed");
                            break;
                        case 3:
                            // Show Menu
                            System.out.println(">>> Items in Menu <<<");
                            for (Item item : hotelManagement.getMenu().getItems()) {
                                System.out.print("Item Id: " + item.getItemId());
                                System.out.println(", Item Name: " + item.getItemName());
                            }
                            System.out.println(">>> End of Menu <<<");
                            System.out.println();
                            break;
                        case 4:
                            // Exit
                            break;
                        default:
                            System.out.println("Invalid Choice");
                    }
                    break;
                case 4:
                    // Handle Order
                    int flag2;
                    showOrderMenu();
                    flag2 = sc.nextInt();
                    System.out.print("\033[H\033[2J");
                    System.out.flush();
                    switch (flag2) {
                        case 1:
                            // Add Order
                            System.out.print("Enter Order Id: ");
                            String orderId = sc.next();
                            Order order = new Order(orderId);
                            do {
                                System.out.print("Enter Item Id: ");
                                int itemId = sc.nextInt();
                                order.addItem(itemId, hotelManagement.getMenu());
                                System.out.print("Add more items? (y/n): ");
                                char choice = sc.next().charAt(0);
                                if (choice == 'n' || choice == 'N') {
                                    break;
                                }
                            } while (true);
                            hotelManagement.addOrder(order);
                            break;
                        case 2:
                            // Remove Order
                            System.out.print("Enter Order Id: ");
                            String orderIdToRemove = sc.next();
                            for (Order order1 : hotelManagement.getOrders()) {
                                if (order1.getOrderId() == orderIdToRemove) {
                                    hotelManagement.removeOrder(order1);
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
                            for (Order order2 : hotelManagement.getOrders()) {
                                System.out.print("Order Id: " + order2.getOrderId());
                                order2.order_items();
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
                    // Generate Bill
                    System.out.print("Enter Customer Id: ");
                    int customerId = sc.nextInt();
                    for (Customer customer : hotelManagement.getCustomers()) {
                        if (customerId == customer.getCustomerId()) {
                            customer.printBill();
                            break;
                        }
                    }
                    break;
            }
        } while (cond != 6);
        sc.close();
    }
}
