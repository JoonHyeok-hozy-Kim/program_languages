package ch_10.objects.Measurable;

public class Data{
    public Data(){}

    public static double average(Measurable[] objects){
        if (objects.length == 0) return 0;

        double sum = 0;
        for (Measurable obj: objects){
            sum += obj.getMeasure();
        }

        return sum / objects.length;
    }

    public static Measurable max(Measurable[] objects){
        if (objects.length == 0) return null;

        Measurable result = objects[0];
        for (Measurable obj: objects){
            if (obj.getMeasure() > result.getMeasure()) result = obj;
        }

        return result;
    }
}