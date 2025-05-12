public class Main {
    public static void main(String[] args) {
            System.out.println("isIsogram(\"Hallo\"): " + isIsogram("Hallo"));
            System.out.println("isIsogram(\"Morgen\"): " + isIsogram("Morgen"));

            System.out.println("\nPascal's Triangle (5 rows):");
            pascalsTriangle(5);

            System.out.println("\nPythagorean Triplets for N = 60:");
            pythagoreanTriplets(60);

            System.out.println("\nWord Count for example.txt:");
            wc("example.txt");  // Увери се, че файлът съществува в директорията на проект
    }

    public static boolean isIsogram(String str) {
        str = str.toLowerCase();
        Set<Character> seen = new HashSet<>();
        for (char c : str.toCharArray()) {
            if (Character.isLetter(c)) {
                if (seen.contains(c)) return false;
                seen.add(c);
            }
        }
        return true;
    }

    public static void pascalsTriangle(int rows) {
        for (int i = 0; i < rows; i++) {
            int number = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(number + " ");
                number = number * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }

    public static void pythagoreanTriplets(int n) {
        for (int a = 1; a < n; a++) {
            for (int b = a; b < n; b++) {
                int c = n - a - b;
                if (c > 0 && a * a + b * b == c * c) {
                    System.out.println(a + " " + b + " " + c);
                }
            }
        }
    }

    public static void wc(String filename) {
        int lines = 0, words = 0, characters = 0;

        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) {
                lines++;
                characters += line.length() + 1; // +1 for newline
                words += line.trim().isEmpty() ? 0 : line.trim().split("\\s+").length;
            }
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
            return;
        }

        System.out.println("Lines: " + lines);
        System.out.println("Words: " + words);
        System.out.println("Characters: " + characters);
    }



}
