import java.util.*;

public class Bill {
    Scanner sc = new Scanner(System.in);
    private int billId;
    private String orderId;
    private double totalBill;
    private Payment payment;

    public static int billIdCounter = 1;

    public Bill(String orderId) {
        this.billId = billIdCounter++;
        this.orderId = orderId;
        this.totalBill = 0.0;
        setPayment();
    }

    public Payment getPayment() {
        return this.payment;
    }

    private void setPayment() {
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
            HotelManagement.getOrderById(orderId);
            payment = new Card(Payment.paymentIdCounter++, totalBill, cardNumber, expirationDate, cvv);
            payment.processPayment();
            setTotalBill(totalBill);
        } else if (paymentType == 2) {
            System.out.print("Enter Cash: ");
            double cash = sc.nextDouble();
            setTotalBill(cash);
            payment = new Cash(Payment.paymentIdCounter++, totalBill);
            payment.processPayment();
        } else {
            System.out.println("Invalid Choice");
        }
    }

    public int getBillId() {
        return billId;
    }

    public double getTotalBill() {
        return totalBill;
    }

    public void setTotalBill(double totalBill) {
        this.totalBill = totalBill;
    }

    public void printBill() {
        System.out.println("Bill Id: " + this.billId);
        System.out.println("Order Id: " + this.orderId);
        System.out.println("Total Bill: " + this.totalBill);
    }

    public String getOrderId() {
        return this.orderId;
    }

    public void calculateTotalBill(Order order) {
        this.totalBill = 0.0;
        for (Item item : order.getItems()) {
            this.totalBill += item.getAmount();
        }
    }
}
