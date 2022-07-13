#ifndef MATRIXCALCULATOR_CMATRIX_H
#define MATRIXCALCULATOR_CMATRIX_H

#include <cmath>
#include <vector>
#include <unordered_map>
#include <utility>
#include <memory>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief
 * A general abstract class representing an interface for a sparse and a dense matrix.
 */
class CMatrix
{
	 /**
	  * @brief
	  * This class provides access to its attributes and methods for performing various mathematical and
	  * linear operations on matrices.
	  * */
	 friend class CBinaryOperation;
	 friend class CUnaryOperation;

public:
	 /**
	  * @brief
	  * Basic matrix constructor.
	  * @param rows - a number of rows in the matrix being created.
	  * @param columns - a number of columns in the matrix being created.
	  * */
	 CMatrix (const size_t rows, const size_t columns);
	 virtual ~CMatrix () = default;

	 /**
	  * @brief
	  * A function that creates a sparse or dense matrix based on the number of zero elements.
	  * If the percentage of non-zero elements is less than or equal to 30%,
	  * then the function returns a sparse matrix, otherwise it returns a dense matrix.
	  * @param rows - a number of rows in the matrix being created.
	  * @param columns - a number of columns in the matrix being created.
	  * @param input_elements - a vector containing all the elements of the matrix being created.
	  * @return a dense or a sparse matrix.
	  * */
	 static shared_ptr<CMatrix> createMatrix (const size_t rows, const size_t columns,
														  const vector<double>& input_elements);

	 /**
	  * @brief
	  * A function that writes a matrix to the console or to a file.
	  * If the matrix has more than 10 rows or columns, then it is saved to a file ResultMatrix.txt.
	  * */
	 void print () const;

	 /**
	  * @brief
	  * A function for comparing 2 numbers of the double type.
	  * @param x - the first double number.
	  * @param y - the second double number.
	  * @return true, if two numbers are close enough taking into account the inaccuracy, false otherwise.
	  * */
	 static bool closeEnough (const double x, const double y);

protected:
	 /**
	  * @brief
	  * A number of rows, columns, and elements in the matrix.
	  * */
	 size_t m_Rows, m_Columns, m_Elements;

	 /**
	  * @brief
	  * A determinant sign of the matrix, true = +, false = -.
	  * */
	 bool m_DeterminantSign;

	 /**
	  * @brief
	  * The inaccuracy error of comparing 2 double numbers;
	  * the limit of the content of non-zero elements to create a sparse or dense matrix.
	  * */
	 constexpr const static double m_Inaccuracy = 1e-9, m_DensityBoundary = 0.3;

	 /**
	  * @brief
	  * A function for displaying the matrix to the console.
	  * */
	 void printToConsole () const;

	 /**
	  * @brief
	  * Function for saving the matrix to a file ResultMatrix.txt.
	  * @throw CFileOpeningException if the file could not be opened for writing.
	  * */
	 void saveToFile () const;

	 /**
	  * @brief
	  * A function that determines the percentage of non-zero elements in the matrix.
	  * @param rows - a number of rows in the considered matrix.
	  * @param columns - a number of columns in the considered matrix.
	  * @param input_elements - all the elements of the considered matrix.
	  * @return density of the matrix.
	  * */
	 static double getDensity (const size_t rows, const size_t columns, const vector<double>& input_elements);

	 /**
	  * @brief
	  * A virtual function that returns an element of the matrix.
	  * @param row_pos - a row index of the desired element.
	  * @param column_pos - a column index of the desired element.
	  * @return desired element of the matrix.
	  * */
	 virtual double getElement (const size_t row_pos, const size_t column_pos) const = 0;

};

#endif // MATRIXCALCULATOR_CMATRIX_H
