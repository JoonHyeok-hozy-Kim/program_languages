package ch_08.r0826;

public class TextLine {
    private int length;
    private String content;

    public TextLine(int length){
        this.length = length;
    }

    public boolean hasContent(){
        if (this.content.length() == this.length) return true;
        return false;
    }

    public boolean setContent(String content){
        if (content.length() != this.length){
            return false;
        }
        this.content = content;
        return true;
    }

    public String getContent(){
        if (this.content.length() == this.length) return this.content;
        return "";
    }
}
