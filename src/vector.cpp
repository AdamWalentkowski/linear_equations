#include "../include/vector.hpp"

Vector::Vector(double fill) {
	vector = new double[constants::n] { 0.0 };
	if (!(fill == 0.0)) {
			std::fill(vector, vector + constants::n, fill);
	}
}

Vector::Vector(const Vector &v) {
	vector = new double[constants::n];
	for (auto i = 0; i < constants::n; i++) {
		vector[i] = v.vector[i];
	}
}

double Vector::computeEuclideanNorm()
{
	double norm = 0.0;
	for (auto i = 0; i < constants::n; i++) {
		norm += vector[i] * vector[i];
	}
	return sqrt(norm);
}

Vector::~Vector() {
	delete[] vector;
}