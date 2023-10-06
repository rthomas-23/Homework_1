// AERSP424_Homework_1.cpp : Defines the entry point for the application.
#include "AERSP424_Homework_1.h"
#include "Q1.h"
#include "Q2.h"
#include "Q3.h"
#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"
#include "Q8.h"
#include "Q9.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	////--- Question 1 ---////
	double L_p = 0.3; //roll damping coefficient
	double L_delta = -0.1; // aileron effectiveness
	cout << "Question 1.... " << endl;
	Question1(L_p, L_delta);

	////--- Question 2 ---////
	double K = 2; // feedback control gain
	cout << "\nQuestion 2.... " << endl;
	Question2(L_p, L_delta, K);

	////--- Question 3 ---////
	double alpha = 0.2; // adaptive rate
	double k0 = 0.5; // initial control gain
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
	cout << "\n\nQuestion 8.... " << endl;
	// this is the reference data of 8 aircraft to tune the neural network
	double ref_data[8][4] =
	{
		{124, 31.89,20.945,1},
		{74,51.08,9.17,0},
		{103,34.67,8.3,1},
		{77,52,9.4,0},
		{104,35.63,13,1},
		{92,56,12.5,0},
		{130,31.29,17.637,1},
		{73,52,9.6,0}
	};
	int n = 99; // number of iterations to train the network
	vector<double> w_trained = train_network(w, alpha_update, ref_data, n);
	cout << "\nw_trained = ";
	for (double i : w_trained)
		std::cout << i << ' ';

	////--- Question 9 ---////
	cout << "\n\nQuestion 9.... " << endl;
	// this is data for 4 new aircraft. for their engine type to be identified by the neural network
	map<string, vector<double>> new_data =
	{
		{"SF50 Vision", {87,38.67,6}},
		{"208 Caravan", {79,52.08,8}},
		{"Aero L-29 Delfin", {92,33.75,7.804}},
		{"AT-802U", {91,59.25,16}}
	};
	map<string, vector<double>> a = guess_engine(new_data, w_trained);

	return 0;
}
