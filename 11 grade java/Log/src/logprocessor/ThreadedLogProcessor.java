package logprocessor;

import java.util.*;
import java.util.concurrent.*;

public class ThreadedLogProcessor {
    public static void processFiles(List<String> filePaths, LogAnalyzerStrategy strategy) throws InterruptedException {
        ExecutorService executor = Executors.newFixedThreadPool(filePaths.size());
        List<Future<List<LogRecord>>> futures = new ArrayList<>();

        for (String path : filePaths) {
            futures.add(executor.submit(() -> LogFileReader.readFile(path)));
        }

        for (Future<List<LogRecord>> future : futures) {
            try {
                List<LogRecord> records = future.get();
                strategy.analyze(records);
            } catch (ExecutionException e) {
                e.printStackTrace();
            }
        }

        executor.shutdown();
        executor.awaitTermination(1, TimeUnit.MINUTES);
        strategy.printResult();
    }
}
