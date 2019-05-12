#include "../include/utils.hpp"

void test_matrix(double *matrix[constants::nTest], std::string name = "<Unnamed>") {
	std::cout << std::endl << name + ": " << std::endl;
	for (auto i = 0; i < constants::nTest; i++) {
		for (auto j = 0; j < constants::nTest; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_vector(double vector[], std::string name = "<Unnamed>") {
	std::cout << std::endl << name + ": " << std::endl;
	for (auto i = 0; i < constants::nTest; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}