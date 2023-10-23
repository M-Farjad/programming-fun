public class Customer {
    private int customerId;
    private String customerName;
    private Bill bill;
    private String orderId;

    public Customer(int customerId, String customerName, String orderId) {
        this.customerId = customerId;
        this.customerName = customerName;
        this.orderId = orderId;
        this.bill = new Bill(orderId);
    }

    public void printBill() {
        this.bill.printBill();
    }

    public String getOrderId() {
        return this.orderId;
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
