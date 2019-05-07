#pragma once

#include "constants.hpp"

double *addVectors(double aVector[], double bVector[]);
double **addMatrices(double *aMatrix[constants::n],
	double *bMatrix[constants::n]);
double **multiplyMatrices(double *lhMatrix[constants::n],
	double *rhMatrix[constants::n]);
double computeEuclideanNorm(double vector[]);
double *multiplyMatVec(double* matrix[constants::n], double vector[]);
double *computeJacobiMethod(double *aMatrix[constants::n], 
	double *lMatrix[constants::n], double *uMatrix[constants::n], 
	double *dMatrix[constants::n], double bVector[]);
