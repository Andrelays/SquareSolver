/*!
\file

\brief Файл с функциями, испоьзующимися для нахождения корней квадратного уравнения
*/

#include "SquareSolver.h"

solutions solve_equasion (const double coefficients[], double * x_1, double * x_2)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != x_1, EQUAL_POINTERS_PASSED_TO_FUNC, return NOT_VALID);

    if (!check_zero(coefficients[0]))//старший коэффицент не 0          / TODO split into functions-
        return solve_square (coefficients, x_1, x_2);

    else
        return solve_linear (coefficients, x_1, x_2);

    #define CHECK_NULL(arg) \
        if (check_zero(arg) || !isfinite(arg)) arg = 0;

    CHECK_NULL (*x_1);
    CHECK_NULL (*x_2);

    #undef CHECK_NULL
}

solutions solve_square (const double coefficients[], double * x_1, double * x_2)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != x_1, EQUAL_POINTERS_PASSED_TO_FUNC, return NOT_VALID);

    double a = coefficients[0],
           b = coefficients[1],
           c = coefficients[2];

    double discriminant = b * b - 4.0 * a * c;

    if (check_zero(discriminant))
    {
        *x_1 = *x_2 = -b / (2 * a);//дискриминант равен 0
        return ONE_SOLUTION;
    }

    else if (discriminant < 0)
    {
        *x_1 = *x_2 = 0;
        return NO_SOLUTION;//Дискриминант меньше 0 (нет корней)
    }

    else
    {
        double sqrt_discriminant = sqrt (discriminant);
        *x_1 = (-b - sqrt_discriminant ) / (2 * a);   //TODO make var-
        *x_2 = (-b + sqrt_discriminant ) / (2 * a);
        return TWO_SOLUTION;
    }
}

solutions solve_linear (const double coefficients[], double * x_1, double * x_2)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_1 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2 != x_1, EQUAL_POINTERS_PASSED_TO_FUNC, return NOT_VALID);

    double b = coefficients[1], c = coefficients[2];

    if (check_zero(b) && check_zero(c))
        {
        *x_1 = *x_2 = 0;
        return INFINITELY;//в случае если все коэффиценты равны 0 (бесконечно много корней)
        }

    else if (check_zero(b))
        {
        *x_1 = *x_2 = 0;
        return NO_SOLUTION;//все коэффиценты кроме свободного члена равны 0 (нет корней)
        }

    else
    {
        *x_1 = *x_2 = -c / b;//линейное уравнение
        return ONE_SOLUTION;

    }
}
