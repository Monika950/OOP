import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        Task task1 = new Task("Коя е столицата на България?", List.of("София", "Пловдив", "Варна", "Бургас"), 5, "София");
        Task task2 = new Task("Колко е 2 + 2?", List.of("3", "4", "5", "6"), 3, "4");

        Test test = new Test("2025-01-13", "12А", List.of(task1, task2));

        Student student1 = new Student(1, "Иван Иванов", test, List.of("София", "4"));
        Student student2 = new Student(2, "Мария Петрова", test, List.of("Пловдив", "4"));

        List<Student> students = new ArrayList<>();
        students.add(student1);
        students.add(student2);

        students.sort(Comparator.comparingInt(Student::calculateScore).reversed().thenComparing(Student::getName));

        System.out.println("Резултати на учениците:");
        for (Student student : students) {
            System.out.println("Име: " + student.getName() + ", Резултат: " + student.calculateScore());
        }
    }
}
