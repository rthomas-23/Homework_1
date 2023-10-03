// AERSP424_Homework_1.cpp : Defines the entry point for the application.
//

#include "AERSP424_Homework_1.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"

#include <vector>
using namespace std;

int main()
{
	double L_p = 0.3;
	double L_delta = -0.1;
	cout << "Question 1.... " << endl;
	Question1(L_p, L_delta);

	double K = 2;
	cout << "\nQuestion 2.... " << endl;
	Question2(L_p, L_delta, K);

	double alpha = 0.2;
	double k0 = 0.5;
	cout << "\nQuestion 3.... " << endl;
	Question3(L_p, L_delta, k0, alpha);


	cout << "\nQuestion 4.... " << endl;
	vector<double> w{ 124, 31.89, 20.945};
	vector<double> x{ 0.0001, 0.0001, 0.0001};
	double dot_test = dot_product(w, x);
	cout << "Example x dot w Equals: " << dot_test << endl;

	return 0;
}
