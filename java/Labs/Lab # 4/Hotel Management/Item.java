public class Item {
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
