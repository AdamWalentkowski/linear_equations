#include "../include/utils.hpp"
#include "../include/matrix.hpp"
#include "../include/vector.hpp"

void test_matrix(const Matrix &matrix, std::string name) {
	std::cout << std::endl << name + ": " << std::endl;
	for (auto i = 0; i < constants::nTest; i++) {
		for (auto j = 0; j < constants::nTest; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void test_vector(const Vector &vector, std::string name) {
	std::cout << std::endl << name + ": " << std::endl;
	for (auto i = 0; i < constants::nTest; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void write_to_csv(const Vector &vector, const Vector &vector2, std::string name) {
	std::cout << std::endl << name + ": " << std::endl;
	for (auto i = 0; vector[i] != 0 || vector2[i] != 0; i++) {
		std::cout << vector[i] << "," << vector2[i] << std::endl;
	}
}