
class SmartAC implements SmartDevice {
    private int temperature;
    private String mode;

    private SmartAC(int temperature, String mode) {
        this.temperature = temperature;
        this.mode = mode;
    }

    public void turnOn() {
        System.out.println("Smart AC is turned on at " + temperature + "°C in " + mode + " mode.");
    }

    public static class Builder {
        private int temperature = 24;
        private String mode = "Cool";

        public Builder setTemperature(int temperature) {
            this.temperature = temperature;
            return this;
        }

        public Builder setMode(String mode) {
            this.mode = mode;
            return this;
        }

        public SmartAC build() {
            return new SmartAC(temperature, mode);
        }
    }
}