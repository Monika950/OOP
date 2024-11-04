package bg.sofia.uni.fmi.mjt.vehiclerent.vehicle;

public class Car extends Vehicle {

    private String id;
    private String model;
    private FuelType fuelType;
    private int numberOfSeats;
    private double pricePerWeek;
    private double pricePerDay;
    private double pricePerHour;

    public Car(String id,
               String model,
               FuelType fuelType,
               int numberOfSeats,
               double pricePerWeek,
               double pricePerDay,
               double pricePerHour) {
        super(id,model);
        this.fuelType = fuelType;
        this.numberOfSeats = numberOfSeats;
        this.pricePerWeek = pricePerWeek;
        this.pricePerDay = pricePerDay;
        this.pricePerHour = pricePerHour;
    }


}
