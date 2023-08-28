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
            printf ("Уравнение имеет бесконечно много корней\n");
            break;

        case NO_SOLUTION:
            printf ("Действительных корней нет\n");
            break;

        case ONE_SOLUTION:
            printf ("Данное уравнение имеет 1 корень: %g\n", x_1);
            break;

        case TWO_SOLUTION:
            printf ("Данное уравнение имеет 2 корня: %g и %g\n", x_1, x_2);
            break;

        case NOT_VALID:

        default:
            printf("ОШИБКА! Получено неправильное значение\n");
    }
}
