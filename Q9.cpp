#include "Q4.h"
#include "Q5.h"
#include "Q6.h"
#include "Q7.h"
#include "Q8.h"
#include "Q9.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

////-- Question 9 --////
map<string, vector<double>> guess_engine(map<string, vector<double>> test_data, vector<double> w_trained)
{
    // Iterate through the map using a range-based for loop
    for (const auto& pair : test_data) {
        const std::string& aircraftName = pair.first;
        const std::vector<double>& aircraftData = pair.second;
        std::cout << "Aircraft: " << aircraftName << std::endl;

        // Iterate through the vector of double values for each aircraft
        vector <double> xi(3); // [0]: approach speed. [1]: wingspan. [2] MTOW
        int i = 0;
        for (double value : aircraftData) {
            //std::cout << value << " ";
            xi[i] = value;
            i = i +1;
        }

        double y_predict = sigmoid(dot_product(xi, w_trained));
        cout << "y-Predict = " << y_predict << endl;

        // Determine engine type of aircraft
        if (y_predict > 0.5)
        {
            cout << "Engine type.... JET ENGINE" << endl;
        }
        else
        {
            cout << "Engine type.... TURBOPROP" << endl;
        }
        std::cout << std::endl;
    }
    
    return test_data;
}