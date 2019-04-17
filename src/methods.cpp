#include "methods.hpp"
#include "utils.hpp"

double **addMatrices(const double *aMatrix[constants::n], 
const double *bMatrix[constants::n]) {
    double **sumMatrix = new double*[constants::n];

    for (int i = 0; i < constants::n; i++) {
        sumMatrix[i] = new double[constants::n];
        for (int j = 0; j < constants::n; j++) {
            sumMatrix[j][i] = aMatrix[j][i] + bMatrix[j][i];
        }
    }
    return sumMatrix;
}

double computeEuclideanNorm(double vector[]) {
    
}

double *computeJacobiMethod(double *matrix[constants::n], double vector[]) {
    double xVector[constants::n];


    return xVector;
}