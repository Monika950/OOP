public class Main {
    public static void main(String[] args) {
        System.out.println("Business Trip Itinerary:");
        ItineraryBuilder businessBuilder = new BusinessItineraryBuilder();
        ItineraryDirector director = new ItineraryDirector(businessBuilder);
        Itinerary businessTrip = director.constructBusinessTrip();
        System.out.println(businessTrip);

        System.out.println("\nVacation Trip Itinerary:");
        ItineraryBuilder vacationBuilder = new VacationItineraryBuilder();
        director = new ItineraryDirector(vacationBuilder);
        Itinerary vacationTrip = director.constructVacationTrip();
        System.out.println(vacationTrip);
    }
}
