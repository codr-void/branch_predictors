/*
 * File Name: predictors.h
 * Description: Header file declaring the OneBitPredictor and TwoBitPredictor classes.
 * Key Functionality: Defines the structure and functionality for both 1-bit and 2-bit branch predictors.
 * Author: Wa'el Alkalbani
 * Email: wael@pdx.edu
 */

#ifndef PREDICTORS_H
#define PREDICTORS_H

#include <vector>
using namespace std;

class OneBitPredictor {
public:
    double calculateAccuracy(const vector<bool>& branchOutcomes);
};

class TwoBitPredictor {
public:
    double calculateAccuracy(const vector<bool>& branchOutcomes);
};

#endif

