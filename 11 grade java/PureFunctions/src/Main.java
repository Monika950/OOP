import java.util.*;

public class Main {
    public static void main(String[] args) {
        String text = "Hello, hello!! The WORLD is big, and the world is round.";
        Set<String> stopWords = new HashSet<>(Arrays.asList("the", "is", "and"));

        List<String> result = TextAnalytics.analyzeText(text, stopWords);
        System.out.println(result);
    }
}