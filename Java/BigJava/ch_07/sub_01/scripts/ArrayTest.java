package sub_01.scripts;

public class ArrayTest {
    public static void arrayBuildingTest(){
        double[] doubleArray1 = {1.0,2.0,3.0,4.0,5.0};
        double[] doubleArray2 = new double[10];
        for (int i=0; i<10; i++){
            doubleArray2[i] = (double) i;
        }

        for (int i=0; i<doubleArray1.length; i++){
            System.out.printf("%f ", doubleArray1[i]);
        }
        System.out.print("\n\n");
        for (int i=0; i<doubleArray2.length; i++){
            System.out.printf("%f ", doubleArray2[i]);
        }
        System.out.println("???");
    }

    public static void advanceReferencingTest(){
        double[] arr = {1,2,3};
        for (double e : arr){
            System.out.println(e);
        }
    }

    public static void main(String[] args){
        advanceReferencingTest();
    }
    
}
