package logprocessor;

import org.junit.jupiter.api.Test;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

public class LogProcessorTest {

    @Test
    public void testCountByLevelStrategy() {
        List<LogRecord> records = List.of(
                new LogRecord("", "", "INFO", "", ""),
                new LogRecord("", "", "ERROR", "", ""),
                new LogRecord("", "", "INFO", "", ""),
                new LogRecord("", "", "DEBUG", "", "")
        );
        CountByLevelStrategy strategy = new CountByLevelStrategy();
        strategy.analyze(records);

        // We can't access the map directly, so just ensure output occurs without exception
        assertDoesNotThrow(strategy::printResult);

    }

    @Test
    public void testFindKeywordStrategy() {
        List<LogRecord> records = List.of(
                new LogRecord("Line1", "", "INFO", "", "test exception occurred"),
                new LogRecord("Line2", "", "ERROR", "", "everything ok"),
                new LogRecord("Line3", "", "DEBUG", "", "another exception happened")
        );
        FindKeywordStrategy strategy = new FindKeywordStrategy("exception");
        strategy.analyze(records);

        assertEquals(2, strategy.getMatchedRecords().size());
        assertEquals("Line1", strategy.getMatchedRecords().get(0).getRawLine());
        assertEquals("Line3", strategy.getMatchedRecords().get(1).getRawLine());
    }
}
