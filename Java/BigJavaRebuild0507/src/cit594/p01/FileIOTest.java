package cit594.p01;

import static org.junit.Assert.assertThrows;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

import org.junit.Test;

public class FileIOTest {
    public static void main(String[] args){
        int b;
        int result=0;

        try {
            FileInputStream fis = new FileInputStream("myFile.txt");
            try{
                b = fis.read();
            } catch (IOException e1) {
                System.err.println("Error: " + e1.getMessage());
            }
            byte[] chunk = new byte[8];
            
            try{
                result = fis.read(chunk);
            } catch (IOException e2) {
                System.err.println("Error: " + e2.getMessage());
            }

            System.out.println(result);

        } catch (FileNotFoundException e) {
            System.err.println("Error: " + e.getMessage());
        }

        int x = readUntil(2, result);
    }

    public int readUntil(byte stop, FileInputStream fis){
        int count = 0;
        try{
            while (fis.read() != stop){
                count++;
            }
        } catch (IOException e2) {
            System.err.println("Error: " + e2.getMessage());
        }
        return count;
    }
}
