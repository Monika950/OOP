import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class Test {
    private Date date;
    private String group;
    private List<Task> tasks;

    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd");

    public Test(String date, String group, List<Task> tasks) {
        try {
            this.date = DATE_FORMAT.parse(date);
        } catch (ParseException e) {
            e.printStackTrace();
            this.date = new Date();
        }
        this.group = group;
        this.tasks = tasks;
    }

    public Date getDate() {
        return date;
    }

    public String getFormattedDate() {
        return DATE_FORMAT.format(date);
    }

    public String getGroup() {
        return group;
    }

    public List<Task> getTasks() {
        return tasks;
    }
}
