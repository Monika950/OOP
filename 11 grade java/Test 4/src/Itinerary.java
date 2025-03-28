import java.util.ArrayList;
import java.util.List;

class Itinerary {
    private List<Flight> flights = new ArrayList<>();
    private List<Hotel> hotels = new ArrayList<>();
    private List<Activity> activities = new ArrayList<>();
    private List<Transport> transports = new ArrayList<>();

    public void addFlight(Flight flight) {
        flights.add(flight);
    }

    public void addHotel(Hotel hotel) {
        hotels.add(hotel);
    }

    public void addActivity(Activity activity) {
        activities.add(activity);
    }

    public void addTransport(Transport transport) {
        transports.add(transport);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        flights.forEach(f -> sb.append(f).append("\n"));
        hotels.forEach(h -> sb.append(h).append("\n"));
        activities.forEach(a -> sb.append(a).append("\n"));
        transports.forEach(t -> sb.append(t).append("\n"));
        return sb.toString();
    }
}
