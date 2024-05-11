package ch_08.p0806;

import java.util.Arrays;

public class Barcode {
    private final int[] weights = {7,4,2,1,0};
    private final char[] bars = {'|', ':'};
    private final int ASCIIZERO = 48; 

    public Barcode(){}

    public String numToBarcode(int n){
        String barcode = "";
        int barCnt = 0;
        if (n == 0) n = 11;
        for (int w: this.weights){
            if (n < w || (barCnt == 2 && w == 0)) barcode += this.bars[1];
            else {
                barcode += this.bars[0];
                barCnt++;
                n -= w;
            }
        }
        return barcode;
    }

    public int getCheckNum(int[] zipInt){
        int result = 0;
        for (int x: zipInt){
            result += x;
        }
        result = 10 - (result % 10);
        return result;
    }

    public String zipToBarcodes(String zip){
        String barcodes = "" + this.bars[0];
        int[] zipInt = new int[zip.length()];
        int currNum;
        for (int i=0; i<zip.length(); i++){
            currNum = zip.charAt(i) - this.ASCIIZERO;
            barcodes += this.numToBarcode(currNum);
            zipInt[i] = currNum;
        }
        barcodes += this.numToBarcode(this.getCheckNum(zipInt));
        barcodes += this.bars[0];
        return barcodes;
    }

    public int barcodeToNum(String barcode){
        int result = 0;
        for (int i=0; i<barcode.length(); i++){
            if (barcode.charAt(i) == this.bars[0]){
                result += this.weights[i];
            }
        }
        if (result == 11) result = 0;
        return result;
    }

    public String barcodesToZip(String barcodes){
        String result = "";
        if (barcodes.length() != 1 + 5*5 + 5 + 1){
            return "Wrong format (length).";
        }

        barcodes = barcodes.substring(1, barcodes.length()-1);
        int[] zipInt = new int[6];
        for (int i=0; i<6; i++){
            zipInt[i] += this.barcodeToNum(barcodes.substring(i*5, (i+1)*5));
            if (i < 5) result += zipInt[i];
        }

        if (this.getCheckNum(Arrays.copyOfRange(zipInt, 0, 5)) != zipInt[5]){
            return "Invalidate format.";
        }
        return result;
    }
}

