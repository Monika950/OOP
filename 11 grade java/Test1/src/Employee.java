public class Employee implements Payable {
    private String name;
    private double baseSalary;
    private JobLevel jobLevel;

    public Employee(String name, double baseSalary, JobLevel jobLevel) {
        this.name = name;
        this.baseSalary = baseSalary;
        this.jobLevel = jobLevel;
    }

    @Override
    public double calculatePay() {
        return baseSalary;
    }

    @Override
    public String toString() {
        return "Employee: " + name + ", Level: " + jobLevel + ", Salary: " + baseSalary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    public JobLevel getJobLevel() {
        return jobLevel;
    }

    public void setJobLevel(JobLevel jobLevel) {
        this.jobLevel = jobLevel;
    }
}