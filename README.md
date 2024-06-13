Конечно! Вот обновленный README для вашего проекта с более подробной информацией о структуре проекта и стеком технологий:

---

# CMatrixCalculator 🧮

## Project Structure: 📁
- `src/`: Contains the source code files for the matrix calculator.
- `examples/`: Includes example files for loading matrices.
- `assets/`: Holds images and documentation files.
- `DOCUMENTATION.md`: Additional documentation for the project.
- `Doxyfile`: Configuration file for generating documentation with Doxygen.
- `Makefile`: Used for building the project.
- `README.md`: The main README file for the project.
- `prohlaseni.txt`: Declaration file.
- `zadani.txt`: Project assignment file.

## Technology Stack: 🔍
- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Techniques:** Polymorphism, Inheritance, Encapsulation
- **Libraries:** STL (Standard Template Library)
- **Build Tools:** Makefile for building the project
- **Documentation Tools:** Doxygen for generating documentation
- **Data Structures:** Dense and Sparse Matrices
- **Algorithms:** Matrix operations (addition, subtraction, multiplication, etc.), advanced linear algebra operations (transposition, inversion, determinant calculation, Gaussian elimination)
- **Other:** Parsers for file input and output, Exception handling

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

---

Этот README теперь включает более подробное описание структуры проекта и стека технологий, что поможет пользователям лучше понять, как организованы файлы и какие технологии используются.