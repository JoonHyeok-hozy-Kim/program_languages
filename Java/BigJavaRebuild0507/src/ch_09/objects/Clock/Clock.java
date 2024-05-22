package ch_09.objects.Clock;

import java.util.*;

public class Clock {
    private int hour;
    private int minute;
    
    public Clock(){
        Date d = new Date();
        String hhmmss = d.toString().split(" ")[2];
        this.hour = Integer.parseInt(hhmmss.split(":")[0]);
        this.hour = Integer.parseInt(hhmmss.split(":")[1]);
    }

    public String getHours(){
        return Integer.toString(this.hour);
    }

    public String getMinutes(){
        return Integer.toString(this.minute);
    }
}
