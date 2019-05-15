#pragma once

#include "../include/constants.hpp"
#include <math.h>
#include <algorithm>

class Vector {
	double *vector;

public:

	Vector(double fill = 0.0);
	Vector(const Vector &v);

	double computeEuclideanNorm();

	double &operator [] (const size_t &index)       { return vector[index]; }
	double &operator [] (const size_t &index) const { return vector[index]; }

	/* In this class module I purposefully do not use above operators,
		as they tend to drop the performance for methods with iteration loops */

	Vector operator + (const Vector &rhsVector) {
		Vector sumVector;
		for (auto i = 0; i < constants::n; i++) {
			sumVector.vector[i] = vector[i] + rhsVector.vector[i];
		}
		return sumVector;
	}

	Vector &operator <= (const Vector &rhsVector) {
		if (this == &rhsVector) {
			return *this;
		}
		for (auto i = 0; i < constants::n; i++) {
			vector[i] = rhsVector.vector[i];
		}
		return *this;
	}

	Vector operator ~ () {
		Vector negativeVector;
		for (auto i = 0; i < constants::n; i++) {
			if (vector[i] != 0.0) {
				negativeVector.vector[i] = vector[i] * -1.0;
			}
		}
		return negativeVector;
	}

	~Vector();
};