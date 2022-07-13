#include "CParser.h"
#include "CException.h"
#include "CMatrix.h"

void CParser::parseOption (size_t& option)
{
	 while (true)
	 {
		  cin >> option;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good () && (option == 0 || option == 1))
				break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of option, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;
}

void CParser::parseDimensions (int& rows, int& columns)
{
	 while (true)
	 {
		  cin >> rows >> columns;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good () && rows > 0 && columns > 0)
				break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of dimensions, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;
}

void CParser::parseOperation (string& operation)
{
	 while (true)
	 {
		  cin >> operation;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good ())
		  {
				string toupper_operation = toupperOperation (operation);
				operation = toupper_operation;
				if (operation == "SUM" || operation == "SUBTRACTION" || operation == "PRODUCT" ||
					 operation == "HORIZONTAL_JOIN" || operation == "VERTICAL_JOIN" || operation == "TRANSPOSE" ||
					 operation == "GEM" || operation == "INVERSE" || operation == "DETERMINANT" || operation == "TRIM" ||
					 operation == "CHANGE" || operation == "PRINT" || operation == "EXIT")
					 break;
		  }
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of operation, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;
}

string CParser::toupperOperation (string operation)
{
	 transform (operation.begin(), operation.end(), operation.begin(), [](unsigned char c) { return toupper(c); });
	 return operation;
}

void CParser::parseConstant (double& constant)
{
	 while (true)
	 {
		  cin >> constant;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good () && !(CMatrix::closeEnough (constant, 0)))
				break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of constant, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;
}

void CParser::parseIndexes (int& row_idx, int& column_idx)
{
	 while (true)
	 {
		  cin >> row_idx >> column_idx;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good () && row_idx >= 0 && column_idx >= 0)
				break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of indexes, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;
}

vector<double> CParser::parseElements (const int rows, const int columns)
{
	 vector<double> elements;
	 double element;
	 for (int i = 0; i < (rows * columns); )
	 {
		  cin >> element;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good ())
		  {
				elements.push_back (element);
				i++;
				continue;
		  }
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of element, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');
	 cout << endl;

	 return elements;
}

vector<double> CParser::parseFile (int& rows, int& columns)
{
	 cout << "Enter the path of file with matrix:" << endl;
	 string file_name;
	 while (true)
	 {
		  cin >> file_name;
		  if (cin.eof ())
				throw CEOFException ();
		  if (cin.good ())
				break;
		  cin.clear ();
		  cin.ignore (numeric_limits<streamsize>::max(), '\n');
		  cerr << "Invalid input of file name, try again." << endl;
	 }
	 cin.ignore (numeric_limits<streamsize>::max(), '\n');

	 ifstream ifs (file_name);
	 if (ifs.fail () || !(ifs.is_open ()))
	 {
		  ifs.close ();
		  throw CFileOpeningException ();
	 }

	 char symbol;
	 if (!(ifs >> rows >> symbol >> columns) || symbol != ',' || rows == 0 || columns == 0)
	 {
		  ifs.close ();
		  throw CFileFormattingException ();
	 }

	 vector<double> elements;
	 size_t dimensions = rows * columns;
	 for (size_t i = 0; i < dimensions; i++)
	 {
		  double element;
		  if (!(ifs >> element))
		  {
				ifs.close ();
				throw CFileFormattingException ();
		  }
		  elements.push_back (element);
	 }
	 ifs.close ();

	 return elements;
}
