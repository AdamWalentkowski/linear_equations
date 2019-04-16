#include "utils.h"
#include "methods.h"
#include "constants.h"



int main() {

	double termVec[constants::N];
	double *coefficientMat[constants::N], *lowerTMat[N], 
	*upperTMat[constants::N], *diagonalMat[constants::N];

	for (auto i = 0; i < N; i++) {
		coefficientMat[i] = new double[constants::N]{0.0};
	}

	auto start = std::chrono::system_clock::now();

	for (auto i = 0; i < constants::N; i++) {
		termVec[i] = sin((i+1) * (constants::f + 1));
		for (auto j = 0; j < N; j++) {
			if (j == i) {
				coefficientMat[j][i] = constants::a1;
			}
			else if (abs(i - j) == 1) {
				coefficientMat[j][i] = constants::a2;
			}
			else if (abs(i - j) == 2) {
				coefficientMat[j][i] = constants::a3;
			}
		}
	}

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> time_result = end - start;
	std::cout << "Time: " << time_result.count() << " seconds." << std::endl;

	system("pause");
	return 0;
}