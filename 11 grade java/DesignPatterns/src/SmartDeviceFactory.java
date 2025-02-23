class SmartDeviceFactory {
    public static SmartDevice createDevice(String type) {
        switch (type.toLowerCase()) {
            case "light":
                return new SmartLight.Builder().setBrightness(50).setColor("White").build();
            case "ac":
                return new SmartAC.Builder().setTemperature(24).setMode("Cool").build();
            case "speaker":
                return new SmartSpeaker.Builder().setVolume(50).setLanguage("English").build();
            default:
                throw new IllegalArgumentException("Unknown device type: " + type);
        }
    }
}