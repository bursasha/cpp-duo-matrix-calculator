#include "CCalculator.h"
#include "CUnaryOperation.h"
#include "CBinaryOperation.h"
#include "CParser.h"
#include "CException.h"

CCalculator::CCalculator ()
: lhs_rows (), lhs_columns (), rhs_rows (), rhs_columns (), lhs_m (), rhs_m (), result_m ()
{
}

CCalculator::~CCalculator ()
{
}

void CCalculator::run ()
{
	 try
	 {
		  size_t option;
		  string operation;

		  cout << "********************************************************************************" << endl;

		  cout << "You have launched the matrix calculator." << endl << endl;
		  cout << "First, fill in 2 matrices which you will be able to work with later." << endl;
		  cout << "Then there will be available different calculator operations." << endl;
		  cout << "If you want to load a matrix from a file, it should be formatted as follows:" << endl;
		  cout << "in the first line, separated by commas, there are the dimensions of the matrix" << endl;
		  cout << "(the number of rows and columns), and then all the elements." << endl << endl;

		  cout << "********************************************************************************" << endl;
		  cout << "Select if you want to load the first matrix (X) from a file." << endl;
		  cout << "0 = yes" << endl;
		  cout << "1 = no" << endl;
		  CParser::parseOption (option);
		  if (option == 0)
		  {
				vector<double> input_elements = CParser::parseFile (lhs_rows, lhs_columns);
				lhs_m = CMatrix::createMatrix (this->lhs_rows, this->lhs_columns, input_elements);
				cout << "The (X) matrix was successfully uploaded." << endl << endl;
		  }
		  else if (option == 1)
		  {
				cout << "Enter the number of rows and columns of the first matrix (X):" << endl;
				CParser::parseDimensions (this->lhs_rows, this->lhs_columns);
				cout << "Enter the elements of the first matrix (X):" << endl;

				vector<double> input_elements = CParser::parseElements (this->lhs_rows, this->lhs_columns);
				lhs_m = CMatrix::createMatrix (this->lhs_rows, this->lhs_columns, input_elements);
		  }

		  cout << "********************************************************************************" << endl;

		  cout << "Select if you want to load the second matrix (Y) from a file." << endl;
		  cout << "0 = yes" << endl;
		  cout << "1 = no" << endl;
		  CParser::parseOption (option);
		  if (option == 0)
		  {
				vector<double> input_elements = CParser::parseFile (rhs_rows, rhs_columns);
				rhs_m = CMatrix::createMatrix (this->rhs_rows, this->rhs_columns, input_elements);
				cout << "The (Y) matrix was successfully uploaded." << endl << endl;
		  }
		  else if (option == 1)
		  {
				cout << "Enter the number of rows and columns of the second matrix (Y):" << endl;
				CParser::parseDimensions (this->rhs_rows, this->rhs_columns);
				cout << "Enter the elements of the second matrix (Y):" << endl;

				vector<double> input_elements = CParser::parseElements (this->rhs_rows, this->rhs_columns);
				rhs_m = CMatrix::createMatrix (this->rhs_rows, this->rhs_columns, input_elements);
		  }

		  while (operation != "EXIT")
		  {
				cout << "********************************************************************************" << endl;
				cout << "Available operations:" << endl;
				cout << "SUM | SUBTRACTION | PRODUCT | TRANSPOSE | GEM (Gaussian elimination) | INVERSE" << endl;
				cout << "DETERMINANT | HORIZONTAL_JOIN | VERTICAL_JOIN | PRINT | TRIM | CHANGE | EXIT" << endl;
				cout << "Enter the type of operation:" << endl;
				CParser::parseOperation (operation);

				if (operation == "SUM")
				{
					 if (lhs_rows != rhs_rows || lhs_columns != rhs_columns)
						  throw CMatricesDimensionsException ();
					 cout << "X + Y:" << endl;
					 result_m = CBinaryOperation::sum (lhs_m, rhs_m);
					 result_m->print ();
				}

				else if (operation == "SUBTRACTION")
				{
					 if (lhs_rows != rhs_rows || lhs_columns != rhs_columns)
						  throw CMatricesDimensionsException ();
					 cout << "Select if you want (X - Y) or (Y - X)." << endl;
					 cout << "0 = (X - Y)" << endl;
					 cout << "1 = (Y - X))" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X - Y:" << endl;
						  result_m = CBinaryOperation::subtraction (lhs_m, rhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y - X:" << endl;
						  result_m = CBinaryOperation::subtraction (rhs_m, lhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "PRODUCT")
				{
					 cout << "Select if you want a product of matrices or with a constant." << endl;
					 cout << "0 = matrices" << endl;
					 cout << "1 = constant" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "Select if you want (X * Y) or (Y * X)." << endl;
						  cout << "0 = (X * Y)" << endl;
						  cout << "1 = (Y * X))" << endl;
						  CParser::parseOption (option);
						  if (option == 0)
						  {
								if (lhs_columns != rhs_rows)
									 throw CMatricesDimensionsException ();
								cout << "X * Y:" << endl;
								result_m = CBinaryOperation::product (lhs_m, rhs_m);
								result_m->print ();
						  }
						  else if (option == 1)
						  {
								if (rhs_columns != lhs_rows)
									 throw CMatricesDimensionsException ();
								cout << "Y * X:" << endl;
								result_m = CBinaryOperation::product (rhs_m, lhs_m);
								result_m->print ();
						  }
					 }
					 else if (option == 1)
					 {
						  cout << "Enter a constant other than 0:" << endl;
						  double constant;
						  CParser::parseConstant (constant);
						  cout << "Select if you want to multiplicate the matrix (X) or (Y)." << endl;
						  cout << "0 = (X)" << endl;
						  cout << "1 = (Y)" << endl;
						  CParser::parseOption (option);
						  if (option == 0)
						  {
								cout << "X * " << constant << ":" << endl;
								result_m = CBinaryOperation::product (lhs_m, constant);
								result_m->print ();
						  }
						  else if (option == 1)
						  {
								cout << "Y * " << constant << ":" << endl;
								result_m = CBinaryOperation::product (rhs_m, constant);
								result_m->print ();
						  }
					 }

				}

				else if (operation == "HORIZONTAL_JOIN")
				{
					 if (lhs_rows != rhs_rows)
						  throw CMatricesDimensionsException ();
					 cout << "Select if you want to join (XY) or (YX)." << endl;
					 cout << "0 = (XY)" << endl;
					 cout << "1 = (YX)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X join Y:" << endl;
						  result_m = CBinaryOperation::joinHorizontally (lhs_m, rhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y join X:" << endl;
						  result_m = CBinaryOperation::joinHorizontally (rhs_m, lhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "VERTICAL_JOIN")
				{
					 if (lhs_columns != rhs_columns)
						  throw CMatricesDimensionsException ();
					 cout << "Select if you want to join (X/Y) or (Y/X)." << endl;
					 cout << "0 = (X/Y)" << endl;
					 cout << "1 = (Y/X)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X join Y:" << endl;
						  result_m = CBinaryOperation::joinVertically (lhs_m, rhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y join X:" << endl;
						  result_m = CBinaryOperation::joinVertically (rhs_m, lhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "TRANSPOSE")
				{
					 cout << "Select if you want to transpose (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X^T:" << endl;
						  result_m = CUnaryOperation::transpose (lhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y^T:" << endl;
						  result_m = CUnaryOperation::transpose (rhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "GEM")
				{
					 cout << "Select if you want to gem (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X after Gaussian elimination:" << endl;
						  result_m = CUnaryOperation::gaussianElimination (lhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y after Gaussian elimination:" << endl;
						  result_m = CUnaryOperation::gaussianElimination (rhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "PRINT")
				{
					 cout << "Select if you want to print (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  cout << "X:" << endl;
						  lhs_m->print ();
					 }
					 else if (option == 1)
					 {
						  cout << "Y:" << endl;
						  rhs_m->print ();
					 }
				}

				else if (operation == "INVERSE")
				{
					 cout << "Select if you want to invert (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  if (lhs_rows != lhs_columns)
								throw CSquareMatrixException ();
						  cout << "X^(-1):" << endl;
						  result_m = CUnaryOperation::inverse (lhs_m);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  if (rhs_rows != rhs_columns)
								throw CSquareMatrixException ();
						  cout << "Y^(-1):" << endl;
						  result_m = CUnaryOperation::inverse (rhs_m);
						  result_m->print ();
					 }
				}

				else if (operation == "DETERMINANT")
				{
					 cout << "Select if you want to get the determinant of (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  if (lhs_rows != lhs_columns)
								throw CSquareMatrixException ();
						  double determinant = CUnaryOperation::determinant (lhs_m);
						  cout << "X determinant: " << determinant << endl;
					 }
					 else if (option == 1)
					 {
						  if (rhs_rows != rhs_columns)
								throw CSquareMatrixException ();
						  double determinant = CUnaryOperation::determinant (rhs_m);
						  cout << "Y determinant: " << determinant << endl;
					 }
				}

				else if (operation == "TRIM")
				{
					 cout << "Select if you want to trim (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  int row_idx, column_idx;
						  cout << "Enter the row and the column indexes from which the matrix (X) will be trimmed:" << endl;
						  CParser::parseIndexes (row_idx, column_idx);
						  if (row_idx >= lhs_rows || column_idx >= lhs_columns)
								throw CIndexesException ();
						  cout << "Trimmed X:" << endl;
						  result_m = CUnaryOperation::trim (lhs_m, row_idx, column_idx);
						  result_m->print ();
					 }
					 else if (option == 1)
					 {
						  int row_idx, column_idx;
						  cout << "Enter the row and the column indexes from which the matrix (Y) will be trimmed:" << endl;
						  CParser::parseIndexes (row_idx, column_idx);
						  if (row_idx >= rhs_rows || column_idx >= rhs_columns)
								throw CIndexesException ();
						  cout << "Trimmed Y:" << endl;
						  result_m = CUnaryOperation::trim (rhs_m, row_idx, column_idx);
						  result_m->print ();
					 }
				}

				else if (operation == "CHANGE")
				{
					 cout << "Select if you want to load the matrix from a file." << endl;
					 cout << "0 = yes" << endl;
					 cout << "1 = no" << endl;
					 CParser::parseOption (option);
					 int tmp_rows, tmp_columns;
					 if (option == 0)
					 {
						  vector<double> input_elements = CParser::parseFile (tmp_rows, tmp_columns);
						  result_m = CMatrix::createMatrix (tmp_rows, tmp_columns, input_elements);
					 }
					 else if (option == 1)
					 {
						  cout << "Enter the number of rows and columns of the matrix:" << endl;
						  CParser::parseDimensions (tmp_rows, tmp_columns);
						  cout << "Enter the elements of the matrix:" << endl;
						  vector<double> input_elements = CParser::parseElements (tmp_rows, tmp_columns);
						  result_m = CMatrix::createMatrix (tmp_rows, tmp_columns, input_elements);
					 }

					 cout << "Select if you want to change (X) or (Y)." << endl;
					 cout << "0 = (X)" << endl;
					 cout << "1 = (Y)" << endl;
					 CParser::parseOption (option);
					 if (option == 0)
					 {
						  lhs_m = result_m;
						  cout << "The (X) matrix was successfully changed." << endl << endl;
					 }
					 else if (option == 1)
					 {
						  rhs_m = result_m;
						  cout << "The (Y) matrix was successfully changed." << endl << endl;
					 }
				}

				else if (operation == "EXIT")
					 cout << "You exit the calculator." << endl;
		  }
	 }

	 catch (CException& exc)
	 {
		  exc.exception ();
	 }
}
