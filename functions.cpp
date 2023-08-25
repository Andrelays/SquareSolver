#include "header.h"

void release(void)
{
    double coefficients[] = {NAN, NAN, NAN}; // � ������ ��������� ����������� ����������� ���������
    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    input_data (coefficients);

    number_solutions = solve_equasion (coefficients, &x_1, &x_2);

    output_data(x_1, x_2, number_solutions);
}  // TODO space-

void input_data (double coefficients[])
{
    int consent = 0, index = 0;  // TODO naming-
    printf ("������� ����������� ����������� ��������� ����: A*x^2+B*x+C = 0\n");
    printf ("������������� ����� ���� ����� � ��������� ������. ������ ������������: 121 ��� 567.7 \n");
    do
    {
        for (index = 0; index < 3; index++)
        {
            coefficients[index] = get_coefficent (index);
            printf ("���������� %c = %g\n", 'A' + index, coefficients[index]);
        }

        printf ("���������� ���������: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);

        consent = confirm_input();

    } while (consent != 'y');
}

solutions solve_equasion (const double coefficients[], double * x_1, double * x_2)
{
    MYASSERT(isfinite(coefficients[0]));
    MYASSERT(isfinite(coefficients[1]));
    MYASSERT(isfinite(coefficients[2]));
    MYASSERT(x_1 != NULL);
    MYASSERT(x_2 != NULL);
    MYASSERT(x_2 != x_1);

    if (!check_zero(coefficients[0]))//������� ���������� �� 0          / TODO split into functions-
        return solve_square (coefficients, x_1, x_2);

    else
        return solve_linear (coefficients, x_1, x_2);

    #define CHECK_NULL(arg) \
        if (check_zero(arg) || !isfinite(arg)) arg = 0;

    CHECK_NULL (*x_1);
    CHECK_NULL (*x_2);

    #undef CHECK_NULL
}

void output_data (double x_1, double x_2, enum solutions number_solutions)
{
    MYASSERT(isfinite(x_1));
    MYASSERT(isfinite(x_2));

    switch (number_solutions)
    {
        case INFINITELY:
            printf ("��������� ����� ���������� ����� ������\n");
            break;

        case NO_SOLUTION:
            printf ("�������������� ������ ���\n");
            break;

        case ONE_SOLUTION:
            printf ("������ ��������� ����� 1 ������: %g\n", x_1);
            break;

        case TWO_SOLUTION:
            printf ("������ ��������� ����� 2 �����: %g � %g\n", x_1, x_2);
            break;

        case NOT_VALID:

        default:
            printf("������! �������� ������������ ��������\n");
    }
}

solutions solve_square (const double coefficients[], double * x_1, double * x_2)
{
    MYASSERT(isfinite(coefficients[0]));
    MYASSERT(isfinite(coefficients[1]));
    MYASSERT(isfinite(coefficients[2]));
    MYASSERT(x_1 != NULL);
    MYASSERT(x_2 != NULL);
    MYASSERT(x_2 != x_1);

    double a = coefficients[0],
           b = coefficients[1],
           c = coefficients[2];

    double discriminant = b * b - 4.0 * a * c;

    if (check_zero(discriminant))
    {
        *x_1 = *x_2 = -b / (2 * a);//������������ ����� 0
        return ONE_SOLUTION;
    }

    else if (discriminant < 0)
    {
        *x_1 = *x_2 = 0;
        return NO_SOLUTION;//������������ ������ 0 (��� ������)
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
    MYASSERT(isfinite(coefficients[0]));
    MYASSERT(isfinite(coefficients[1]));
    MYASSERT(isfinite(coefficients[2]));
    MYASSERT(x_1 != NULL);
    MYASSERT(x_2 != NULL);
    MYASSERT(x_2 != x_1);

    double b = coefficients[1], c = coefficients[2];

    if (check_zero(b) && check_zero(c))
        {
        *x_1 = *x_2 = 0;
        return INFINITELY;//� ������ ���� ��� ����������� ����� 0 (���������� ����� ������)
        }

    else if (check_zero(b))
        {
        *x_1 = *x_2 = 0;
        return NO_SOLUTION;//��� ����������� ����� ���������� ����� ����� 0 (��� ������)
        }

    else
    {
        *x_1 = *x_2 = -c / b;//�������� ���������
        return ONE_SOLUTION;

    }
}

double get_coefficent (int index)
{
    double coefficient = NAN;
    int symbol = 0;

    printf ("������� ���������� %c = ", 'A' + index);

    while (scanf ("%lf", &coefficient) != 1 || isinf(coefficient))
    {
        printf("������! ������� �������� ����������� ��� ���!\n");

        while ((symbol = getchar()) != '\n')
            continue;   //todo

        if (isinf(coefficient)) // TODO is_inf-
            printf ("������! �������� ����������� %c ������� ������ �� ���������� ��������.\n", 'A' + index);

        printf ("������� ���������� %c = ", 'A' + index);
    }

    return coefficient;
}

bool check_zero (double number) // TODO bool-
{
    MYASSERT(isfinite(number));

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

int confirm_input (void)
{
    int consent = 0;
    do
    {
        printf ("E��� �� �������� � ��������� �������, ������� <y>\n");
        printf ("���� �� ������ ������ ������ ��� ���, ������� <n>\n");
    } while ((consent = getch()) != 'y' && consent != 'n');

    return consent;
}

FILE * check_isopen (const char file_name[])
{
    FILE * file_pointer = NULL;

    if ((file_pointer = fopen (file_name, "r")) == NULL || ferror (file_pointer)) // todo func, check isopen-
        printf("������! �� ������� ������� ���� \"%s\"!\n", file_name);

    return file_pointer;
}

void test(void)
{
    const char file_name[50] = "data.txt";

    FILE * file_pointer = check_isopen (file_name);   //todo null-

    if (file_pointer != NULL)
    {
        int number_tests = 0, index_test = 0;

        fscanf(file_pointer, "%d", &number_tests);

        for (index_test = 0; index_test < number_tests; index_test++)
        {
            double coefficients[3] = {NAN, NAN, NAN};
            enum solutions number_solutions_correct = NOT_VALID;
            double x_1_correct = NAN, x_2_correct = NAN; //todo correct-

            fscanf(file_pointer, " COEFF %lg%lg%lg", &coefficients[0], &coefficients[1], &coefficients[2]);
            fscanf(file_pointer, " ROOTS %lg%lg", &x_1_correct, &x_2_correct);
            fscanf(file_pointer, " SOLUTIONS %d", &number_solutions_correct);

            test_equasion (coefficients, x_1_correct, x_2_correct, number_solutions_correct, index_test);
        }
        fclose(file_pointer);
    }
}

void test_equasion (double coefficients[], double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, int index_test)
{
    MYASSERT(isfinite(coefficients[0]));
    MYASSERT(isfinite(coefficients[1]));
    MYASSERT(isfinite(coefficients[2]));
    MYASSERT(isfinite(x_1_correct));
    MYASSERT(isfinite(x_2_correct));

    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    number_solutions = solve_equasion (coefficients, &x_1, &x_2);

    if (compare_number(x_1, x_1_correct) != EQUAL || compare_number(x_2, x_2_correct) != EQUAL || number_solutions_correct != number_solutions)      //todo compare test result
    {
        printf(RED "������!\n���� %d ��������! �����������: %f %f %f\n", index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
        printf("���������� ������: %f %f %d\n", x_1_correct, x_2_correct, number_solutions_correct);
        printf("���������� ������: %f %f %d\n" RESET_COLOR, x_1, x_2, number_solutions);
    }
    else
        printf(GREEN "���� %d �������! �����������: %f %f %f\n" RESET_COLOR, index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
}


