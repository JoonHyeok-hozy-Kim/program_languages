package exercise;

public class Counter {
    private int value;
    private int limit=-1;

    public Counter(){
        value = 0;
    }

    public int getValue(){
        return value;
    }

    public void setLimit(int maximum){
        limit = maximum;
        while (value > limit){
            this.undo();
        }
    }

    public void click(){
        if (limit > -1){
            value = Math.min(value+1, limit);
        } else {
            value++;
        }
    }

    public void undo(){
        value = Math.max(value-1, 0);
    }
}
