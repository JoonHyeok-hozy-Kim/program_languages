package ch_09.exercises;

import java.io.OutputStream;
import java.io.PrintStream;
import java.io.Writer;
import java.rmi.server.LogStream;

public class r0912{
    public static void main(String[] args){
        System.out.println(System.out instanceof PrintStream);
        System.out.println(System.out instanceof Object);
        System.out.println(System.out instanceof OutputStream);
        // System.out.println(System.out instanceof String);
        System.out.println(System.out instanceof LogStream);
        // System.out.println(System.out instanceof Writer);
    }
}