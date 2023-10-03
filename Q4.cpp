#include "Q4.h"
#include <iostream>
#include <vector>
using namespace std;

////-- Question 4 --////
double dot_product( vector<double> x,  vector<double> w)
{
	if (x.size() != w.size())
	{
		cout << "Vectors are incorrect size, dot product will not compute" << endl;
		return 0;
	}
	int len = x.size();
	double result = 0;
	for (int i = 0; i < len; i++)
	{
		result = result + x[i] * w[i];
	}

	return result;

}