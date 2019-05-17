#pragma once

#include "../include/utils.hpp"
#include "../include/matrix.hpp"

Vector computeJacobiMethod(Matrix aMatrix,
	Matrix lMatrix, Matrix uMatrix,
	Matrix dMatrix, Vector bVector);

Vector applyForwardSubstitution(Matrix lMatrix,
	Vector bVector);

Vector applyBackwardSubstitution(Matrix uMatrix,
	Vector bVector);
	
Vector computeGaussSeidelMethod(Matrix aMatrix, 
	Matrix lMatrix, Matrix uMatrix, 
	Matrix dMatrix, Vector bVector);

void computeLUFactorizationMethod(Matrix aMatrix, Vector bVector);