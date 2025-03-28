abstract class ItineraryBuilder {
    protected Itinerary itinerary;

    public ItineraryBuilder() {
        this.itinerary = new Itinerary();
    }

    public abstract ItineraryBuilder addFlight(String airline, String departure, String arrival);
    public abstract ItineraryBuilder addHotel(String name, String location, int nights);
    public abstract ItineraryBuilder addActivity(String name, String location);
    public abstract ItineraryBuilder addTransport(String type, String provider);

    public Itinerary getItinerary() {
        return itinerary;
    }
}

