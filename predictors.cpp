/*
 * File Name: predictors.cpp
 * Description: Implements the functionality of 1-bit and 2-bit branch predictors.
 * Key Functionality: Includes methods to calculate the prediction accuracy of 1-bit and 2-bit branch predictors based on
 *                    a vector of boolean representing branch outcomes.
 * Author: Wa'el Alkalbani
 * Email: wael@pdx.edu
 */


#include "predictors.h"

// 1-bit branch predictor implementation
double OneBitPredictor::calculateAccuracy(const vector<bool>& branchOutcomes) {
int correctPredictions = 0;
    int counter = 0; // Initial state is '00'

    for (bool outcome : branchOutcomes) {
        bool prediction = (counter >= 2); // Predict 'taken' if counter is 10 or 11

        if (prediction == outcome) {
            correctPredictions++;
        }

        // Update the counter based on the actual outcome
        if (outcome) {
            if (counter < 3) counter++;
        } else {
            if (counter > 0) counter--;
        }
    }
    return static_cast<double>(correctPredictions) / branchOutcomes.size() * 100;
}

// 2-bit saturating counter branch predictor implementation
double TwoBitPredictor::calculateAccuracy(const vector<bool>& branchOutcomes) {
    int correctPredictions = 0;
    bool lastOutcome = false; // Initial state is 'not taken'

    for (bool outcome : branchOutcomes) {
        if (lastOutcome == outcome) {
            correctPredictions++;
        }
        lastOutcome = outcome;
    }
    return static_cast<double>(correctPredictions) / branchOutcomes.size() * 100;
}

