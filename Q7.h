#pragma once
#include <vector>
using namespace std;
vector <double> gradient_weights(vector<double> x, vector<double> w, double y);
vector <double> update_weights(vector<double> w, vector <double> dw, double alpha);