package ch_08.p0801;

public class ComboLock {
    private final int MINVAL = 0;
    private final int NUMBEROFVAL = 40;
    private int[] password = new int[3];
    private int currCnt;
    private int currDial;

    public ComboLock(int secret1, int secret2, int secret3) {
        this.password[0] = secret1;
        this.password[1] = secret2;
        this.password[2] = secret3;

        this.currDial = this.MINVAL;
        this.reset();
    }

    public void reset() { 
        this.currCnt = 0;
    }

    public void turnLeft(int ticks) { 
        this.currDial -= ticks;
        while (this.currDial < 0) this.currDial += this.NUMBEROFVAL;
        if (this.currDial == this.password[this.currCnt] && this.currCnt < 3) this.currCnt++;
    }

    public void turnRight(int ticks) { 
        this.currDial = (this.currDial + ticks) % this.NUMBEROFVAL;
        if (this.currDial == this.password[this.currCnt]) this.currCnt++;
    }

    public boolean open() { 
        if (this.currCnt == 3) return true;
        return false;
    }

}
