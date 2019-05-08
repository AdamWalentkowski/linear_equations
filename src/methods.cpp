#include "../include/methods.hpp"
#include "../include/utils.hpp"

double *addVectors(double aVector[], double bVector[])
{
	auto sumVector = new double[constants::n]{0.0};
	for (auto i = 0; i < constants::n; i++) {
		sumVector[i] = aVector[i] + bVector[i];
	}
	return sumVector;
}

double **addMatrices(double *aMatrix[constants::n],
	double *bMatrix[constants::n])
{
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
	double *rhMatrix[constants::n])
{
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

double computeEuclideanNorm(double vector[]) 
{
	double norm = 0.0;
	for (auto i = 0; i < constants::n; i++) {
		norm += vector[i] * vector[i];
	}
	return sqrt(norm);
}

double *multiplyMatVec(double *matrix[constants::n], double vector[]) 
{	
	double *matVec = new double[constants::n]{ 0.0 };
	for (auto i = 0; i < constants::n; i++) {
		for (auto j = 0; j < constants::n; j++) {
			matVec[i] += matrix[j][i] * vector[j];
		}
	}
	return matVec;
}

double *computeJacobiMethod(double *aMatrix[constants::n], 
	double *lMatrix[constants::n], double *uMatrix[constants::n], 
	double *dMatrix[constants::n], double bVector[])
{
	auto xVector = new double[constants::n] { 1.0 };
	auto residuumVector = new double[constants::n] { 1.0 };	//res

	auto dInv = new double *[constants::n];	// D^-1
	auto dInvNeg = new double *[constants::n];	// -D^-1
	auto bNeg = new double[constants::n];
	for (auto i = 0; i < constants::n; i++) {
		dInv[i] = new double[constants::n] { 0.0 };
		dInvNeg[i] = new double[constants::n] { 0.0 };
		dInv[i][i] = 1.0 / dMatrix[i][i];
		dInvNeg[i][i] = dInv[i][i] * -1.0;
		bNeg[i] = bVector[i] * -1.0;
	}

	auto dInv_b = multiplyMatVec(dInv, bVector);	// D^-1 * b
	auto l_U = addMatrices(lMatrix, uMatrix);	// L + U
	double *l_U_x, *dInvNeg_L_U_x, *a_x;
	double norm = 1.0;
	int iteration = 0;

	while (norm > constants::eps) {
		l_U_x = multiplyMatVec(l_U, xVector);	// (L + U) * x
		dInvNeg_L_U_x = multiplyMatVec(dInvNeg, l_U_x);	// -D^-1 * (L + U) * x
		xVector = addVectors(dInvNeg_L_U_x, dInv_b);
		// -D^-1 * (L + U) * x + D^-1 * b
		a_x = multiplyMatVec(aMatrix, xVector); // A * x
		residuumVector = addVectors(a_x, bNeg); // res = A * x - b
		norm = computeEuclideanNorm(residuumVector);

		++iteration;
		std::cout << "Iteration no.: " << iteration << " norm: " 
			<< norm << std::endl;
	}
	return xVector;
}
