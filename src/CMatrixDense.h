#ifndef MATRIXCALCULATOR_CMATRIXDENSE_H
#define MATRIXCALCULATOR_CMATRIXDENSE_H

#include "CMatrix.h"

/**
 * @brief
 * A class representing a sparse matrix.
 * */
class CMatrixDense : public CMatrix
{
public:
	 /**
	  * @brief
	  * A constructor for setting up a dense matrix.
	  * @param rows - a number of rows in the matrix being created.
	  * @param columns - a number of columns in the matrix being created.
	  * @param input_elements - all the elements of the matrix being created.
	  * */
	 CMatrixDense (const size_t rows, const size_t columns, const vector<double>& input_elements);

private:
	 /**
	  * @brief
	  * A data structure for efficient storage of non-zero elements of a dense matrix.
	  * */
	 vector<double> m_DenseElements;

	 /**
	  * @brief
	  * Function for getting the desired element.
	  * @param row_pos - a row index of the desired element.
	  * @param column_pos - a column index of the desired element.
	  * @return the element due to its linear index.
	  * */
	 double getElement (const size_t row_pos, const size_t column_pos) const override;

};

#endif // MATRIXCALCULATOR_CMATRIXDENSE_H
