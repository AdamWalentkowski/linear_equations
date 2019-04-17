#include "utils.hpp"
#include "methods.hpp"
#include "constants.hpp"



int main() {

	double termVec[constants::n];
	double *coefficientMat[constants::n], *lowerTMat[constants::n], 
	*upperTMat[constants::n], *diagonalMat[constants::n];

	for (auto i = 0; i < constants::n; i++) {
		coefficientMat[i] = new double[constants::n]{0.0};
		lowerTMat[i] = new double[constants::n]{0.0};
		upperTMat[i] = new double[constants::n]{0.0};
		diagonalMat[i] = new double[constants::n]{0.0};
	}

	auto start = std::chrono::system_clock::now();

	for (auto i = 0; i < constants::n; i++) {
		for (auto j = 0; j < constants::n; j++) {
			switch (i - j) //i represents row number, j represents column number
			{
			case 0:
				coefficientMat[j][i] = constants::a1;
				diagonalMat[j][i] = coefficientMat[j][i];
				break;
			case 1:
				coefficientMat[j][i] = constants::a2;
				lowerTMat[j][i] = coefficientMat[j][i];
				break;
			case -1:
				coefficientMat[j][i] = constants::a2;
				upperTMat[j][i] = coefficientMat[j][i];
				break;
			case 2:
				coefficientMat[j][i] = constants::a3;
				lowerTMat[j][i] = coefficientMat[j][i];
				break;
			case -2:
				coefficientMat[j][i] = constants::a3;
				upperTMat[j][i] = coefficientMat[j][i];
				break;
			default:
				break;
			}
		}
		termVec[i] = sin((i+1) * (constants::f + 1));
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;

	// test_matrix(coefficientMat, "Coefficients");
	// test_matrix(upperTMat, "Upper");	
	// test_matrix(lowerTMat, "Lower");
	// test_matrix(diagonalMat, "Diag");

	system("pause");
	return 0;
}