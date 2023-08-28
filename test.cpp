/*!
\file
\brief Программа содержит функции, вызываемые в main.cpp чтобы протестировать программу для решения квадратных уравнений
*/

#include "SquareSolver.h"

void test()
{
    const char file_name[] = "data.txt";

    FILE * file_pointer = check_isopen (file_name);

    if (file_pointer != NULL)
    {
        int number_tests = 0, index_test = 0;

        fscanf(file_pointer, "%d", &number_tests);

        for (index_test = 0; index_test < number_tests; index_test++)
        {
            double coefficients[3] = {NAN, NAN, NAN};
            enum solutions number_solutions_correct = NOT_VALID;
            double x_1_correct = NAN, x_2_correct = NAN;

            number_solutions_correct = read_test (coefficients, &x_1_correct, &x_2_correct, file_pointer);

            test_equasion (coefficients, x_1_correct, x_2_correct, number_solutions_correct, index_test);
        }
        fclose(file_pointer);
    }
}

void test_equasion (const double coefficients[], double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, int index_test)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_1_correct), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_2_correct), NON_FINITE_NUM_PASSED_TO_FUNC, return);

    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    number_solutions = solve_equasion (coefficients, &x_1, &x_2);

    if (!compare_test_result (x_1_correct, x_2_correct, number_solutions_correct, number_solutions, x_1, x_2))
        print_test_failed (coefficients, x_1_correct, x_2_correct, number_solutions_correct, index_test, number_solutions, x_1, x_2);

    else
        print_test_passed (coefficients, index_test);
}

solutions read_test (double coefficients[], double * x_1_correct, double * x_2_correct, FILE * file_pointer)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_1_correct != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2_correct != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(file_pointer != NULL, NULL_POINTER_PASSED_TO_FUNC, return NOT_VALID);
    MYASSERT(x_2_correct != x_1_correct, EQUAL_POINTERS_PASSED_TO_FUNC, return NOT_VALID);

    enum solutions number_solutions_correct = NOT_VALID;

    fscanf(file_pointer, " COEFF %lg%lg%lg ROOTS %lg%lg SOLUTIONS %d", &coefficients[0], &coefficients[1], &coefficients[2], x_1_correct, x_2_correct, (int*)&number_solutions_correct);

    return number_solutions_correct;
}

bool compare_test_result (double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, enum solutions number_solutions, double x_1, double x_2)
{
    if (compare_number(x_1, x_1_correct) != EQUAL || compare_number(x_2, x_2_correct) != EQUAL || number_solutions_correct != number_solutions)
        return 0;

    else
        return 1;
}

void print_test_failed (const double coefficients[], double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, int index_test, enum solutions number_solutions, double x_1, double x_2)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_1_correct), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_2_correct), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_1), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(x_2), NON_FINITE_NUM_PASSED_TO_FUNC, return);

    printf(RED "Ошибка!\nТест %d Провален! Коэффиценты: %f %f %f\n", index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
    printf("Ожидаемые данные: %f %f %d\n", x_1_correct, x_2_correct, number_solutions_correct);
    printf("Полученные данные: %f %f %d\n" RESET_COLOR, x_1, x_2, number_solutions);
}

void print_test_passed (const double coefficients[], int index_test)
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[0]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[1]), NON_FINITE_NUM_PASSED_TO_FUNC, return);
    MYASSERT(isfinite(coefficients[2]), NON_FINITE_NUM_PASSED_TO_FUNC, return);

    printf(GREEN "Тест %d пройден! Коэффиценты: %f %f %f\n" RESET_COLOR, index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
}
