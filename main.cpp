/*
 * File Name: main.cpp
 * Description: Driver program for testing branch predictors on a sequence of branch outcomes.
 * Key Functionality: Reads a sequence of branch outcomes from a trace file and calculates the prediction accuracy
 *                    for both 1-bit and 2-bit branch predictors. Outputs the results to the standard output.
 * Author: Wa'el Alkalbani
 * Email: wael@pdx.edu
 */
 
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "predictors.h"

using namespace std;

// Function to read branch outcomes from a trace file
vector<bool> readBranchOutcomes(const string& filename) {
    vector<bool> branchOutcomes;
    ifstream infile(filename);
    string address, outcome;
    
    while (infile >> address >> outcome) {
        if (outcome == "T") {
            branchOutcomes.push_back(true);
        } else if (outcome == "NT") {
            branchOutcomes.push_back(false);
        }
    }
    
    infile.close();
    return branchOutcomes;
}

int main() {
    // Read branch outcomes from the trace file
    vector<bool> branchOutcomes = readBranchOutcomes("trace.txt");

    // Initialize predictors
    OneBitPredictor oneBit;
    TwoBitPredictor twoBit;

    // Calculate prediction accuracy for both predictors
    double accuracy1Bit = oneBit.calculateAccuracy(branchOutcomes);
    double accuracy2Bit = twoBit.calculateAccuracy(branchOutcomes);

    // Output the results
    cout << "1-bit Predictor Accuracy: " << accuracy1Bit << "%" << endl;
    cout << "2-bit Predictor Accuracy: " << accuracy2Bit << "%" << endl;

    return 0;
}

