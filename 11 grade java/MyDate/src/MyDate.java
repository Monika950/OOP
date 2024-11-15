public class MyDate {
    private int day;
    private Month month;
    private int year;

    public MyDate(int day, Month month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        if(day >= 1 && day <= 31)//dovurshi
            this.day = day;
    }

    public Month getMonth() {
        return month;
    }

    public void setMonth(Month month) {
        if(month>=1 && month<=12 ) {
            this.month = month;
        }
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
}
