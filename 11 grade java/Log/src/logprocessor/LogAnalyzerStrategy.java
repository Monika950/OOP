package logprocessor;

import java.util.List;

public interface LogAnalyzerStrategy {
    void analyze(List<LogRecord> records);
    void printResult();
}