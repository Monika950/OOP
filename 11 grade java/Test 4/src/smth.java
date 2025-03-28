class Flight {
    private String airline;
    private String departure;
    private String arrival;

    public Flight(String airline, String departure, String arrival) {
        this.airline = airline;
        this.departure = departure;
        this.arrival = arrival;
    }

    @Override
    public String toString() {
        return "Flight: " + airline + " from " + departure + " to " + arrival;
    }
}

class Hotel {
    private String name;
    private String location;
    private int nights;

    public Hotel(String name, String location, int nights) {
        this.name = name;
        this.location = location;
        this.nights = nights;
    }

    @Override
    public String toString() {
        return "Hotel: " + name + ", " + location + " for " + nights + " nights";
    }
}

class Activity {
    private String name;
    private String location;

    public Activity(String name, String location) {
        this.name = name;
        this.location = location;
    }

    @Override
    public String toString() {
        return "Activity: " + name + " at " + location;
    }
}

class Transport {
    private String type;
    private String provider;

    public Transport(String type, String provider) {
        this.type = type;
        this.provider = provider;
    }

    @Override
    public String toString() {
        return "Transport: " + type + " by " + provider;
    }
}

