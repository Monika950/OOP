class SmartLight implements SmartDevice {
    private int brightness;
    private String color;

    private SmartLight(int brightness, String color) {
        this.brightness = brightness;
        this.color = color;
    }

    public void turnOn() {
        System.out.println("Smart Light is turned on with brightness: " + brightness + " and color: " + color);
    }

    public static class Builder {
        private int brightness = 50;
        private String color = "White";

        public Builder setBrightness(int brightness) {
            this.brightness = brightness;
            return this;
        }

        public Builder setColor(String color) {
            this.color = color;
            return this;
        }

        public SmartLight build() {
            return new SmartLight(brightness, color);
        }
    }
}