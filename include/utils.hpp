#pragma once

#include "../include/matrix.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>

void test_matrix(const Matrix &matrix, std::string name = "<Unnamed>");
void test_vector(const Vector &vector, std::string name = "<Unnamed>");
void write_to_csv(const Vector &vector, const Vector &vector2, std::string name = "<Unnamed>");