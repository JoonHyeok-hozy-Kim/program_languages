package ch_10.exercises.Measurer;

public class Data {
    public static double average(Object[] objects, Measurer meas){
        if (objects.length == 0) return 0;
        double sum = 0;
        for (Object obj: objects){
            sum += meas.measure(obj);
        }
        return sum / objects.length;
    }    

    public static double max(Object[] objects, Measurer m){
        if (objects.length == 0) return 0;
        double result = Double.MIN_VALUE;
        for (Object o: objects){
            result = Math.max(result, m.measure(o));
        }
        return result;
    }
}
