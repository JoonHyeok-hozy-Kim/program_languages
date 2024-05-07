[Back to Big Java main](../../../main.md)

# 8.6 Packages
### Concept) Packages
- Desc.)
  - A Java **package** is a set of related classes.
- e.g.)
    |Package     |Purpose                                             |Sample Class     |
    |:-:         |:--                                                 |:-:              |
    |java.lang   |Language support                                    |Math             |
    |java.util   |Utilities                                           |Random           |
    |java.io     |Input and output                                    |PrintStream      |
    |java.awt    |Abstract Windowing                                  |Toolkit Color    |
    |java.applet |Applets                                             |Applet           |
    |java.net    |Networking                                          |Socket           |
    |java.sql    |Database access through Structured Query Language   |ResultSet        |   
    |javax.swing |Swing user interface                                |JButton          |
    |org.w3c.dom |Document Object Model for XML documents             |Document         |

<br>

## 8.6.1 Organizing Related Classes into Packages
#### Syntax) Putting a Class into a Package
In the ```class``` script...
```java
package PACKAGE_NAME;
```
- cf.) Default Package
  - A special package with no name.
  - If you did not include any package statement at the top of your source file, its classes are placed in the default package. 

<br>

## 8.6.2 Importing Packages
#### Syntax) 
1. Refer to the package and its class by their full names
   ```java
   java.util.Scanner in = new java.util.Scanner(System.in);
   ```
2. Import a package with a ```import``` statement.
   ```java
   import java.util.Scanner
   ```
   ```java
   import java.util.*   // Import all.
   ```

<br>

## 8.6.3 Package Names
#### Concept) Name Clash
- Desc.)
  - Different classes sharing a same class name.
- e.g.) The ```Timer``` class in...
  - ```java.util```
  - ```javax.swing```


<br>

## 8.6.4 Packages and Source Files
#### Prop.) A source file must be located in a subdirectory that matches the package name.
- e.g.)
  - The classes in the package ```com.horstmann.bigjava``` should be located at a subdirectory *com/horstmann/bigjava*.

<br>

#### Prop.) Package Access
- If a class, instance variable, or method has no ```public``` or ```private``` modifier, then all methods of classes in the **same package** can access the feature.


<br>

[Back to Big Java main](../../../main.md)