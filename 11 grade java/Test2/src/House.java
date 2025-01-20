class House extends Property {
    private double yardCharge;
    private double baseMonthlyRent;

    public House(String location, double baseMonthlyRent, double yardCharge) {
        super(location);
        this.baseMonthlyRent = baseMonthlyRent;
        this.yardCharge = yardCharge;
    }

    public double getBaseMonthlyRent() {
        return baseMonthlyRent;
    }

    public void setBaseMonthlyRent(double baseMonthlyRent) {
        this.baseMonthlyRent = baseMonthlyRent;
    }

    public double getYardCharge() {
        return yardCharge;
    }

    public void setYardCharge(double yardCharge) {
        this.yardCharge = yardCharge;
    }

    @Override
    public double calculateMonthlyRent() {
        return baseMonthlyRent + yardCharge;
    }
}