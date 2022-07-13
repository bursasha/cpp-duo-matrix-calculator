#ifndef MATRIXCALCULATOR_CCALCULATOR_H
#define MATRIXCALCULATOR_CCALCULATOR_H

#include "CMatrix.h"

/**
 * @brief
 * The class responsible for performing all input, write, and matrix operations.
 * */
class CCalculator
{
public:
	 CCalculator ();
	 ~CCalculator ();

	 /**
	  * @brief
	  * A function that launches the calculator, its menu with all operations.
	  * */
	 void run ();

private:
	 /**
	  * @brief
	  * Dimensions of 2 matrices entered into the calculator.
	  * */
	 int lhs_rows, lhs_columns, rhs_rows, rhs_columns;
	 /**
	  * @brief
	  * 2 matrices entered into the calculator and the result of the operation.
	  * */
	 shared_ptr<CMatrix> lhs_m, rhs_m, result_m;

};

#endif // MATRIXCALCULATOR_CCALCULATOR_H
