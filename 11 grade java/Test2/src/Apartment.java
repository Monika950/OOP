class Apartment extends Property {
    private double baseMonthlyRent;

    public Apartment(String location, double baseMonthlyRent) {
        super(location);
        this.baseMonthlyRent = baseMonthlyRent;
    }

    @Override
    public double calculateMonthlyRent() {
        return baseMonthlyRent;
    }
}