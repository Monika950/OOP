public class CompanyManagement {
    public static void main(String[] args) {
        Company company = new Company();

        for (String arg : args) {
            String[] parts = arg.split(",");
            String name = parts[0];
            double baseSalary = Double.parseDouble(parts[1]);
            JobLevel jobLevel = JobLevel.valueOf(parts[2].toUpperCase());
            String type = parts[3];

            if (type.equalsIgnoreCase("Manager")) {
                double bonus = Double.parseDouble(parts[4]);
                Manager manager = new Manager(name, baseSalary, jobLevel, bonus);
                company.addEmployee(manager);
            } else if (type.equalsIgnoreCase("Employee")) {
                Employee employee = new Employee(name, baseSalary, jobLevel);
                company.addEmployee(employee);
            } else {
                System.out.println("ERROR: " + type);
            }
        }


        company.printSalaries();
    }
}