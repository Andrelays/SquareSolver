/*!
\file
\brief Файл с функцией, release, которая выполняется в случае, если отключен режим TEST
*/

#include "SquareSolver.h"

void release()
{
    double coefficients[] = {NAN, NAN, NAN}; // в массив поступают коэффиценты квадратного уравнения
    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    input_data (coefficients);

    number_solutions = solve_equasion (coefficients, &x_1, &x_2);

    output_data(x_1, x_2, number_solutions);
} 
