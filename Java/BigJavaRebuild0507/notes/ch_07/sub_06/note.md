[Back to Big Java main](../../../main.md)

# 7.6 Two-Dimensional Arrays
### Concept) Two-Dimensional Array
- Def.)
  - An arrangement consisting of rows and columns of values 
- Syntax)
  ```java
  final int NUMBER_OF_ROWS = 8;
  final int NUMBER_OF_COLUMNS = 3;
  int[][] matrix = new int[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
  ```
  ```java
  int[][] matrix = {
    { 0, 3, 0 },
    { 0, 0, 1 }, 
    { 0, 0, 1 }, 
    { 1, 0, 0 }, 
    { 0, 0, 1 }, 
    { 3, 1, 1 },
    { 0, 1, 0 },
    { 1, 0, 1 }
  };
  ```

<br>

### Tech.) Accessing Elements
- e.g.)
  ```java
  for (int i=0; i<NUMBER_OF_ROWS; i++){
    for (int j=0; j<NUMBER_OF_COLUMNS; j++){
        System.out.printf("%8d", matrix[i][j]);
    }
    System.out.println();
  }
  ```
  ```java
  for (int i=0; i<NUMBER_OF_ROWS; i++){
    for (int j=0; j<matrix[i].length; j++){
        System.out.printf("%8d", matrix[i][j]);
    }
    System.out.println();
  }
  ```

<br>

### Tech.) Two-Dimensional Arrays with Variable Row Lengths
- e.g.)
  - Consider the case as follows.
    ```java
    // Declare arrays in which the row length varies.
    double[][] b = new double[3][];

    /*
     * b[0][0]                       0
     * b[1][0] b[1][1]              10  11
     * b[2][0] b[2][1] b[2][2]      20  21  22
    */

    // Allocating each row with different number of columns
    for (int i=0; i<b.length; i++){
        b[i] = new double[i+1];
    }

    // Assigning values.
    for (int i=0; i<b.length; i++){
        for (int j=0; j<b[i].length; j++){
            b[i][j] = i*10+j;
        }
    }

    // Referencing values using enhanced for loops
    for (double[] row : b){
        for (double element : row){
            System.out.printf("%f ", element);
        }
        System.out.println();
    }
    ```


<br>

[Back to Big Java main](../../../main.md)