#include "Q5.h"
#include <iostream>
using namespace std;

////-- Question 5 --////
double sigmoid(double z)
{
	double sigma = 1 / (1 + exp(-z));
	return sigma;
}

double gradient_sigmoid(double sigma) 
{
	double deriv = sigma * (1 - sigma);
	return deriv;
}
