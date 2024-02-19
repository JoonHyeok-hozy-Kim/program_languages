package exercise;

public class Letter {
    private String recipientName;
    private String lines;
    private String senderName;

    public Letter(String from, String to){
        this.recipientName = to;
        this.senderName = from;
        this.lines = "\n";
    }

    public void addLine(String line){
        this.lines = this.lines.concat(line).concat("\n");
    }

    public String getText(){
        String result = "Dear ";
        result = result.concat(this.recipientName);
        result = result.concat(":\n");
        result = result.concat(this.lines);
        result = result.concat("\nSincerely,\n\n");
        result = result.concat(this.senderName);

        return result;
    }
}
