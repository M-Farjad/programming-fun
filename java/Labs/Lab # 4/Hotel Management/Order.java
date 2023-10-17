import java.util.*;
public class Order {
    private int orderId;
    private Menu menu;
    private List<Item> items;
    private double totalAmount;

    public Order(int orderId, Menu menu) {
        this.orderId = orderId;
        this.menu = menu;
        this.items = new ArrayList<>();
        this.totalAmount = 0.0;
    }

    public int getOrderId() {
        return orderId;
    }

    public Menu getMenu() {
        return menu;
    }

    public List<Item> getItems() {
        return items;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void addItem(int itemId) {
        Item item = menu.getItemById(itemId);
        this.items.add(item);
        this.totalAmount += item.getAmount();
    }

    public void removeItem(int itemId) {
        Item item = menu.getItemById(itemId);
        this.items.remove(item);
        this.totalAmount -= item.getAmount();
    }
}
