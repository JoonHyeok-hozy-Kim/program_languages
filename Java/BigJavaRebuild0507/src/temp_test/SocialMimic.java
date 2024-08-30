import java.util.HashMap;
import java.util.PriorityQueue;

public class SocialMimic {
    public static HashMap<String, PriorityQueue> ParseString(String str){
        HashMap<String, PriorityQueue> result = new HashMap<>();

        for (String line : str.split("\n")){
            // System.out.println(line);
            // System.out.println(line.getClass());
            String[] splt1 = line.split(":");
            PriorityQueue<String>
            for (String friend : splt1[1].split(",")){

            }

        }


        return result;
    }

    public static String MaxSocial(){
        return "";
    }

    public static int CommonLink(String p1, String p2){
        return 0;
    }
}
