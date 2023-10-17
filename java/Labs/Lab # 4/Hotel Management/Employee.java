public class Employee {
    private String employeeId;
    private String name;
    private String salary;

    Employee(String employeeId, String name, String salary) {
        this.employeeId = employeeId;
        this.name = name;
        this.salary = salary;
    }

    Employee() {
    }

    public String getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getSalary() {
        return salary;
    }

    public void setEmployeeId(String employeeId) {
        this.employeeId = employeeId;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(String salary) {
        this.salary = salary;
    }
}
