#include "methods.hpp"
#include "utils.hpp"

double *addVectors(double aVector[], double bVector[]) {
	auto sumVector = new double[constants::n]{0.0};
	for (auto i = 0; i < constants::n; i++) {
		sumVector[i] = aVector[i] + bVector[i];
	}
	return sumVector;
}

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
	for (auto i = 0; i < constants::n; i++) {
		norm += vector[i] * vector[i];
	}
	return sqrt(norm);
}

double *multiplyMatVec(double *matrix[constants::n], double vector[]) {
	double *matVec = new double[constants::n]{ 0.0 };
	for (auto i = 0; i < constants::n; i++) {
		for (auto j = 0; j < constants::n; j++) {
			matVec[i] += matrix[j][i] * vector[j];
		}
	}
	return matVec;
}

double *computeJacobiMethod(double *matrix[constants::n], 
	double *lMatrix[constants::n], double *uMatrix[constants::n], 
	double *dMatrix[constants::n], double vector[]) {
	auto xVector = new double *[2];
	xVector[0] = new double[constants::n] { 1.0 };
	xVector[1] = new double[constants::n];
	auto residuumVector = new double[constants::n] { 1.0 };
	auto invertedDMatrix = new double *[constants::n];
	auto negativeInvertedDMatrix = new double *[constants::n];
	for (auto i = 0; i < constants::n; i++) {
		invertedDMatrix[i] = new double[constants::n] { 0.0 };
		negativeInvertedDMatrix[i] = new double[constants::n] { 0.0 };
		invertedDMatrix[i][i] = 1.0 / dMatrix[i][i];
		negativeInvertedDMatrix[i][i] = invertedDMatrix[i][i] * -1.0;
	}
	auto invDBMatVec = multiplyMatVec(invertedDMatrix, vector);
	auto LUSumMat = addMatrices(lMatrix, uMatrix);
	double *LUSumXMatVec;
	double *negativeInvDLUSumXMatVec;
	double *resultMatVec;
	double norm = 1.0;
	int iteration = 0;
	while (norm > constants::eps) {
		LUSumXMatVec = multiplyMatVec(LUSumMat, xVector[0]);
		negativeInvDLUSumXMatVec = multiplyMatVec(
			negativeInvertedDMatrix, LUSumXMatVec);
	}

	return xVector[1];
}