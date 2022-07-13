#include "CMatrixDense.h"

CMatrixDense::CMatrixDense (const size_t rows, const size_t columns, const vector<double>& input_elements)
: CMatrix (rows, columns), m_DenseElements (input_elements)
{
}

double CMatrixDense::getElement (const size_t row_pos, const size_t column_pos) const
{
	return m_DenseElements[(row_pos * m_Columns) + column_pos];
}
