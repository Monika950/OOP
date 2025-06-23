package logprocessor;

public class LogRecord {
    private final String rawLine;
    private final String timestamp;
    private final String level;
    private final String sourceClass;
    private final String message;

    public LogRecord(String rawLine, String timestamp, String level, String sourceClass, String message) {
        this.rawLine = rawLine;
        this.timestamp = timestamp;
        this.level = level;
        this.sourceClass = sourceClass;
        this.message = message;
    }

    public String getRawLine() {
        return rawLine;
    }

    public String getLevel() {
        return level;
    }

    public String getMessage() {
        return message;
    }

    public String getSourceClass() {
        return sourceClass;
    }
}