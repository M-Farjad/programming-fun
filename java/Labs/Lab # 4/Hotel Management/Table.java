public class Table {
    private int tableNumber;
    private boolean occupiedStatus;
    private String serverId;
    private int customerId;

    public Table(int tableNumber, boolean occupiedStatus, String serverId, int customerId) {
        this.tableNumber = tableNumber;
        this.occupiedStatus = occupiedStatus;
        this.serverId = serverId;
        this.customerId = customerId;
    }

    public boolean getAvailabilityStatus() {
        return occupiedStatus;
    }

    public int getTableNumber() {
        return tableNumber;
    }

    public String getServerId() {
        return serverId;
    }

    public int getCustomerId() {
        return customerId;
    }
}
