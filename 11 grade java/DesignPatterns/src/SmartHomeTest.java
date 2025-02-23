public class SmartHomeTest {
    public static void main(String[] args) {
        SmartHomeManager manager = SmartHomeManager.getInstance();

        SmartDevice light = new SmartLight.Builder().setBrightness(80).setColor("Blue").build();
        SmartDevice ac = new SmartAC.Builder().setTemperature(22).setMode("Heat").build();
        SmartDevice speaker = new SmartSpeaker.Builder().setVolume(70).setLanguage("Spanish").build();

        OldHeater oldHeater = new OldHeater();
        SmartDevice adaptedHeater = new HeaterAdapter(oldHeater, 3);

        manager.addDevice(light);
        manager.addDevice(ac);
        manager.addDevice(speaker);
        manager.addDevice(adaptedHeater);

        manager.showDevices();

        light.turnOn();
        ac.turnOn();
        speaker.turnOn();
        adaptedHeater.turnOn();
    }
}