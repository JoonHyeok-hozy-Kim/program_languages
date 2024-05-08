package ch_08.r0826;

public class Test {

    public static void main(String args[]){
        String T = "Consider the task of fully justifying a paragraph of text to a target length, by putting as many words as possible on each line and evenly distributing extra spaces so that each line has the target length.";
    
        Justifier j = new Justifier(30);
        j.addText(T);
        for (String s: j.getJustifedText()){
            System.out.println(s);
        }
    }

}
