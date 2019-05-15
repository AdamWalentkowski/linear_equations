#pragma once

#include "../include/utils.hpp"
#include "../include/matrix.hpp"

void computeJacobiMethod(Matrix aMatrix,
	Matrix lMatrix, Matrix uMatrix,
	Matrix dMatrix, Vector bVector);

Vector applyForwardSubstitution(Matrix lMatrix,
	Vector bVector);
	
void computeGaussSeidelMethod(Matrix aMatrix, 
	Matrix lMatrix, Matrix uMatrix, 
	Matrix dMatrix, Vector bVector);
