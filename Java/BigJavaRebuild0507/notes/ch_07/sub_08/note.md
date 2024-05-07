[Back to Big Java main](../../main.md)

# 7.8 Regression 
### Concept) Test Suite
- It is a common and useful practice to make a new test whenever you find a program bug.
- Feed it to the next version after that and all subsequent versions.
- Such a collection of test cases is called a **test suite**.

<br>

### Concept) Regression Testing
- The process of checking each version of a program against a [test suite](#concept-test-suite).

<br>

### Concept) Batch Files and Shell Scripts
- Desc.)
  - If you need to perform the same tasks repeatedly on the command line, then it is worth learning about the automation features offered by your operating system.
  - Under Windows, you use **batch files** to execute a number of commands automatically.
    - e.g.)
      - Create the ```test.bat``` file.
        ```
        java ScoreTester1
        java ScoreTester < input1.txt
        java ScoreTester < input2.txt
        ```
      - Run the ```test.bat``` file.
        ```
        test.bat
        ```
  - On Linux, Mac OS, and UNIX, **shell scripts** are used for the same purpose.
    - e.g.)
      - Run the ```test.bat``` file.
        ```
        sh test.bat
        ```


<br>

[Back to Big Java main](../../main.md)