#include "utils.hpp"
#include "methods.hpp"
#include "constants.hpp"



int main() {

	double termVec[constants::n];
	double *coefficientMat[constants::n], *lowerTMat[constants::n],
		 *upperTMat[constants::n], *diagonalMat[constants::n];

	for (auto i = 0; i < constants::n; i++) {
		coefficientMat[i] = new double[constants::n]{ 0.0 };
		lowerTMat[i] = new double[constants::n]{ 0.0 };
		upperTMat[i] = new double[constants::n]{ 0.0 };
		diagonalMat[i] = new double[constants::n]{ 0.0 };
	}

	auto start = std::chrono::system_clock::now();

	for (auto i = 0; i < constants::n; i++) {
		coefficientMat[i][i] = constants::a1;
		diagonalMat[i][i] = coefficientMat[i][i];
		for (auto j = 0; j < constants::n; j++) {
			switch (i - j) //i represents row number, j represents column number
			{
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
		termVec[i] = sin(((double)i + 1.0) * (constants::f + 1));
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;

	// test_matrix(coefficientMat, "Coefficients");
	// test_matrix(upperTMat, "Upper");	
	// test_matrix(lowerTMat, "Lower");
	// test_matrix(diagonalMat, "Diag");
	//double *aMatrix[constants::nTest],  *bMatrix[constants::nTest];
	//std::srand((size_t)time(NULL));
	//for (auto i = 0; i < constants::nTest; i++)
	//{
	//	aMatrix[i] = new double[constants::nTest];
	//	bMatrix[i] = new double[constants::nTest];
	//	for (auto j = 0; j < constants::nTest; j++) {
	//		aMatrix[i][j] = (double)(std::rand() % 10);
	//		bMatrix[i][j] = (double)(std::rand() % 10);
	//	}
	//}
	//test_matrix(aMatrix, "A");
	//test_matrix(bMatrix, "B");
	//double **cMatrix = addMatrices(aMatrix, bMatrix);
	//test_matrix(cMatrix, "Test sum");
	//double **dMatrix = multiplyMatrices(aMatrix, bMatrix);
	//test_matrix(dMatrix, "Test product");
	system("pause");
	return 0;
}