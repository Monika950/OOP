
public class Manager extends Employee {
    private double bonus;

    public Manager(String name, double baseSalary, JobLevel jobLevel, double bonus) {
        super(name, baseSalary, jobLevel);
        this.bonus = bonus;
    }

    @Override
    public double calculatePay() {
        return getBaseSalary() + getBonus();
    }

    @Override
    public String toString() {
        return "Manager: " + getName() +
                ", Level: " + getJobLevel() +
                ", Salary: " + calculatePay() +
                " (Base: " + getBaseSalary() +
                " + Bonus: " + getBonus() + ")";
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }
}

