#ifndef MATRIXCALCULATOR_CMATRIXSPARSE_H
#define MATRIXCALCULATOR_CMATRIXSPARSE_H

#include "CMatrix.h"

/**
 * @brief
 * A class representing a sparse matrix.
 * */
class CMatrixSparse : public CMatrix
{
public:
	 /**
	  * @brief
	  * A constructor for setting up a sparse matrix.
	  * @param rows - a number of rows in the matrix being created.
	  * @param columns - a number of columns in the matrix being created.
	  * @param input_elements - all the elements of the matrix being created.
	  * */
	 CMatrixSparse (const size_t rows, const size_t columns, const vector<double>& input_elements);

private:
	 /**
	  * @brief
	  * A data structure for efficient storage of non-zero elements of a sparse matrix.
	  * The key is the linear index of the element, the value is the element itself.
	  * */
	 unordered_map<size_t, double> m_SparseElements;

	 /**
	  * @brief
	  * Function for getting the desired element.
	  * @param row_pos - a row index of the desired element.
	  * @param column_pos - a column index of the desired element.
	  * @return the element due to its linear index.
	  * */
	 double getElement (const size_t row_pos, const size_t column_pos) const override;

};

#endif // MATRIXCALCULATOR_CMATRIXSPARSE_H
