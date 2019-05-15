#pragma once

#include "../include/vector.hpp"
#include <algorithm>

class Matrix {

	double **matrix;

public:
	Matrix(double fill = 0.0);
	Matrix(const Matrix &m);

	double *&operator [] (const size_t &index)       { return matrix[index]; }
	double *&operator [] (const size_t &index) const { return matrix[index]; }

	/* In this class module I purposefully do not use above operators,
	as they tend to drop the performance in n^2 / n^3 methods */

	Matrix operator + (const Matrix &otherMatrix) {
		Matrix sumMatrix;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				sumMatrix.matrix[i][j] = matrix[i][j] + otherMatrix.matrix[i][j];
			}
		}
		return sumMatrix;
	}

	Matrix operator * (const Matrix &rhsMatrix) {
		Matrix productMatrix;
		double cellValue;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				cellValue = 0.0;
				for (auto k = 0; k < constants::n; k++) {
					cellValue += matrix[k][j] * rhsMatrix.matrix[i][k];
				}
				productMatrix.matrix[i][j] = cellValue;
			}
		}
		return productMatrix;
	}

	Vector operator * (const Vector &rhsVector) {
		Vector matVec;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				matVec[i] += matrix[i][j] * rhsVector[j];
			}
		}
		return matVec;
	}

	Matrix &operator <= (const Matrix &rhsMatrix) {
		if (this == &rhsMatrix) {
			return *this;
		}
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++)
			{
				matrix[i][j] = rhsMatrix.matrix[i][j];
			}
		}
		return *this;
	}

	Matrix operator ~ () {
		Matrix negativeMatrix;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				if (matrix[i][j] != 0.0) {
					negativeMatrix.matrix[i][j] = matrix[i][j] * -1.0;
				}
			}
		}
		return negativeMatrix;
	}

	~Matrix();
};

