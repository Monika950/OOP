abstract class Employee {
    protected String name;
    protected int id;

    public Employee(String name, int id) {
        this.name = name;
        this.id = id;
    }

    public abstract double calculateMonthlyPay();

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public abstract String getRole();
}