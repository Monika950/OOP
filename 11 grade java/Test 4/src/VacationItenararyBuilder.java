class VacationItineraryBuilder extends ItineraryBuilder {
    @Override
    public ItineraryBuilder addFlight(String airline, String departure, String arrival) {
        itinerary.addFlight(new Flight(airline, departure, arrival));
        return this;
    }

    @Override
    public ItineraryBuilder addHotel(String name, String location, int nights) {
        itinerary.addHotel(new Hotel(name, location, nights));
        return this;
    }

    @Override
    public ItineraryBuilder addActivity(String name, String location) {
        itinerary.addActivity(new Activity(name, location));
        return this;
    }

    @Override
    public ItineraryBuilder addTransport(String type, String provider) {
        itinerary.addTransport(new Transport(type, provider));
        return this;
    }
}
