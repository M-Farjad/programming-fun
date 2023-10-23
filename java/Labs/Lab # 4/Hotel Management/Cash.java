public class Cash extends Payment {

    public Cash(int paymentId, double amount) {
        super(paymentId, amount);
    }

    @Override
    public void processPayment() {
        System.out.println("Payment through Cash done");
    }
}
