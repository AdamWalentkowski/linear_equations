#include "../include/matrix.hpp"

Matrix::Matrix(double fill) {
	matrix = new double *[constants::n];
	for (auto i = 0; i < constants::n; i++) {
		matrix[i] = new double[constants::n]{ 0.0 };
	}

	if (!(fill == 0.0)) {
		for (auto i = 0; i < constants::n; i++) {
			std::fill(matrix[i], matrix[i] + constants::n, fill);
		}
	}
}

Matrix::Matrix(const Matrix &m) {
	matrix = new double *[constants::n];
	for (auto i = 0; i < constants::n; i++) {
		matrix[i] = new double[constants::n];
		for (auto j = 0; j < constants::n; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (auto i = 0; i < constants::n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}