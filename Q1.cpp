#include "Q1.h"
#include <iostream>
using namespace std;

////-- Question 1 --////
void Question1(double L_p, double L_delta)
{
	//assigning variables
	//double L_p = 0.3; // roll damping coefficient
	//float L_delta = -0.1; // aileron effectiveness
	int p0 = 1; // initial roll rate (rad/sec)
	int delta = 1; /// aileron deflection (rad)
	int t_ail = 2; // time of aileron deflection (sec)
	int n = 500; // number of iterations
	double dt = 0.01; // time interval (sec)
	int t_total = 5; // time for prediction to last

	double ti = 0;
	double pi = 0;
	double p_doti = 0;
	double pi_new = 0;
	// initial conditions (t = 0)
	pi = p0; // t = t
	ti = 0;
	p_doti = L_p * pi + L_delta * delta;
	std::cout << "Time = " << ti << " sec, p =" << pi << " rad/sec, p_dot =" << p_doti << " rad/sec/sec" << std::endl;

	// propogate equation for 0 < t < 5 sec
	for (int i = 0; i < n; i++)
	{
		if (i > 199)
		{
			delta = 0; // delta = 0 for t > 2 sec
		}
		ti = dt * (i + 1); // t = t
		pi = pi + (p_doti * dt); // t = t
		p_doti = L_p * pi + L_delta * delta; // t = t
		std::cout << "Time = " << ti << " sec, p =" << pi << " rad/sec, p_dot =" << p_doti << " rad/sec/sec" << std::endl;
		//cout << "delta = " << delta << endl;
	}
	return;
}
