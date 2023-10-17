public class Cash extends Payment {
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
