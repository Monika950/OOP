import java.util.List;

public class Student {
    private int id;
    private String name;
    private Test test;
    private List<String> answers;

    public Student(int id, String name, Test test, List<String> answers) {
        this.id = id;
        this.name = name;
        this.test = test;
        this.answers = answers;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Test getTest() {
        return test;
    }

    public List<String> getAnswers() {
        return answers;
    }

    public int calculateScore() {
        int score = 0;
        List<Task> tasks = test.getTasks();

        for (int i = 0; i < tasks.size(); i++) {
            if (i < answers.size() && answers.get(i).equals(tasks.get(i).getCorrectAnswer())) {
                score += tasks.get(i).getPoints();
            }
        }
        return score;
    }
}
