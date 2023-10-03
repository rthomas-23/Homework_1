// AERSP424_Homework_1.cpp : Defines the entry point for the application.
//

#include "AERSP424_Homework_1.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"

#include <vector>
using namespace std;

int main()
{
	////--- Question 1 ---////
	double L_p = 0.3;
	double L_delta = -0.1;
	cout << "Question 1.... " << endl;
	Question1(L_p, L_delta);

	////--- Question 2 ---////
	double K = 2;
	cout << "\nQuestion 2.... " << endl;
	Question2(L_p, L_delta, K);
#
	////--- Question 3 ---////
	double alpha = 0.2;
	double k0 = 0.5;
	cout << "\nQuestion 3.... " << endl;
	Question3(L_p, L_delta, k0, alpha);

	////--- Question 4 ---////
	cout << "\nQuestion 4.... " << endl;
	vector<double> x{ 124, 31.89, 20.945};
	vector<double> w{ 0.0001, 0.0001, 0.0001};
	double dot_test = dot_product(w, x);
	cout << "Example: x = ";
	for (double i : x)
		std::cout << i << ' ';
	cout << ", w = ";
	for (double i : w)
		std::cout << i << ' ';
	cout << "\nx.w = " << dot_test << endl;

	////--- Question 5 ---////
	cout << "\nQuestion 5.... " << endl;
	double z = 0.0176835;
	double sigma = sigmoid(z);
	double deriv = gradient_sigmoid(sigma);
	cout << "Example: z = " << z << ", sigmoid = " << sigma << "\nderiv = " << deriv << endl;

	////--- Question 6 ---////
	cout << "\nQuestion 6.... " << endl;
	double y = 1;
	double y_pred = 0.504421;
	double dC = gradient_cost(y, y_pred);
	cout << "Example: y = " << y << ", y_prediction = " << y_pred << "\ndC = " << dC << endl;

	////--- Question 7 ---////
	cout << "\nQuestion 7.... " << endl;
	vector<double> dw = gradient_weights(x, w, y);
	cout << "Example: y = " << y << ", x = ";
	for (double i : x)
		std::cout << i << ' ';
	cout << ", w = ";
	for (double i : w)
		std::cout << i << ' ';
	cout << "\ndw = ";
	for (double i : dw)
		std::cout << i << ' ';

	double alpha_update = 0.001;
	vector <double> w_update = update_weights(w, dw, alpha_update);
	cout << "\nUpdated w = ";
	for (double i : w_update)
		std::cout << i << ' ';

	////--- Question 8 ---////

	return 0;
}
