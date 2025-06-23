package logprocessor;

import java.util.*;
import java.util.concurrent.CopyOnWriteArrayList;

public class FindKeywordStrategy implements LogAnalyzerStrategy {
    private final String keyword;
    private final List<LogRecord> matchedRecords = new CopyOnWriteArrayList<>();

    public FindKeywordStrategy(String keyword) {
        this.keyword = keyword;
    }

    @Override
    public void analyze(List<LogRecord> records) {
        for (LogRecord record : records) {
            if (record.getMessage().contains(keyword)) {
                matchedRecords.add(record);
            }
        }
    }

    @Override
    public void printResult() {
        System.out.println("--- Резултати от анализ: Съобщения, съдържащи \"" + keyword + "\" ---");
        for (LogRecord record : matchedRecords) {
            System.out.println(record.getRawLine());
        }
    }

    public List<LogRecord> getMatchedRecords() {
        return matchedRecords;
    }
}
