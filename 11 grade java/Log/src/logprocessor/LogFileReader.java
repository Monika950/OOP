package logprocessor;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class LogFileReader {
    public static List<LogRecord> readFile(String path) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(path))) {
            return reader.lines()
                    .filter(line -> !line.trim().isEmpty())
                    .map(line -> {
                        String[] parts = line.trim().split("\\s+", 5);

                        String timestamp = parts.length > 1 ? parts[0] + " " + parts[1] : "";
                        String level = parts.length > 2 ? parts[2] : "";
                        String sourceClass = parts.length > 3 ? parts[3] : "";
                        String message = parts.length > 4 ? parts[4] : "";

                        return new LogRecord(line, timestamp, level, sourceClass, message);
                    })
                    .collect(Collectors.toList());
        }
    }
}
