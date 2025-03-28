class ItineraryDirector {
    private ItineraryBuilder builder;

    public ItineraryDirector(ItineraryBuilder builder) {
        this.builder = builder;
    }

    public Itinerary constructBusinessTrip() {
        return builder.addFlight("AirBusiness", "New York", "London")
                .addHotel("Grand Business Hotel", "London", 3)
                .addTransport("Taxi", "BlackCab")
                .getItinerary();
    }

    public Itinerary constructVacationTrip() {
        return builder.addFlight("VacationAir", "Paris", "Barcelona")
                .addHotel("Beach Resort", "Barcelona", 5)
                .addActivity("Snorkeling", "Costa Brava")
                .addTransport("Rental Car", "Hertz")
                .getItinerary();
    }
}


