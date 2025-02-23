class SmartSpeaker implements SmartDevice {
    private int volume;
    private String language;

    private SmartSpeaker(int volume, String language) {
        this.volume = volume;
        this.language = language;
    }

    public void turnOn() {
        System.out.println("Smart Speaker is playing at volume: " + volume + " in language: " + language);
    }

    public static class Builder {
        private int volume = 50;
        private String language = "English";

        public Builder setVolume(int volume) {
            this.volume = volume;
            return this;
        }

        public Builder setLanguage(String language) {
            this.language = language;
            return this;
        }

        public SmartSpeaker build() {
            return new SmartSpeaker(volume, language);
        }
    }
}