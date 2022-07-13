#include "CMatrixSparse.h"

CMatrixSparse::CMatrixSparse (const size_t rows, const size_t columns, const vector<double>& input_elements)
: CMatrix (rows, columns)
{
	for (size_t i = 0; i < m_Rows; i++)
	{
		for (size_t j = 0; j < m_Columns; j++)
		{
			double input_element = input_elements[(i * m_Columns) + j];
			if (!CMatrix::closeEnough (input_element, 0))
			{
				 size_t index = ((i * m_Columns) + j);
				 m_SparseElements.insert (make_pair (index, input_element));
			}
		}
	}
}

double CMatrixSparse::getElement (const size_t row_pos, const size_t column_pos) const
{
	 size_t index = ((row_pos * m_Columns) + column_pos);
	 auto get_element = m_SparseElements.find (index);
	 return (get_element != m_SparseElements.end()) ? get_element->second : 0;
}
