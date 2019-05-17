#include "../include/methods.hpp"

Vector computeJacobiMethod(Matrix aMatrix, Matrix lMatrix, 
	Matrix uMatrix, Matrix dMatrix, Vector bVector)
{
	Vector xVector(1.0);
	Vector normVector;
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
		normVector[iteration] = norm = (aMatrix * xVector + (~bVector)).computeEuclideanNorm();
				//res = A * x - b
		++iteration;
		std::cout << "Iteration no.: " << iteration << " norm: " 
			<< norm << std::endl;
	}
	return normVector;
}

Vector applyForwardSubstitution(Matrix lMatrix, Vector bVector) {
	double lhSum;
	Vector resultVector;
	for (auto i = 0; i < constants::n; i++) {
		lhSum = 0.0;
		for (auto j = 0; j < i; j++) {
			lhSum += lMatrix[i][j] * resultVector[j];
		}
		resultVector[i] = (bVector[i] - lhSum) / lMatrix[i][i];
	}
	return resultVector;
}

Vector applyBackwardSubstitution(Matrix uMatrix, Vector bVector) {
	double lhSum;
	Vector resultVector;
	for (auto i = constants::n - 1; i >= 0; i--) {
		lhSum = 0.0;
		for (auto j = i; j < constants::n; j++) {
			lhSum += uMatrix[i][j] * resultVector[j];
		}
		resultVector[i] = (bVector[i] - lhSum) / uMatrix[i][i];
	}
	return resultVector;
}

Vector computeGaussSeidelMethod(Matrix aMatrix, Matrix lMatrix,
	Matrix uMatrix, Matrix dMatrix, Vector bVector)
{
	Vector xVector(1.0);
	Vector normVector;
	double norm = 1.0;
	int iteration = 0;
	auto ldMatrix = lMatrix + dMatrix;
	auto constantMatVec = applyForwardSubstitution(ldMatrix, bVector);
													// (L + D)^-1 * b
	while (norm > constants::eps) {
		xVector <= (~applyForwardSubstitution(ldMatrix, uMatrix * xVector)) + constantMatVec;
		// x(k+1) = -(L + D)^-1 * U * x(k) + (L + D)^-1 * b
		normVector[iteration] = norm = (aMatrix * xVector + (~bVector)).computeEuclideanNorm();
		++iteration;
		std::cout << "Iteration no.: " << iteration << " norm: "
			<< norm << std::endl;
	}
	return normVector;
}

void computeLUFactorizationMethod(Matrix aMatrix, Vector bVector) {
	Matrix lMatrix, uMatrix;

	for (auto i = 0; i < constants::n; i++) {
		// Upper Triangular 
		for (auto j = i; j < constants::n; j++) {
			// Summation of L(i, k) * U(k, j) 
			double sum = 0.0;
			for (auto k = 0; k < i; k++) {
				sum += (lMatrix[i][k] * uMatrix[k][j]);
			}
			// Evaluating U(i, j) 
			uMatrix[i][j] = aMatrix[i][j] - sum;
		}
		// Lower Triangular 
		for (auto j = i; j < constants::n; j++) {
			if (i == j)
				lMatrix[i][i] = 1; // Diagonal as 1 
			else {
				// Summation of L(j, k) * U(k, i) 
				double sum = 0.0;
				for (auto k = 0; k < i; k++)
					sum += (lMatrix[j][k] * uMatrix[k][i]);
				// Evaluating L(j, i) 
				lMatrix[j][i] = (aMatrix[j][i] - sum) / uMatrix[i][i];
			}
		}
	}
	auto yTempVector = applyForwardSubstitution(lMatrix, bVector);
	auto norm = (aMatrix * applyBackwardSubstitution(uMatrix, yTempVector) + ~bVector).computeEuclideanNorm();
	std::cout << "Equations computed. Norm: " << norm << std::endl;
}