# CMatrixCalculator 🧮

## What is it capable of? 🚀

### **Support for working with 2 matrices.**

**Basic operations:**
* ➕ Addition.
* ➖ Subtraction.
* ✖️ Multiplication/multiplication by a constant.
* ✂️ Trimming/joining matrices.
* 📏 Vertical/Horizontal join of matrices.
* ✏️ Changing the entered matrix by the console or file input.
* 🖥️ Output of the matrix to the console or to the file.

**Advanced linear operations:**
* 🔄 Transposition.
* 🔁 Finding the inverse matrix.
* 🧮 Search for a determinant.
* 📉 Gaussian elimination.

## Program interface: 🖥️
* Console application.
* User and file input processing.
* Support for the above commands.
* Error output depending on the problem encountered.
* To load a matrix from a file, it must be formatted as follows:
    * In the first line, separated by commas, are the dimensions of the matrix,
    * Then from the next line are its elements (example file in the `examples/` folder).

## Application of polymorphic functions: 🧬
* 2 types of matrices – dense and sparse, for efficient storage of internal elements, depending on the number of non-zero elements.
* The `getElement` function to get the desired element from the matrix, depending on its type.
* Different types of exceptions.

## Project Description: 📜
I created a console calculator for performing basic operations on different matrices. It will be possible to interact with the program by entering commands such as `ADD`, `SUBTRACT`, `PRODUCT`, `TRANSPOSE`, `DETERMINANT`, and others. When starting the calculator, the user will be greeted with a welcome message and a short guide to using the program. While working with the calculator, in case of incorrect input or other issues, the program will notify the user of the exceptions that have occurred. It will also be possible to terminate the program using a specific command.

## General basic view of the program: 🏗️
![Calculator structure](/assets/basic_structure.png)
