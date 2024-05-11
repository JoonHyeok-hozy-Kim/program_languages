package ch_08.p0805;

public class Test {
    public static void main(String[] args){
        String[] testStrings = {
            "John Jacob Astor,1763,1848",
            "\"William Backhouse Astor, Jr.\",1829,1892",
            "\"John Jacob \"\"Jakey\"\" Astor VI\",1912,1992",
        };

        Table t = new Table();

        for (String s: testStrings){
            t.addLine(s);
        }

        System.out.println(t.rows());
        System.out.println(t.columns());
        //System.out.println(t.rows());
        System.out.println(t.getEntry(1, 1));
        System.out.println(t.getEntry(2, 0));
    }
}
