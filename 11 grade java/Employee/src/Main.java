import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.DoubleStream;

public class Main {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<>();

        employees.add(new FullTimeEmployee("Alice", 1, 60000));
        employees.add(new FullTimeEmployee("Bob", 2, 72000));
        employees.add(new FullTimeEmployee("Charlie", 3, 48000));
        employees.add(new PartTimeEmployee("David", 4, 20, 160));
        employees.add(new PartTimeEmployee("Eve", 5, 25, 140));
        employees.add(new PartTimeEmployee("Frank", 6, 15, 150));

        System.out.println("monthly pay > 3000:");
        employees.stream()
                .filter(e -> e.calculateMonthlyPay() > 3000)
                .forEach(e -> System.out.println(e.getName() + " - " + e.calculateMonthlyPay()));

        System.out.println("\nsorted by monthly pay (descending):");
        employees.stream()
                .sorted(Comparator.comparingDouble(Employee::calculateMonthlyPay).reversed())
                .forEach(e -> System.out.println(e.getName() + " - " + e.calculateMonthlyPay()));

        System.out.println("\ndetails:");
        List<String> employeeDetails = employees.stream()
                .map(e -> "ID:" + e.getId() + ", Name:" + e.getName() + ", Monthly Pay:" + e.calculateMonthlyPay())
                .toList();
        employeeDetails.forEach(System.out::println);

        DoubleSummaryStatistics stats = employees.stream()
                .mapToDouble(Employee::calculateMonthlyPay)
                .summaryStatistics();
        System.out.println("\nStatistics:");
        System.out.println("Average Monthly Pay: " + stats.getAverage());
        System.out.println("Min Monthly Pay: " + stats.getMin());
        System.out.println("Max Monthly Pay: " + stats.getMax());
        System.out.println("Total Monthly Pay: " + stats.getSum());
        System.out.println("Total Employees: " + stats.getCount());

        System.out.println("\nExamples:");
        boolean anyHighPay = employees.stream().anyMatch(e -> e.calculateMonthlyPay() > 6000);
        boolean allAbove2000 = employees.stream().allMatch(e -> e.calculateMonthlyPay() > 2000);
        boolean noneBelow500 = employees.stream().noneMatch(e -> e.calculateMonthlyPay() < 500);
        System.out.println("Any with pay > 6000: " + anyHighPay);
        System.out.println("All with pay > 2000: " + allAbove2000);
        System.out.println("No with pay < 500: " + noneBelow500);

        System.out.println("\nMiddle class:");
        employees.stream()
                .sorted(Comparator.comparingDouble(Employee::calculateMonthlyPay).reversed())
                .skip(2)
                .limit(3)
                .forEach(e -> System.out.println(e.getName() + " - " + e.calculateMonthlyPay()));

        double totalPay = employees.stream()
                .mapToDouble(Employee::calculateMonthlyPay)
                .reduce(0, Double::sum);
        System.out.println("Total Pay: " + totalPay);

        System.out.println("\nGrouping by role:");
        Map<String, List<Employee>> groupedByRole = employees.stream()
                .collect(Collectors.groupingBy(Employee::getRole));
        groupedByRole.forEach((role, emps) -> {
            System.out.println(role + ":");
            emps.forEach(e -> System.out.println("  " + e.getName() + " - " + e.calculateMonthlyPay()));
        });

        System.out.println("\nFind employee by ID (ID=3):");
        Optional<Employee> employeeById = employees.stream().filter(e -> e.getId() == 3).findFirst();
        employeeById.ifPresentOrElse(
                e -> System.out.println("Found: " + e.getName()),
                () -> System.out.println("Employee not found"));
    }
}