import java.util.ArrayList;
import java.util.List;

public static void main(String[] args) {
    List<Property> properties = new ArrayList<>();
    properties.add(new Apartment("Sofia", 800));
    properties.add(new Apartment("Varna", 900));
    properties.add(new Apartment("Plovdiv", 1200));
    properties.add(new Apartment("Burgas", 950));

    properties.add(new House("Sofia", 1000, 200));
    properties.add(new House("Varna", 1100, 300));
    properties.add(new House("Plovdiv", 700, 250));
    properties.add(new House("Burgas", 1200, 400));

    System.out.println("rent > 1000:");
    properties.stream()
            .filter(p -> p.calculateMonthlyRent() > 1000)
            .forEach(p -> System.out.println("Location: " + p.getLocation() + ", Rent: " + p.calculateMonthlyRent()));

    System.out.println("\nsorted by rent:");
    properties.stream()
            .sorted((p1, p2) -> Double.compare(p2.calculateMonthlyRent(), p1.calculateMonthlyRent()))
            .forEach(p -> System.out.println("Location: " + p.getLocation() + ", Rent: " + p.calculateMonthlyRent()));

    System.out.println("\nas strings:");
    List<String> propertyStrings = properties.stream()
            .map(p -> "Location: " + p.getLocation() + ", Monthly Rent: " + p.calculateMonthlyRent())
            .toList();
    propertyStrings.forEach(System.out::println);

    double averageRent = properties.stream()
            .mapToDouble(Property::calculateMonthlyRent)
            .average().orElse(0);

    double minRent = properties.stream()
            .mapToDouble(Property::calculateMonthlyRent)
            .min().orElse(0);

    double maxRent = properties.stream()
            .mapToDouble(Property::calculateMonthlyRent)
            .max().orElse(0);

    double totalRent = properties.stream()
            .mapToDouble(Property::calculateMonthlyRent)
            .sum();

    long propertyCount = properties.size();

    System.out.println("\nStatistics:");
    System.out.println("Average Rent: " + averageRent);
    System.out.println("Min Rent: " + minRent);
    System.out.println("Max Rent: " + maxRent);
    System.out.println("Total Rent: " + totalRent);
    System.out.println("Property Count: " + propertyCount);

    boolean hasRentAbove1500 = properties.stream()
            .anyMatch(p -> p.calculateMonthlyRent() > 1500);
    System.out.println("\nrent > 1500: " + hasRentAbove1500);

    boolean allRentAbove300 = properties.stream()
            .allMatch(p -> p.calculateMonthlyRent() > 300);
    System.out.println("All rent > 300: " + allRentAbove300);

    boolean noRentBelow200 = properties.stream()
            .noneMatch(p -> p.calculateMonthlyRent() < 200);
    System.out.println("No rent < 200: " + noRentBelow200);

    System.out.println("\nSecond 3 cheapest:");
    properties.stream()
            .sorted(Comparator.comparingDouble(Property::calculateMonthlyRent))
            .skip(3)
            .limit(3)
            .forEach(p -> System.out.println("Location: " + p.getLocation() + ", Rent: " + p.calculateMonthlyRent()));
}
