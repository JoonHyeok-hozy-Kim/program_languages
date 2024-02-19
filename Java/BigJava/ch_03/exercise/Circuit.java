package exercise;

public class Circuit {
    private int s1;
    private int s2;

    public Circuit(){
        s1 = 0;
        s2 = 0;
    }

    public int getFirstSwitchState(){
        return s1;
    }

    public int getSecondSwitchState(){
        return s2;
    }

    public int getLampState(){
        if (s1+s2 > 0){
            return 1;
        } else{
            return 0;
        }
    }

    public void toggleFirstSwitch(){
        s1 = (s1+1)%2;
    }

    public void toggleSecondSwitch(){
        s2 = (s2+1)%2;
    }

    public int getSwitchState(int s){
        if (s == 1){
            return getFirstSwitchState();
        } else {
            return getSecondSwitchState();
        }
    }

    public void toggleSwitch(int s){
        if (s==1){
            toggleFirstSwitch();
        } else {
            toggleSecondSwitch();
        }
    }
}
