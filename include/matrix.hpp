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

	Matrix operator + (const Matrix &otherMatrix) {
		Matrix sumMatrix;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				sumMatrix[i][j] = matrix[i][j] + otherMatrix[i][j];
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
					cellValue += matrix[k][j] * rhsMatrix[i][k];
				}
				productMatrix[i][j] = cellValue;
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

	Matrix operator ~ () {
		Matrix negativeMatrix;
		for (auto i = 0; i < constants::n; i++) {
			for (auto j = 0; j < constants::n; j++) {
				negativeMatrix[i][j] = matrix[i][j] * -1.0;
			}
		}
		return negativeMatrix;
	}

	~Matrix();
};

