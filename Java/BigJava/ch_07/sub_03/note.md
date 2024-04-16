[Back to Big Java main](../../main.md)

# 7.3 Common Array Algorithms
## 7.3.1 Filling
- e.g.)
  ```java
  for (int i=0; i<values.length; i++){
    values[i] = i*i;
  }
  ```

<br>

## 7.3.2 Sum and Average Value
- e.g.)
  ```java
  double total = 0;
  for (double element : values){
    total += element;
  }

  double average = 0;
  if (values.length > 0) {average = total / values.length;}
  ```

<br>

## 7.3.3 Maximum and Minimum
- e.g.)
  ```java
  double largest = values[0];
  double smallest = values[0];

  for (element : values){
    if (element > largest) largest = element;
    if (element < smallest) smallest = element;
  }
  ```

<br>

## 7.3.4 Element Separators
- e.g.) Separating with |
  ```java
  for (int i=0; i<values.length; i++){
    if (i > 0) System.out.print(" | ");
    System.out.print(values[i])
  }
  ```
- e.g.) Using the String format of the Array class
  ```java
  System.out.println("values=" + Arrays.toString(values));
  ```

<br>

## 7.3.5 Linear Search 
- e.g.) Visit all elements until you have found a match
  ```java
  int targetValue = 100;
  int position = 0;
  boolean found = false;

  while (position < values.length && !found){
    if (values[position] == targetValue) found = true;
    else position++;
  }

  if (found) System.out.println("Found at position : " + position);
  else System.out.println("Not found.");
  ```

<br>

## 7.3.6 Removing an Element
- e.g.) Sorted Array Case
  ```java
  values[pos] = values[currentSize-1];
  currentSize--;
  ```
- e.g.) Not-Sorted Array Case
  ```java
  for (int i=pos+1; i<currentSize; i++){
    values[i-1] = values[i];
  }
  currentSize--;
  ```

<br>

## 7.3.7 Inserting an Element
- e.g.) Inserting at the end
  ```java
  if (currentSize < values.length){
    currentSize++;
    values[currentSize-1] = newElement;
  }
  ```
- e.g.) Inserting at a particular position
  ```java
  if (currentSize < values.length){
    currentSize++;
    for (int i=currentSize; i>pos; i--){
        values[i] = values[i-1];
    }
    values[pos] = newElement;
  }
  ```

<br>

## 7.3.8 Swapping Elements
- e.g.) Use a temporary variable
  ```java
  double temp = values[i];
  values[i] = values[j];
  values[j] = temp;
  ```

<br>

## 7.3.9 Copying Arrays
- e.g.) Use ```Arrays.copyOf``` method.
  ```java
  import java.util.Arrays;
  double[] copiedValues = Arrays.copyOf(values, values.length);
  ```

<br>

## 7.3.10 
- e.g.) 
  ```java
  
  ```


<br>

[Back to Big Java main](../../main.md)