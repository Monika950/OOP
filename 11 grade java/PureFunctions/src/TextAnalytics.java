import java.util.*;
import java.util.stream.Collectors;

public class TextAnalytics {

    public static String removePunctuation(String text) {
        if (text == null || text.isEmpty()) {
            return "";
        }
        return text.replaceAll("[\\p{Punct}]", ""); //all punctuations
    }

    public static String toLowerCase(String text) {
        if (text == null || text.isEmpty()) {
            return "";
        }
        return text.toLowerCase();
    }

    public static List<String> splitIntoWords(String text) {
        if (text == null || text.isEmpty()) {
            return Collections.emptyList();
        }
        return Arrays.asList(text.split("\\s+")); //whitespaces
    }

    public static List<String> removeStopWords(List<String> words, Set<String> stopWords) {
        if (words == null || words.isEmpty()) {
            return Collections.emptyList();
        }
        return words.stream()
                .filter(word -> !stopWords.contains(word))
                .collect(Collectors.toList());
    }

    public static Map<String, Integer> calculateFrequencies(List<String> words) {
        if (words == null || words.isEmpty()) {
            return Collections.emptyMap();
        }
        Map<String, Integer> frequencyMap = new HashMap<>();
        for (String word : words) {
            frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
        }
        return frequencyMap;
    }

    public static List<String> sortWordsByFrequency(Map<String, Integer> frequencies) {
        if (frequencies == null || frequencies.isEmpty()) {
            return Collections.emptyList();
        }
        return frequencies.entrySet().stream()
                .sorted((a, b) -> b.getValue().compareTo(a.getValue()))
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

    public static List<String> analyzeText(String text, Set<String> stopWords) {
        if (text == null || text.isEmpty()) {
            return Collections.emptyList();
        }

        String cleanedText = removePunctuation(text);
        String lowerCaseText = toLowerCase(cleanedText);
        List<String> words = splitIntoWords(lowerCaseText);
        List<String> filteredWords = removeStopWords(words, stopWords);
        Map<String, Integer> frequencies = calculateFrequencies(filteredWords);
        return sortWordsByFrequency(frequencies);
    }
}