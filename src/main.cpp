#include "../include/constants.hpp"
#include "../include/methods.hpp"
#include "../include/utils.hpp"
#include "../include/matrix.hpp"
#include "../include/vector.hpp"
#include <Windows.h>

int main()
{

	Matrix coefficientMat, lowerTMat, upperTMat, diagonalMat;
	Vector termVector;

	for (auto i = 0; i < constants::n; i++) {
		termVector[i] = sin(((double)i + 1.0) * (constants::f + 1));
		diagonalMat[i][i] = coefficientMat[i][i] = constants::a1;
		for (auto j = 0; j < constants::n; j++) {
			switch (i - j) { // i represents row number, j represents column number
			case 1:
				lowerTMat[i][j] = coefficientMat[i][j] = constants::a2;
				break;
			case -1:
				upperTMat[i][j] = coefficientMat[i][j] = constants::a2;
				break;
			case 2:
				lowerTMat[i][j] = coefficientMat[i][j] = constants::a3;
				break;
			case -2:
				upperTMat[i][j] = coefficientMat[i][j] = constants::a3;
				break;
			default:
				break;
			}
		}
	}

	std::cout << "Computing linear equations with Jacobi's method" << std::endl;
	auto start = std::chrono::system_clock::now();

	computeJacobiMethod(coefficientMat, lowerTMat, upperTMat, diagonalMat, termVector);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;
	Sleep(1000);
	std::cout << std::endl << "Computing linear equations with Gauss-Seidel's method" << std::endl;
	start = std::chrono::system_clock::now();

	computeGaussSeidelMethod(coefficientMat, lowerTMat, upperTMat, diagonalMat, termVector);

	end = std::chrono::system_clock::now();
	time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;
	Sleep(1000);
	std::cout << std::endl << "Computing linear equations with LU Factorization method" << std::endl;
	start = std::chrono::system_clock::now();

	computeLUFactorizationMethod(coefficientMat, termVector);

	end = std::chrono::system_clock::now();
	time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;
	return 0;
}