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
}