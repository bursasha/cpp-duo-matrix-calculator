#ifndef MATRIXCALCULATOR_CEXCEPTION_H
#define MATRIXCALCULATOR_CEXCEPTION_H

#include <iostream>

/**
 * @brief
 * An abstract class responsible for possible exceptions that occur during the operation of the calculator.
 * */
class CException
{
public:
	 /**
	  * @brief
	  * A virtual function responsible for exception output.
	  * */
	 virtual void exception () = 0;

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * with 2 matrices that do not fit each other due to different dimensions.
 * */
class CMatricesDimensionsException : public CException
{
public:
	void exception ();
	
};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * with a matrix that is not square.
 * */
class CSquareMatrixException : public CException
{
public:
	 void exception ();

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * with a matrix that is irreversible, its determinant is 0.
 * */
class CIrreversibleException : public CException
{
public:
	 void exception ();

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * with indexes of elements that are not in considered matrix.
 * */
class CIndexesException : public CException
{
public:
	 void exception ();

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * with the opening of a file that cannot be opened.
 * */
class CFileOpeningException: public CException
{
public:
	 void exception ();

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * of parsing a file with matrix, the file is incorrectly formatted.
 * */
class CFileFormattingException: public CException
{
public:
	 void exception ();

};

/**
 * @brief
 * A class responsible for the output of an exception associated with performing an operation
 * of ending the input.
 * */
class CEOFException: public CException
{
public:
	 void exception ();

};

#endif // MATRIXCALCULATOR_CEXCEPTION_H
