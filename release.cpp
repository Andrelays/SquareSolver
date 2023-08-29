/*!
\file
\brief Файл с функцией, release, которая выполняется в случае, если отключен режим TEST
*/

#include "square_solver.h"

void release()
{
    double coefficients[] = {NAN, NAN, NAN}; // в массив поступают коэффиценты квадратного уравнения
    double x_1 = NAN, x_2 = NAN;

    input_data (coefficients);

    solutions number_solutions = NOT_VALID;

    number_solutions = solve_equasion (coefficients, &x_1, &x_2);

    output_data(x_1, x_2, number_solutions);
} 
