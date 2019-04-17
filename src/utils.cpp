#include "utils.hpp"

void test_matrix(double *matrix[constants::n], std::string name = "<Unnamed>") {
	std::cout << std::endl << name + ": " << std::endl;
    for (auto i = 0; i < constants::n; i++) {
		for (auto j = 0; j < constants::n; j++) {
			std::cout << matrix[j][i] << " ";
		}
        std::cout << std::endl;
	}
        std::cout << std::endl;
}

void test_vector(double vector[], std::string name = "<Unnamed>") {
    std::cout << std::endl << name + ": " << std::endl;
    for (auto i = 0; i < constants::n; i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}