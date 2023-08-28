/*!
\file
\brief Файл с утилитами, используемыми в программе
*/

#include "SquareSolver.h"

bool check_zero (double number) // TODO bool-
{
    MYASSERT(isfinite(number), NON_FINITE_NUM_PASSED_TO_FUNC, return false);

    const double NEAR_ZERO = 1e-6;

    return (fabs (number) < NEAR_ZERO);
}

int compare_number (double number_1, double number_2)
{
    if ((isnan (number_1) && !isnan (number_2)) || (!isnan (number_1) && isnan (number_2)))
        return NOT_COMPARE;

    else if ((isnan (number_1) && isnan (number_2)) || (check_zero (number_1 - number_2)))
        return EQUAL;

    else if (number_1 < number_2)
        return LESS;

    else
        return MORE;
}

FILE * check_isopen (const char file_name[])
{
    MYASSERT(file_name != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    FILE * file_pointer = NULL;

    if ((file_pointer = fopen (file_name, "r")) == NULL || ferror (file_pointer)) // todo func, check isopen-
        printf("ОШИБКА! Не удалось открыть файл \"%s\"!\n", file_name);

    return file_pointer;
}
