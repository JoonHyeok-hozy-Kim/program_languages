package ch_08.p0805;

import java.util.ArrayList;
import java.util.Scanner;

public class Table {
    private ArrayList<ArrayList<String>> data = new ArrayList<>();

    public Table(){}

    public ArrayList<String> parseLine(String line){
        ArrayList<String> result = new ArrayList<>();
        String temp = "";
        boolean singleQuoteFlag = false;
        boolean doubleQuotePass = false;
        for (int i=0; i<line.length(); i++){
            if (doubleQuotePass) {
                doubleQuotePass = false;
                continue;
            } else if (line.charAt(i) == '"'){
                if (i < line.length()-1 && line.charAt(i+1) == '"'){
                    temp += "\"";
                    doubleQuotePass = true;
                } else if (singleQuoteFlag){
                    if (i == line.length()-1 || line.charAt(i+1) != ','){
                        result.clear();
                        return result;
                    }
                    singleQuoteFlag = false;
                } else {
                    singleQuoteFlag = true;
                }
            } else if (line.charAt(i) == ','){
                if (singleQuoteFlag) {
                    temp += ",";
                } else {
                    result.add(temp);
                    temp = "";
                }
            } else {
                temp += line.charAt(i);
            }
        }
        if (!temp.equals("")){
            result.add(temp);
        }
        return result;
    }

    public void addLine(String line){
        ArrayList<String> parsed = this.parseLine(line);
        if (parsed.size() == 0) {
            System.out.println("Invalid line! Not added.");
            return;
        }
        // System.out.println(parsed);
        this.data.add(parsed);
    }

    public String getEntry(int row, int column){
        String errorIndexOutOfRange = "[Error] Index out of range!";
        if (row >= this.data.size() || column >= this.data.get(row).size()) return errorIndexOutOfRange;
        return this.data.get(row).get(column);
    }

    public int rows(){
        return this.data.size();
    }

    public int columns(){
        int currMax = 0;
        for (int i=0; i<this.data.size(); i++){
            currMax = Math.max(currMax, this.data.get(i).size());
        }
        return currMax;
    }
}
