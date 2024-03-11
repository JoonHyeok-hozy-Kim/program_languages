package exercise;

public class Time05 {
    int hour;
    int minute;

    public Time05(int hour, int minute){
        this.hour = hour;
        this.minute = minute;
    }

    public int compareTo(Time05 other){
        if (this.hour < other.hour){
            return -1;
        } else if (this.hour == other.hour){
            if (this.minute < other.minute){
                return -1;
            } else if (this.minute == other.minute){
                return 0;
            }
        }
        return 1;
    }
}
