public class Customer {
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
