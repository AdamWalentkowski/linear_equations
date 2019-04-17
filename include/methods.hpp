#pragma once

#include "constants.hpp"

double **addMatrices(const double *aMatrix[constants::n], 
        const double *bMatrix[constants::n]);
double computeEuclideanNorm(double vector[]);
double *computeJacobiMethod(double *matrix[constants::n], double vector[]);
