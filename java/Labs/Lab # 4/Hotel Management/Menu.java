import java.util.*;

public class Menu {
    private int itemId;
    private String itemName;
    private List<Item> items;

    public Menu(int menuId, String menuName) {
        this.itemId = menuId;
        this.itemName = menuName;
        this.items = new ArrayList<>();
    }

    public int getItemId() {
        return itemId;
    }

    public String getItemName() {
        return itemName;
    }

    public List<Item> getItems() {
        return items;
    }

    public void addItem(Item item) {
        this.items.add(item);
    }

    public void removeItem(Item item) {
        this.items.remove(item);
    }

    public Item getItemById(int itemId) {
        for (Item item : items) {
            if (item.getItemId() == itemId) {
                return item;
            }
        }
        return null;
    }
}
