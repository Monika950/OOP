package logprocessor;

import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.concurrent.*;

public class LogProcessor {
    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
            System.err.println("Използване: java LogProcessor <log_files...> <analyzer_type> [keyword]");
            return;
        }

        List<String> filePaths = new ArrayList<>();
        for (int i = 0; i < args.length - 1; i++) filePaths.add(args[i]);
        String analysisType = args[args.length - 1];

        LogAnalyzerStrategy strategy;
        if ("count_by_level".equals(analysisType)) {
            strategy = new CountByLevelStrategy();
        } else if ("find_keyword".equals(analysisType) && args.length > 2) {
            strategy = new FindKeywordStrategy(args[args.length - 1]);
            filePaths = filePaths.subList(0, args.length - 2);
        } else {
            System.err.println("Невалиден тип анализ.");
            return;
        }

        ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());
        List<Future<?>> futures = new ArrayList<>();

        for (String filePath : filePaths) {
            List<String> lines = Files.readAllLines(Paths.get(filePath));
            List<LogRecord> records = new ArrayList<>();
            for (String line : lines) {
                String[] parts = line.split(" ", 5);
                if (parts.length < 5) continue;
                String timestamp = parts[0] + " " + parts[1];
                String level = parts[2];
                String sourceClass = parts[3];
                String message = parts[4];
                records.add(new LogRecord(line, timestamp, level, sourceClass, message));
            }

            futures.add(executor.submit(() -> strategy.analyze(records)));
        }

        for (Future<?> f : futures) f.get();

        executor.shutdown();
        strategy.printResult();
    }
}
