#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"
#include "Q8.h"
#include <iostream>
#include <vector>
using namespace std;

////-- Question 8 --////
vector <double> train_network(vector<double> w, double alpha_update, double ref_data[8][4], int n)
{
	// Printing each row of the ref_data
	
	cout << "Reference Aircraft Data: [0]: approach speed. [1]: wingspan. [2] MTOW [3] Propulsion Type";
	for (int i = 0; i < 8; i++)
	{
		/*cout << "\n";
		for (double i : ref_data[i])
			std::cout << i << ' ';*/
	}
	
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			// Initialise xi and y
			vector <double> xi{ ref_data[i][0], ref_data[i][1], ref_data[i][2] }; // [0]: approach speed. [1]: wingspan. [2] MTOW
			int yi = ref_data[i][3];
			vector <double> dwi = gradient_weights(xi, w, yi);
			vector <double> w_update = update_weights(w, dwi, alpha_update);
			w = w_update;
		}
	}
	return w;
}
