#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include "constants.hpp"



void test_matrix(double *matrix[constants::n], std::string name);
void test_vector(double vector[], std::string name);