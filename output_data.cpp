/*!
\file
\brief Файл с функциями, использующимися для вывода корней квадратного уравнения
*/

#include "square_solver.h"

void output_data (double x_1, double x_2, enum solutions number_solutions)
{
    MYASSERT(isfinite(x_1), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_2), NON_FINITE_NUM_PASSED_TO_FUNC, return);

    switch (number_solutions)
    {
        case INFINITELY:
            printf ("The equation has infinitely many roots\n");
            break;

        case NO_SOLUTION:
            printf ("There are no valid roots\n");
            break;

        case ONE_SOLUTION:
            printf ("This equation has 1 root: %g\n", x_1);
            break;

        case TWO_SOLUTION:
            printf ("This equation has 2 roots: %g и %g\n", x_1, x_2);
            break;

        case NOT_VALID:

        default:
            printf("MISTAKE! Incorrect value received\n");
    }
}
