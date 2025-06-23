package logprocessor;

import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class CountByLevelStrategy implements LogAnalyzerStrategy {
    private final Map<String, Integer> levelCount = new ConcurrentHashMap<>();

    @Override
    public void analyze(List<LogRecord> records) {
        for (LogRecord record : records) {
            levelCount.merge(record.getLevel(), 1, Integer::sum);
        }
    }

    @Override
    public void printResult() {
        System.out.println("--- Резултати от анализ: Брой съобщения по ниво ---");
        levelCount.forEach((level, count) -> System.out.println(level + ": " + count));
    }
}