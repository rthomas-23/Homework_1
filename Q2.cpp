#include "Q2.h"
#include <iostream>
using namespace std;

////-- Question 2 --////
void Question2(double L_p, double L_delta, double K)
{
	//assigning variables
	//double L_p = 0.3; // roll damping coefficient
	//float L_delta = -0.1; // aileron effectiveness
	int p0 = 1; // initial roll rate (rad/sec)
	int n = 500; // number of iterations
	double dt = 0.01; // time interval (sec)
	int t_total = 5; // time for prediction to last

	//double ti = 0;
	//double pi = 0;
	//double p_doti = 0;
	//double pi_new = 0;
	//// initial conditions (t = 0)
	//pi = p0; // t = t
	//ti = 0;
	//p_doti = L_p * pi + L_delta * delta;
	//std::cout << "Time = " << ti << " sec, p =" << pi << " rad/sec, p_dot =" << p_doti << " rad/sec/sec" << std::endl;

	double ti = 0;
	double pi = p0;
	// propogate equation for 0 < t < 5 sec
	for (int i = 0; i < n; i++)
	{	

		cout << "Time = " << ti << " sec, p = " << pi << "rad/sec"<< std::endl;
		double p_old = pi;
		ti = dt * (i + 1); // t = t
		pi = p_old + (((L_p*p_old) - (L_delta*p_old*K)) * dt); // t = t
		//cout << "delta = " << delta << endl;
	}
	return;
}
