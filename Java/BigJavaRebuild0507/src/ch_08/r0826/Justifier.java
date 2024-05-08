package ch_08.r0826;

import java.util.ArrayList;

public class Justifier {
    private ArrayList<TextLine> lines = new ArrayList<>();
    private int lineLength;

    public Justifier(int lineLength){
        this.lineLength = lineLength;
    }

    public void addText(String text){
        TextLine currLine = new TextLine(lineLength);
        String currString = "";

        for (int i=0; i<text.length(); i++){
            if (i % lineLength == 0){
                currLine.setContent(currString);
                lines.add(currLine);

                currLine = new TextLine(lineLength);
                currString = text.substring(i, i+1);
            } else {
                currString += text.substring(i, i+1);
            }
        }

        lines.remove(0);
        if (currString.length() > 0){
            while (currString.length() < lineLength) currString += " ";
            currLine.setContent(currString);
            lines.add(currLine);
        }
    }

    public String[] getJustifedText(){
        String[] result = new String[this.lines.size()];
        for (int i=0; i<this.lines.size(); i++){
            result[i] = this.lines.get(i).getContent();
        }
        return result;
    }
}
