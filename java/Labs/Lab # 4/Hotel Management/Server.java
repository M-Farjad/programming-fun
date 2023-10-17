public class Server extends Employee {
    private String serverId;
    private Chef chef;
    private Customer customer;

    public String getServerId() {
        return serverId;
    }

    public Chef getChef() {
        return chef;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setServerId(String serverId) {
        this.serverId = serverId;
    }

    public void setChef(Chef chef) {
        this.chef = chef;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }
}
