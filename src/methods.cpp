#include "methods.hpp"
#include "utils.hpp"

double **addMatrices(double *aMatrix[constants::n],
	double *bMatrix[constants::n]) {
	auto sumMatrix = new double *[constants::n];

	for (auto i = 0; i < constants::n; i++) {
		sumMatrix[i] = new double[constants::n];
		for (auto j = 0; j < constants::n; j++) {
			sumMatrix[i][j] = aMatrix[i][j] + bMatrix[i][j];
		}
	}
	return sumMatrix;
}

double **multiplyMatrices(double *lhMatrix[constants::n],
	double *rhMatrix[constants::n]) {
	auto productMatrix = new double *[constants::n];
	double cellValue;
	for (auto i = 0; i < constants::n; i++) {
		productMatrix[i] = new double[constants::n];
		for (auto j = 0; j < constants::n; j++) {
			cellValue = 0.0;
			for (auto k = 0; k < constants::n; k++) {
				cellValue += lhMatrix[k][j] * rhMatrix[i][k];
			}
			productMatrix[i][j] = cellValue;
		}
	}
	return productMatrix;
}

double computeEuclideanNorm(double vector[]) {
	double norm = 0.0;
	for (int i = 0; i < constants::n; i++) {
		norm += vector[i] * vector[i];
	}
	return sqrt(norm);
}

double *computeJacobiMethod(double *matrix[constants::n], double vector[]) {
	double *xVector = new double[constants::n];


	return xVector;
}