#include "CException.h"

void CMatricesDimensionsException::exception ()
{
	 std::cerr << "The matrices are not of suitable dimensions." << std::endl;
}

void CSquareMatrixException::exception ()
{
	 std::cerr << "The number of rows does not correspond to the number of columns, it is not square." << std::endl;
}

void CIrreversibleException::exception ()
{
	 std::cerr << "The determinant of the matrix is 0, the matrix is irreversible." << std::endl;
}

void CIndexesException::exception ()
{
	 std::cerr << "The entered indexes go beyond the matrix dimensions." << std::endl;
}

void CFileOpeningException::exception ()
{
	 std::cerr << "The exception occurred when opening the file." << std::endl;
}

void CFileFormattingException::exception ()
{
	 std::cerr << "The opened file for reading the matrix is incorrectly formatted." << std::endl;
}

void CEOFException::exception ()
{
	 std::cerr << "The program was interrupted by the completion of the input." << std::endl;
}
