#include "Q6.h"
#include <iostream>
using namespace std;

////-- Question 6 --////
double gradient_cost(double y, double y_pred)
{
	double result = 2 * (y_pred - y);
	return result;
}
