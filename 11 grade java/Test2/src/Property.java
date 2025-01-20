import java.util.*;
import java.util.stream.Collectors;

abstract class Property {
    protected String location;

    public Property(String location) {
        this.location = location;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public abstract double calculateMonthlyRent();
}
