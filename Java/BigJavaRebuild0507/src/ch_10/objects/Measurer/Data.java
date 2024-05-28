package ch_10.objects.Measurer;

public class Data {
    public static double average(Object[] objects, Measurer meas){
        if (objects.length == 0) return 0;
        double sum = 0;
        for (Object obj: objects){
            sum += meas.measure(obj);
        }
        return sum / objects.length;
    }    
}
