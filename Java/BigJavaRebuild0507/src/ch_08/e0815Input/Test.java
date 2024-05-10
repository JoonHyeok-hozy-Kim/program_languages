package ch_08.e0815Input;

import java.util.Scanner;

public class Test {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String prompt = "Type characters : ";
        String error = "Invalid length!";
        Input.readInt(in, prompt, error, 3, 4);
    }
}
