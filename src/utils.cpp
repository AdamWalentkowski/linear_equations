#include "utils.h"

void test_matrix(double *matrix[N]) {
    for (auto i = 0; i < N; i++) {
		for (auto j = 0; j < N; j++) {
			std::cout << matrix[j][i] << " ";
		}
        std::cout << std::endl;
	}
        std::cout << std::endl;
}

void test_vecroe(double vec[]) {
    for (auto i = 0; i < N; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}