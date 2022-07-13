#ifndef MATRIXCALCULATOR_CPARSER_H
#define MATRIXCALCULATOR_CPARSER_H

#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * @brief
 * The class responsible for entering and processing the entered information
 * from the console and from the file.
 * */
class CParser
{
public:
	 /**
	  * @brief
	  * A function that accepts a selection option from the console.
	  * @param option - a variable for recording an option.
	  * @throw CEOFException
	  * */
	 static void parseOption (size_t& option);

	 /**
	  * @brief
	  * A function that accepts matrix dimensions from the console.
	  * @param rows - a variable for recording number of rows of the entered matrix.
	  * @param columns - a variable for recording number of columns of the entered matrix.
	  * @throw CEOFException.
	  * */
	 static void parseDimensions (int& rows, int& columns);

	 /**
	  * @brief
	  * A function that accepts operation type from the console.
	  * @param operation - a variable for recording an operation type.
	  * @throw CEOFException.
	  * */
	 static void parseOperation (string& operation);

	 /**
	  * @brief
	  * An auxiliary function for checking the correctness of the type of operation.
	  * @param operation - a variable for checking an operation type.
	  * @throw CEOFException.
	  * */
	 static string toupperOperation (string operation);

	 /**
	  * @brief
	  * A function that accepts a constant from the console for product operation.
	  * @param constant - a variable for recording a constant.
	  * @throw CEOFException.
	  * */
	 static void parseConstant (double& constant);

	 /**
	  * @brief
	  * A function that accepts indexes of element for trim operation.
	  * @param row_idx - a row index for trim operation.
	  * @param column_idx - a column index for trim operation.
	  * @throw CEOFException.
	  * */
	 static void parseIndexes (int& row_idx, int& column_idx);

	 /**
	  * @brief
	  * A function that accepts numbers of rows and columns of the matrix for the next parsing of its elements.
	  * @param rows - a number of rows.
	  * @param columns - a number of columns.
	  * @return vector of all parsed elements.
	  * @throw CEOFException.
	  * */
	 static vector<double> parseElements (const int rows, const int columns);

	 /**
	  * @brief
	  * A function that loads a matrix from a file.
	  * @param rows - a number of rows.
	  * @param columns - a number of columns.
	  * @return vector of all parsed elements.
	  * @throw CEOFException, CFileOpeningException, CFileFormattingException.
	  * */
	 static vector<double> parseFile (int& rows, int& columns);

};

#endif // MATRIXCALCULATOR_CPARSER_H
