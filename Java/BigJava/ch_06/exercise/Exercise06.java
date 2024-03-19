package exercise;

import java.util.ArrayList;
import java.util.Random;

public class Exercise06{
    public static void r0602(){
        int i=0;
        int j=10;

        // while (i<j){
        //     System.out.println(i + " " + j);
        //     i++;
        //     j--;
        // }

        while (i<j){
            System.out.println(i + j);
            i++;
            j++;
        }
    }

    public static void r0604(int n){
        int temp = 0;
        while (temp*temp < n){
            System.out.println(temp*temp);
            temp += 1;
        }

        System.out.println("----------------------");

        temp = 10;
        while (temp < n){
            System.out.println(temp);
            temp += 10;
        }

        System.out.println("----------------------");

        temp = 1;
        while (temp < n){
            System.out.println(temp);
            temp *= 2;
        }
    }

    public static void r0605(){
        int temp = 2;
        int sum = 0;
        while (temp <= 100){
            sum += temp;
            temp += 2;
        }
        System.out.println(sum);

        temp = 1;
        sum = 0;
        while (temp <= 100){
            sum += temp*temp;
            temp += 1;
        }
        System.out.println(sum);

        r0605c(3, 7);
        r0605d(32677);
    }

    public static void r0605c(int a, int b){
        int temp = a;
        int sum = 0;
        if (a % 2 == 0){
            temp++;
        }
        while (temp <= b){
            sum += temp;
            temp += 2;
        }
        System.out.println(sum);
    }

    public static void r0605d(int n){
        int sum = 0;
        while (n > 0){
            if (n % 2 == 1){
                sum += n % 10;
            }
            n /= 10;
        }
        System.out.println(sum);
    }

    public static void r0614(){
        System.out.println("Su  M  T  W Th  F Sa");
        int date = -2;
        int init = (date + 7) % 7; 
        while (date <= 31){
            if (date <= 0){
                System.out.print("  ");
            } else {
                if (date % 7 == init){
                    System.out.println();
                }
                if (date < 10){
                    System.out.print(" ");
                }
                System.out.print(date);
            }
            System.out.print(" ");
            date++;
        }
    }

    public static void r0616(String str){
        String[] strList = str.split(" ");
        int sum = 0;
        int temp;
        int cnt = 0;
        for (int i=0; i<strList.length; i++){
            // System.out.println(strList[i]);
            if (i < 2) continue;
            temp = Integer.parseInt(strList[i]);
            if (temp == -1) break;
            sum += temp;
            cnt++;
        }
        System.out.println(strList[0] + " " + strList[1] + " : " + (double)(sum / cnt));
    }

    public static void r0617(String str){
        String[] strList = str.split("\\n");

        for (int i=0; i<strList.length; i++){
            // System.out.println(strList[i]);
            if (strList[i].equals("END")) break;
            r0616(strList[i]);
        }
    }

    public static void e0601(double initialBalance, double interestRate){
        int cnt = 0;
        while (initialBalance < 1000000){
            initialBalance *= 1 + interestRate/100;
            cnt ++;
        }
        System.out.printf("It takes %d year", cnt);
        if (cnt > 1) System.out.print("s");
        System.out.print(" to reach one million dollars.");
    }

    public static void e0603(String str){
        String[] strList = str.split(" ");
        int answer_a_min = Integer.parseInt(strList[0]);
        int answer_a_max = answer_a_min;
        int answer_b_odd = 0;
        int answer_b_even = 0;
        Integer[] answer_c = new Integer[strList.length];
        int sum_c = 0;
        ArrayList<Integer> answer_d = new ArrayList<>();
        int curr;
        int prev = -1;

        for (int i=0; i<strList.length; i++){
            curr = Integer.parseInt(strList[i]);
            if (i==0) prev = curr;
            answer_a_max = Math.max(curr, answer_a_max);
            answer_a_min = Math.min(curr, answer_a_min);

            if (curr % 2 == 0) answer_b_even++;
            else answer_b_odd ++;

            sum_c += curr;
            answer_c[i] = sum_c;

            if (i > 0 && prev == curr){
                if (answer_d.size() == 0 || curr != answer_d.get(answer_d.size()-1)) answer_d.add(curr);                
            }
            prev = curr;
        }

        System.out.println("A : " + answer_a_max + ", " + answer_a_min);
        System.out.println("B : " + answer_b_odd + ", " + answer_b_even);
        System.out.print("C : ");
        for (int i=0; i<answer_c.length; i++){
            System.out.print(answer_c[i] + " ");
        }
        System.out.println();
        System.out.print("D : ");
        for (int i=0; i<answer_d.size(); i++){
            System.out.print(answer_d.get(i) + " ");
        }
    }

    public static void e0604(String str){
        String a = "";
        String b = "";
        String c = "";
        int d = 0;
        char curr;
        ArrayList<Integer> e = new ArrayList<>();
        for (int i=0; i<str.length(); i++){
            curr = str.charAt(i);
            if (65 <= curr && curr <= 90){
                a += curr;
            }

            if (i==1){
                b += curr;
            }

            if ("AEIOUaeiou".indexOf(curr) != -1){
                c += "_";
                d++;
                e.add(i);
            }
            else c += curr;
        }

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(e);
    }

    public static void e0606(){
        DataSet05 d = new DataSet05();
    }

    public static void e0608(String str){
        if (str.length() <= 1){
            System.out.println(str);
            return;
        }

        Random r = new Random();
        int i;
        int j;
        String new_str = "";
        for (int k=0; k<str.length(); k++){
            new_str = "";
            i = r.nextInt(str.length()-2);
            j = r.nextInt(i+1, str.length()-1);
            if (i > 0) new_str += str.substring(0, i);
            new_str += str.charAt(j);
            if (j-i > 1) new_str += str.substring(i+1, j);
            new_str += str.charAt(i);
            if (j < str.length()-1) new_str += str.substring(j+1, str.length());
            // System.out.println(str + " > " + new_str);
            str = new_str;
        }
        System.out.println(new_str);
    }

    public static void e0610(String str){
        for (int i=0; i<str.length(); i++){
            System.out.println(str.charAt(i));
        }
    }

    public static void e0611(String str){
        for (int i=0; i<str.length(); i++){
            System.out.print(str.charAt(str.length()-1-i));
        }
    }

    public static void e0612(String str){
        for (int i=0; i<str.length(); i++){
            for (int j=0; j<str.length()-i; j++){
                System.out.println(str.substring(j, j+i+1));
            }
        }
    }

    public static void e0613(){
        int curr = 1;
        for (int i=0; i<20; i++){
            System.out.printf("2^%d = %d\n", i, curr);
            curr *= 2;
        }
        System.out.printf("2^%d = %d\n", 20, curr);
    }

    public static void e0614(int n){
        ArrayList<Integer> a = new ArrayList<>();
        while (n >= 0){
            if (n % 2 == 0) a.add(0);
            else a.add(1);
            n /= 2;

            if (n==0) break;
        }

        for (int i=0; i<a.size(); i++){
            // System.out.println(a.get(a.size()-1-i));
            System.out.println(a.get(i));
        }
    }


    public static void main(String[] args){
        // e0603("1 3 3 4 5 5 6 6 6 2");
        // System.out.println((int)'Z');
        e0614(1);
    }
}