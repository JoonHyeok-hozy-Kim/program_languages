package Java.BigJava.ch_01.ex;

import java.net.URL;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class PracticeExcercises {

    public static void e0101(){
        System.out.println("안녕!");
    }

    public static void e0102(){
        int result = 0;
        for (int i=0; i<10; i++){
            result += i;
        }
        System.out.println(result);
    }

    public static int e0103(int n){
        int result = 1;
        for (int i=0; i<n; i++){
            result *= (i+1);
        }
        System.out.println(result);
        return result;
    }

    public static void e0104(){
        float balance = 1000;
        for (int i=0; i<3; i++){
            balance *= 1.05;
        }
        System.out.println(balance);
    }

    public static void e0105(String name){
        String result;
        System.out.print('+');
        for (int i=0; i<name.length(); i++){
            System.out.print('-');
        }
        System.out.println('+');

        System.out.print('|');
        System.out.print(name);
        System.out.println('|');
        
        System.out.print('+');
        for (int i=0; i<name.length(); i++){
            System.out.print('-');
        }
        System.out.println('+');
    }

    public static void e0106(){
        String name = "Daniel";
        ArrayList<ArrayList<String>> Q = new ArrayList<ArrayList<String>>();

        for (int i=0; i<5; i++){
            ArrayList<String> q = new ArrayList<>();
            Q.add(q);
        }

        for (int i=0; i<name.length(); i++){
            if (name.charAt(i) == 'D'){
                Q.get(0).add("***  ");
                Q.get(1).add("*  * ");
                Q.get(2).add("*   *");
                Q.get(3).add("*  * ");
                Q.get(4).add("***  ");
            } else if (name.charAt(i) == 'a'){
                Q.get(0).add("  *  ");
                Q.get(1).add(" * * ");
                Q.get(2).add("*****");
                Q.get(3).add("*   *");
                Q.get(4).add("*   *");
            } else if (name.charAt(i) == 'n'){
                Q.get(0).add("*   *");
                Q.get(1).add("**  *");
                Q.get(2).add("* * *");
                Q.get(3).add("*  **");
                Q.get(4).add("*   *");
            } else if (name.charAt(i) == 'i'){
                Q.get(0).add(" *** ");
                Q.get(1).add("  *  ");
                Q.get(2).add("  *  ");
                Q.get(3).add("  *  ");
                Q.get(4).add(" *** ");
            } else if (name.charAt(i) == 'e'){
                Q.get(0).add("*****");
                Q.get(1).add("*    ");
                Q.get(2).add("**** ");
                Q.get(3).add("*    ");
                Q.get(4).add("*****");
            } else if (name.charAt(i) == 'l'){
                Q.get(0).add("*    ");
                Q.get(1).add("*    ");
                Q.get(2).add("*    ");
                Q.get(3).add("*    ");
                Q.get(4).add("*****");
            }

            for (int j=0; j<5; j++){
                Q.get(j).add(" ");
            }
        }

        for (int i=0; i<Q.size(); i++){
            for (int j=0; j<Q.get(i).size(); j++){
                System.out.print(Q.get(i).get(j));
            }
            System.out.println();
        }
    }

/*
    +   
   + +  
  +   + 
 +-----+
 | .-. |
 | | | |
 +-+-+-+ 
*/

    public static void e0110(){
        System.out.println("    +   ");
        System.out.println("   + +  ");
        System.out.println("  +   + ");
        System.out.println(" +-----+");
        System.out.println(" | .-. |");
        System.out.println(" | | | |");
        System.out.println(" +-+-+-+ ");
    }

/*
" /\_/\ -----      "
"( ' ' ) / Hello \ "
"( - ) < Junior |  "
" | | | \ Coder!/  "
"(__|__) -----     "
*/

    public static void e0111(){
        System.out.println(" /\\_/\\ -----      ");
        System.out.println("( ' ' ) / Hello \\ ");
        System.out.println("( - ) < Junior |  ");
        System.out.println(" | | | \\ Coder!/  ");
        System.out.println("(__|__) -----     ");
    }

    public static void e0114(){
        System.out.println("* * * * * * ==================================");
        System.out.println(" * * * * *                                    ");
        System.out.println("* * * * * * ==================================");
        System.out.println(" * * * * *                                    ");
        System.out.println("* * * * * * ==================================");
        System.out.println(" * * * * *                                    ");
        System.out.println("* * * * * * ==================================");
        System.out.println(" * * * * *                                    ");
        System.out.println("* * * * * * ==================================");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("==============================================");
        System.out.println("                                              ");
        System.out.println("==============================================");
    }

    public static void e0116(){
        String name = JOptionPane.showInputDialog(("What is your name?"));
        System.out.println(name);
    }

    public static void e0118() throws Exception{
        URL imageLocation = new URL("http://horstmann.com/java4everyone/duke.gif");
        JOptionPane.showMessageDialog(null, "Hello", "Title", JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));
    }

    public static void p0101(int distance, float fuel_efficiency, float train_price){
        float car_maintenance = distance / fuel_efficiency * 4;
        car_maintenance += 5 * distance;
        String result = new String();
        if (car_maintenance > train_price){
            result = "Take train";
        } else {
            result = "Drive your car.";
        }
        System.out.println(result);
        System.out.print("car_maintenance : "); 
        System.out.print(car_maintenance);
        System.out.print(" vs train_ticket_price : ");
        System.out.println(train_price);
    }

    public static void p0103(){
        double target = Math.PI / 4;
        double result = 0;
        double i = 1;
        while (Math.abs(target-result) > 0.0000001){
            result += (1/(2*i-1)) * Math.pow(-1, i+1);
            // System.out.println(String.format("%06.06f", result));
            // System.out.println(i);
            i += 1;
        }
        System.out.print(i);
        System.out.println(String.format(" %06.06f", result));
    }

    public static void p0105(int row_num, int col_num){
        ArrayList<ArrayList<String>> tile = new ArrayList<ArrayList<String>>();
        for (int i=0; i<row_num; i++){
            ArrayList<String> row = new ArrayList<String>();
            row.add("■");

            for (int j=0; j<col_num; j++){
                if (i==0 || i == row_num - 1){
                    row.add("■");
                } else if (i == row_num /2){
                    if (col_num % 2 == 0 && (j == col_num / 2 || j == col_num / 2 - 1)){
                        row.add("■");
                    } else if (col_num % 2 == 1 && (j == col_num / 2 || j == col_num / 2 - 1 || j == col_num / 2 + 1)){
                        row.add("■");
                    } else {
                        row.add("□");
                    }
                } else {
                    row.add("□");
                }
                    
            }

            row.add("■");
            tile.add(row);
        }

        for (int i=0; i<tile.size(); i++){
            for (int j=0; j<tile.get(i).size(); j++){
                System.out.print(tile.get(i).get(j));
            }
            System.out.println();
        }
    }

// ■ □

    public static void p0106(int row_num, int col_num){
        ArrayList<ArrayList<String>> B = new ArrayList<>();
        for (int i=0; i<row_num; i++){
            ArrayList<String> row = new ArrayList<String>();
            row.add("■");

            for (int j=0; j<col_num; j++){
                if (i==0 || i == row_num - 1){
                    row.add("■");
                } else {
                    row.add("□");
                }
                    
            }

            row.add("■");
            B.add(row);
        }

        for (int i=0; i<B.size(); i++){
            for (int j=0; j<B.get(i).size(); j++){
                System.out.print(B.get(i).get(j));
            }
            System.out.println();
        }

    }


    public static void main(String[] args){
        p0106(6, 11);
    }    
}
