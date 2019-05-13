#include "../include/constants.hpp"
#include "../include/methods.hpp"
#include "../include/utils.hpp"
#include "../include/matrix.hpp"
#include "../include/vector.hpp"

int main()
{
	//double termVec[constants::n];
	//double *coefficientMat[constants::n], *lowerTMat[constants::n],
	//	 *upperTMat[constants::n], *diagonalMat[constants::n];

	Matrix coefficientMat, lowerTMat, upperTMat, diagonalMat;
	Vector termVec;

	for (auto i = 0; i < constants::n; i++) {
		//coefficientMat[i] = new double[constants::n]{ 0.0 };
		//lowerTMat[i] = new double[constants::n]{ 0.0 };
		//upperTMat[i] = new double[constants::n]{ 0.0 };
		//diagonalMat[i] = new double[constants::n]{ 0.0 };

		termVec[i] = sin(((double)i + 1.0) * (constants::f + 1));
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

	//auto start = std::chrono::system_clock::now();

	//auto resultVector = computeJacobiMethod(coefficientMat, lowerTMat, upperTMat, diagonalMat, termVec);

	//auto end = std::chrono::system_clock::now();
	//std::chrono::duration<double> time_result = end - start;
	//std::cout << "Time: " << time_result.count() << " seconds." << std::endl;

	//test_matrix(coefficientMat, "Coefficients");
	//test_matrix(upperTMat, "Upper");
	//test_matrix(lowerTMat, "Lower");
	//test_matrix(diagonalMat, "Diag");
	//test_vector(termVec, "Terms");
	
	//Matrix mat1(1.0);
	//Vector vec1(2.0);
	//Vector matVec1 = mat1 * vec1;
	//test_vector(matVec1);
	//Matrix mat2(1.0);
	//Matrix mat3 = mat1 * mat2;
	//test_matrix(mat1);
	//test_matrix(mat3, "1 * 1");
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
	return 0;
}