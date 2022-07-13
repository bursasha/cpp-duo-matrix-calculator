#include "CMatrix.h"
#include "CMatrixDense.h"
#include "CMatrixSparse.h"
#include "CException.h"

CMatrix::CMatrix (const size_t rows, const size_t columns)
: m_Rows (rows), m_Columns (columns), m_Elements (rows * columns), m_DeterminantSign (true)
{
}

shared_ptr<CMatrix> CMatrix::createMatrix (const size_t rows, const size_t columns,
														 const vector<double>& input_elements)
{
	shared_ptr<CMatrix> matrix;
	double density = getDensity (rows, columns, input_elements);

	if (density > m_DensityBoundary)
		matrix = make_shared<CMatrixDense> (rows, columns, input_elements);
	else
		matrix = make_shared<CMatrixSparse> (rows, columns, input_elements);
	
	return matrix;
}

void CMatrix::print () const
{
	(m_Columns <= 10 && m_Rows <= 10) ? this->printToConsole () : this->saveToFile ();
}

bool CMatrix::closeEnough (const double x, const double y)
{
	return fabs (x - y) < m_Inaccuracy;
}

void CMatrix::printToConsole () const
{
	 cout << endl;
	 for (size_t i = 0; i < m_Rows; i++)
	 {
		for (size_t j = 0; j < m_Columns; j++)
			 cout << setw (13) << setprecision (7) << getElement (i, j) << " ";
		cout << endl;
	 }
	 cout << endl;
}

void CMatrix::saveToFile () const
{
	ofstream ofs ("ResultMatrix.txt");

	if (!ofs.is_open ())
	{
		ofs.close ();
		throw CFileOpeningException ();
	}
	else
	{
		cout << "The result matrix is saving to ResultMatrix.txt." << endl;

		ofs << m_Rows << ", " << m_Columns << endl;
		for (size_t i = 0; i < m_Rows; i++)
		{
			for (size_t j = 0; j < m_Columns; j++)
				 ofs << setw (13) << setprecision (7) << getElement (i, j) << " ";
			ofs << endl;
		}

		ofs.close ();
	}
}

double CMatrix::getDensity (const size_t rows, const size_t columns, const vector<double>& input_elements)
{
	size_t all_elements = rows * columns, zero_elements = 0, density;
	
	for (auto &x : input_elements)
	{
		if (closeEnough (x, 0))
			zero_elements++;
	}

	density = (all_elements - zero_elements) / all_elements;
	return density;
}
