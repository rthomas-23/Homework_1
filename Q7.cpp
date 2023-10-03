#include "Q7.h"
#include "Q6.h"
#include "Q5.h"
#include "Q4.h"
#include <iostream>
#include <vector>
using namespace std;

////-- Question 7 --////
vector <double> gradient_weights(vector<double> x, vector<double> w, double y)
{
	double x_dot_w = dot_product(x, w);
	double sigma_xw = sigmoid(x_dot_w);

	vector <double> dw(w.size());
	for (int i = 0; i < w.size(); i++)
	{
		dw[i] = x[i] * (2 * (sigma_xw - y)) * (sigma_xw * (1 - sigma_xw));
	}
	return dw;
}

vector <double> update_weights(vector<double> w, vector <double> dw, double alpha)
{
	for (int i = 0; i < w.size(); i++)
	{
		w[i] = w[i] - alpha*dw[i];
	}
	return w;
}
