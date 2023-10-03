#include "Q3.h"
#include <iostream>
using namespace std;

////-- Question 3 --////
void Question3(double L_p, double L_delta, double k0, double alpha)
{
	//assigning variables
	int p0 = 1; // initial roll rate (rad/sec)
	int n = 500; // number of iterations
	double dt = 0.01; // time interval (sec)
	int t_total = 5; // time for prediction to last

	// initial conditions (t = 0)
	double ti = 0;
	double pi = p0;
	double ki = k0;

	// propogate equation for 0 < t < 5 sec
	for (int i = 0; i < n; i++)
	{
		cout << "Time = " << ti << " sec, p = " << pi << "rad/sec, ki = " << ki << endl;
		double p_old = pi;
		ti = dt * (i + 1); // t = t
		ki = ki + (alpha * p_old * p_old);
		pi = p_old + (L_p * p_old - L_delta * p_old * ki) * dt; // t = t
		//cout << "delta = " << delta << endl;
	}
	return;
}
