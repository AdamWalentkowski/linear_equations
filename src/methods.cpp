#include "../include/methods.hpp"

void computeJacobiMethod(Matrix aMatrix, Matrix lMatrix, 
	Matrix uMatrix, Matrix dMatrix, Vector bVector)
{
	Vector xVector(1.0);
	Matrix dInvMatrix;	// D^-1
	for (auto i = 0; i < constants::n; i++) {
		dInvMatrix[i][i] = 1.0 / dMatrix[i][i];
	}

	double norm = 1.0;
	int iteration = 0;
	auto constantMatVec = dInvMatrix * bVector;
	auto coefficientMatVec = ~(dInvMatrix * (lMatrix + uMatrix));
								//-D^-1 * (L + U)
	while (norm > constants::eps) {
		xVector <= (coefficientMatVec * xVector) + constantMatVec;
		// x(k+1) = -D^-1 * (L + U) * x(k) + (D^-1 * b)
		norm = (aMatrix * xVector + (~bVector)).computeEuclideanNorm();
				//res = A * x - b
		++iteration;
		std::cout << "Iteration no.: " << iteration << " norm: " 
			<< norm << std::endl;
	}
}

Vector applyForwardSubstitution(Matrix lMatrix, Vector bVector) {
	double lhSum;
	Vector resultVector;
	for (auto i = 0; i < constants::n; i++) {
		lhSum = 0;
		for (auto j = 0; j < i; j++) {
			lhSum += lMatrix[i][j] * resultVector[j];
		}
		resultVector[i] = (bVector[i] - lhSum) / lMatrix[i][i];
	}
	
	return resultVector;
}

void computeGaussSeidelMethod(Matrix aMatrix, Matrix lMatrix,
	Matrix uMatrix, Matrix dMatrix, Vector bVector)
{
	Vector xVector(1.0);
	double norm = 1.0;
	int iteration = 0;
	auto ldMatrix = lMatrix + dMatrix;
	auto constantMatVec = applyForwardSubstitution(ldMatrix, bVector);
													// (L + D)^-1 * b
	while (norm > constants::eps) {
		xVector <= (~applyForwardSubstitution(ldMatrix, uMatrix * xVector)) + constantMatVec;
		// x(k+1) = -(L + D)^-1 * U * x(k) + (L + D)^-1 * b
		norm = (aMatrix * xVector + (~bVector)).computeEuclideanNorm();
		++iteration;
		std::cout << "Iteration no.: " << iteration << " norm: "
			<< norm << std::endl;
	}
}