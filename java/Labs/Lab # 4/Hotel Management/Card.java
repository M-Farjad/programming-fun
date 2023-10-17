public class Card extends Payment {
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

