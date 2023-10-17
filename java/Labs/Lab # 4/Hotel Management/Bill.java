import java.util.*;

public class Bill {
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
