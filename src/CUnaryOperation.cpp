#include "CUnaryOperation.h"
#include "CBinaryOperation.h"
#include "CException.h"

shared_ptr<CMatrix> CUnaryOperation::transpose (const shared_ptr<CMatrix> m)
{
	vector<double> result_elements;
	size_t result_rows = m->m_Columns, result_columns = m->m_Rows;

	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
			result_elements.push_back (m->getElement (j, i));
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CUnaryOperation::gaussianElimination (const shared_ptr<CMatrix> m)
{
	vector<double> result_elements;
	size_t result_rows = m->m_Rows, result_columns = m->m_Columns, switch_count = 0;

	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
			result_elements.push_back (m->getElement (i, j));
	}

	for (size_t i = 0; i < (result_rows - 1); i++)
	{
		size_t max_element_row = findMaxElementRowInColumn (result_elements, result_rows, result_columns, i);

		if (CMatrix::closeEnough (result_elements[(max_element_row * result_columns) + i], 0))
			continue;

		if (i != max_element_row)
		{
			switchRows (result_elements, result_columns, i, max_element_row);
			switch_count++;
		}

		for (size_t j = (i + 1); j < result_rows; j++)
		{
			 double factor =
						-(result_elements[(j * result_columns) + i] / result_elements[(i * result_columns) + i]);

			 addRowMultiple (result_elements, result_columns, j, i, factor);
		}
	}

	 auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	 result_matrix->m_DeterminantSign = (switch_count % 2 == 0) ? true : false;
	 return result_matrix;
}

shared_ptr<CMatrix> CUnaryOperation::inverse (const shared_ptr<CMatrix> m)
{
	 vector<double> identity_elements;
	 size_t identity_rows = m->m_Rows, identity_columns = m->m_Columns;

	 for (size_t i = 0; i < identity_rows; i++)
	 {
		  for (size_t j = 0; j < identity_columns; j++)
				i == j ? identity_elements.push_back (1) : identity_elements.push_back (0);
	 }

	 auto identity_matrix = CMatrix::createMatrix (identity_rows, identity_columns, identity_elements);
	 auto augmented_matrix = CBinaryOperation::joinHorizontally (m, identity_matrix);
	 auto gem_augmented_matrix = gaussianElimination (augmented_matrix);
	 size_t augmented_rows = gem_augmented_matrix->m_Rows;

	 for (size_t i = 0; i < augmented_rows; i++)
	 {
		  if (CMatrix::closeEnough (gem_augmented_matrix->getElement (i, i), 0))
				throw CIrreversibleException ();
	 }

	 vector<double> reduced_gem_augmented_elements;
	 size_t reduced_gem_augmented_rows = gem_augmented_matrix->m_Rows,
	 reduced_gem_augmented_columns = gem_augmented_matrix->m_Columns;

	 for (size_t i = 0; i < reduced_gem_augmented_rows; i++)
	 {
		  for (size_t j = 0; j < reduced_gem_augmented_columns; j++)
				reduced_gem_augmented_elements.push_back (gem_augmented_matrix->getElement (i, j));
	 }

	 for (size_t i = (reduced_gem_augmented_rows - 1); i > 0; i--)
	 {
		  for (size_t j = 0; j < i; j++)
		  {
				double factor =
						  -(reduced_gem_augmented_elements[(j * reduced_gem_augmented_columns) + i] /
						  reduced_gem_augmented_elements[(i * reduced_gem_augmented_columns) + i]);

				addRowMultiple (reduced_gem_augmented_elements, reduced_gem_augmented_columns, j, i, factor);
		  }
	 }

	 for (size_t i = 0; i < reduced_gem_augmented_rows; i++)
	 {
		  double factor = 1 / reduced_gem_augmented_elements[(i * reduced_gem_augmented_columns) + i];

		  multiplyRow (reduced_gem_augmented_elements, reduced_gem_augmented_columns, i, factor);
	 }

	 vector<double> result_elements;
	 size_t result_rows = reduced_gem_augmented_rows, result_columns = (reduced_gem_augmented_columns / 2);

	 for (size_t i = 0; i < reduced_gem_augmented_rows; i++)
	 {
		  for (size_t j = reduced_gem_augmented_rows; j < reduced_gem_augmented_columns; j++)
				result_elements.push_back (reduced_gem_augmented_elements[(i * reduced_gem_augmented_columns) + j]);
	 }

	 auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	 return result_matrix;
}

double CUnaryOperation::determinant (const shared_ptr<CMatrix> m)
{
	 size_t result_rows = m->m_Rows;
	 if (result_rows == 2)
	 {
		  double determinant = (m->getElement (0, 0) * m->getElement (1, 1)) - (m->getElement (1, 0) * m->getElement (0, 1));
		  return determinant;
	 }

	 auto result_matrix = gaussianElimination (m);
	 double determinant = (result_matrix->m_DeterminantSign) ? 1 : -1;

	 for (size_t i = 0; i < result_rows; i++)
	 {
		  if (CMatrix::closeEnough (result_matrix->getElement (i, i), 0))
				return 0;
		  determinant *= result_matrix->getElement (i, i);
	 }

	 return determinant;
}

shared_ptr<CMatrix> CUnaryOperation::trim (const shared_ptr<CMatrix> m, const size_t row_pos, const size_t column_pos)
{
	 vector<double> result_elements;
	 size_t original_rows = m->m_Rows, original_columns = m->m_Columns, result_rows = original_rows - row_pos,
	 result_columns = original_columns - column_pos;

	 for (size_t i = row_pos; i < original_rows; i++)
	 {
		  for (size_t j = column_pos; j < original_columns; j++)
				result_elements.push_back (m->getElement (i, j));
	 }

	 auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	 return result_matrix;
}

size_t CUnaryOperation::findMaxElementRowInColumn (const vector<double>& matrix_elements, const size_t rows,
																	const size_t columns, const size_t column_pos)
{
	double max_element = fabs (matrix_elements[(column_pos * columns) + column_pos]);
	size_t max_element_row = column_pos;
	
	for (size_t i = column_pos + 1; i < rows; i++)
	{
		double current_element = fabs (matrix_elements[(i * columns) + column_pos]);

		if (current_element > max_element)
		{
			max_element = current_element;
			max_element_row = i;
		}
	}

	return max_element_row;
}

void CUnaryOperation::switchRows (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
											 const size_t row_j)
{
	vector<double> temp_row_i;
	for (size_t k = 0; k < columns; k++)
		temp_row_i.push_back (matrix_elements[(row_i * columns) + k]);

	for (size_t k = 0; k < columns; k++)
		matrix_elements[(row_i * columns) + k] = matrix_elements[(row_j * columns) + k];

	for (size_t k = 0; k < columns; k++)
		matrix_elements[(row_j * columns) + k] = temp_row_i[k];
}

void CUnaryOperation::multiplyRow (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
											  const double factor)
{
	for (size_t k = 0; k < columns; k++)
		matrix_elements[(row_i * columns) + k] *= factor;
}

void CUnaryOperation::addRowMultiple (vector<double>& matrix_elements, const size_t columns, const size_t row_i,
												  const size_t row_j, const double factor)
{
	for (size_t k = 0; k < columns; k++)
		matrix_elements[(row_i * columns) + k] += (matrix_elements[(row_j * columns) + k] * factor);
}
