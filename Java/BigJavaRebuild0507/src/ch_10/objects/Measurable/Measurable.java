package ch_10.objects.Measurable;

public interface Measurable {
    default double getMeasure() {return 0;};    // Abstract Method

    public static Measurable largest(Measurable[] objects){
        Measurable result = null;
        for (Measurable obj: objects){
            if (result == null || obj.getMeasure() > result.getMeasure()) {
                result = obj;
            }
        }
        return result;
    }

    public static Measurable smallest(Measurable[] objects){
        Measurable result = null;
        for (Measurable obj: objects){
            if (result == null || obj.getMeasure() < result.getMeasure()) {
                result = obj;
            }
        }
        return result;
    }
}
