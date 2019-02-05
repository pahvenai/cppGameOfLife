/* 
 * File:   dataTypes.h
 * Author: Patrik Ahvenainen
 *
 * Created on December 11, 2018, 11:54 AM
 * Modified on 2019-02-05
 */

#include <vector>
#include <cmath>

#ifndef DATATYPES_H
#define DATATYPES_H

// Data is handled in nested vectors, actual data format is bool for all 
// true elements of the arrays that can be referenced data[0][0]...data[m][n]
typedef std::vector<bool> booleanVector;
typedef std::vector<booleanVector> boolean2dVector;

// Pi is defined here as it is not part of the C++ standard
const double PI = std::atan(1.0)*4;

#endif /* DATATYPES_H */

