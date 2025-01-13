import java.util.List;

public class Task {
    private String condition;
    private List<String> answers;
    private int points;
    private String correctAnswer;

    public Task(String condition, List<String> answers, int points, String correctAnswer) {
        this.condition = condition;
        this.answers = answers;
        this.points = points;
        this.correctAnswer = correctAnswer;
    }

    public String getCondition() {
        return condition;
    }

    public List<String> getAnswers() {
        return answers;
    }

    public int getPoints() {
        return points;
    }

    public String getCorrectAnswer() {
        return correctAnswer;
    }
}

