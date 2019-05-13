#pragma once

#include "../include/constants.hpp"
#include <math.h>
#include <algorithm>

class Vector {
	double *vector;

public:

	Vector(double fill = 0.0);
	Vector(const Vector &v);

	double computeEuclideanNorm(const Vector &vector);

	double &operator [] (const size_t &index)       { return vector[index]; }
	double &operator [] (const size_t &index) const { return vector[index]; }

	Vector operator + (const Vector &otherVector) {
		Vector sumVector;
		for (auto i = 0; i < constants::n; i++) {
			sumVector[i] = vector[i] + otherVector[i];
		}
		return sumVector;
	}

	Vector operator ~ () {
		Vector negativeVector;
		for (auto i = 0; i < constants::n; i++) {
			negativeVector[i] = vector[i] * -1.0;
		}
		return negativeVector;
	}

	~Vector();
};