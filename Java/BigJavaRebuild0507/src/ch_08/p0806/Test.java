package ch_08.p0806;

public class Test {
    public static Barcode b = new Barcode();

    public static void barcodeToNumTest(){
        for (int i=0; i<10; i++){
            System.out.println(b.numToBarcode(i));
        }
    }

    public static void zipToBarcodesTest(){
        System.out.println(b.zipToBarcodes("95014"));
    }

    public static void numToBarcodeTest(){
        String barcode;
        for (int i=0; i<10; i++){
            barcode = b.numToBarcode(i);
            System.out.println(i + " > " + barcode + " > " + b.barcodeToNum(barcode));
        }
    }

    public static void barcodesToZipTest(){
        String zip = "95014";
        String barcodes = b.zipToBarcodes(zip);
        System.out.println(zip + " > " + barcodes + " > " + b.barcodesToZip(barcodes));
    }

    public static void main(String[] args){
        // barcodeToNumTest();
        // zipToBarcodesTest();
        // numToBarcodeTest();
        barcodesToZipTest();
    }
}
