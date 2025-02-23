public class HeaterAdapter implements SmartDevice {
    private OldHeater heater;
    private int level;

    public HeaterAdapter(OldHeater heater, int level) {
        this.heater = heater;
        this.level = level;
    }

    public void turnOn() {
        heater.heatUp(level);
    }
}
