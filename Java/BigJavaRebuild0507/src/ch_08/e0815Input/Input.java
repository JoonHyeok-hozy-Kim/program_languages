package ch_08.e0815Input;

import java.util.Scanner;

public class Input {
    public static int readInt(Scanner in, String prompt, String error, int min, int max){
        int strLength;
        while (true){
            System.out.print(prompt);
            strLength = in.nextLine().length();
            if (strLength >= min && strLength <= max) return strLength;
            System.out.println(error);
        }
    }
}
