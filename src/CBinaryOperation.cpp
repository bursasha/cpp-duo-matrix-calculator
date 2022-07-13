#include "CBinaryOperation.h"

shared_ptr<CMatrix> CBinaryOperation::sum (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	vector<double> result_elements;
	size_t result_rows = lhs_m->m_Rows, result_columns = lhs_m->m_Columns;
	
	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = lhs_m->getElement (i, j) + rhs_m->getElement (i, j);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::subtraction (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	vector<double> result_elements;
	size_t result_rows = lhs_m->m_Rows, result_columns = lhs_m->m_Columns;
	
	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = lhs_m->getElement (i, j) - rhs_m->getElement (i, j);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::product (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	vector<double> result_elements;
	size_t result_rows = lhs_m->m_Rows, result_columns = rhs_m->m_Columns, products_count = lhs_m->m_Columns;
	
	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = 0;

			for (size_t k = 0; k < products_count; k++)
				result_element += (lhs_m->getElement (i, k) * rhs_m->getElement (k, j));

			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::product (const shared_ptr<CMatrix> m, const double factor)
{
	vector<double> result_elements;
	size_t result_rows = m->m_Rows, result_columns = m->m_Columns;
	
	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = m->getElement (i, j) * factor;
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::joinHorizontally (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	vector<double> result_elements;
	size_t result_rows = lhs_m->m_Rows, result_columns = (lhs_m->m_Columns + rhs_m->m_Columns);

	for (size_t i = 0; i < result_rows; i++)
	{
		for (size_t j = 0; j < lhs_m->m_Columns; j++)
		{
			double result_element = lhs_m->getElement (i, j);
			result_elements.push_back (result_element);
		}

		for (size_t j = 0; j < rhs_m->m_Columns; j++)
		{
			double result_element = rhs_m->getElement (i, j);
			result_elements.push_back (result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}

shared_ptr<CMatrix> CBinaryOperation::joinVertically (const shared_ptr<CMatrix> lhs_m, const shared_ptr<CMatrix> rhs_m)
{
	vector<double> result_elements;
	size_t result_rows = (lhs_m->m_Rows + rhs_m->m_Rows), result_columns = lhs_m->m_Columns;

	for (size_t i = 0; i < lhs_m->m_Rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = lhs_m->getElement(i, j);
			result_elements.push_back(result_element);
		}
	}

	for (size_t i = 0; i < rhs_m->m_Rows; i++)
	{
		for (size_t j = 0; j < result_columns; j++)
		{
			double result_element = rhs_m->getElement(i, j);
			result_elements.push_back(result_element);
		}
	}

	auto result_matrix = CMatrix::createMatrix (result_rows, result_columns, result_elements);
	return result_matrix;
}
