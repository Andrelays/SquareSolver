#include "header.h"
void release(void)
{
    double coefficients[3] = {NAN, NAN, NAN}; // в массив поступают коэффиценты квадратного уравнения
    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    input_data (coefficients);

    solve_equasion (coefficients, &x_1, &x_2, &number_solutions);

    output_data(x_1, x_2, number_solutions);
}
void input_data (double coefficients[])
{
    int consent = 0, index = 0;  // TODO naming
    printf ("Введите коэффиценты квадратного уравнения вида: A*x^2+B*x+C = 0\n");
    printf ("Коэффицентами могут быть числа с плавающей точкой. Пример коэффицентов: 121 или 567.7 \n");
    do
    {
        for (index = 0; index < 3; index++)
        {
            coefficients[index] = get_coefficent (index);
            printf ("Коэффицент %c = %g\n", 'A' + index, coefficients[index]);
        }

        printf ("Квадратное уравнение: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);

        do
        {
            printf ("Eсли вы согласны с введёнными данными, нажмите <y>\n");
            printf ("Если вы хотите ввести данные ещё раз, нажмите <n>\n");
        } while ((consent = getch()) != 'y' && consent != 'n');

    } while (consent != 'y');
}

void solve_equasion (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions)
{
    assert(isfinite(coefficients[0]));
    assert(isfinite(coefficients[1]));
    assert(isfinite(coefficients[2]));

    if (!check_zero(coefficients[0]))//старший коэффицент не 0          / TODO split into functions
        solve_square (coefficients, x_1, x_2, number_solutions);

    else
        solve_linear (coefficients, x_1, x_2, number_solutions);

    #define CHECK_NULL(arg) \
        if (check_zero(arg)|| !isfinite(arg)) arg = 0;

    CHECK_NULL (*x_1);
    CHECK_NULL (*x_2);

    #undef CHECK_NULL
}

void output_data (double x_1, double x_2, enum solutions number_solutions)
{
    assert(isfinite(x_1));
    assert(isfinite(x_2));

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

void solve_square (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions)
{
    assert(isfinite(coefficients[0]));
    assert(isfinite(coefficients[1]));
    assert(isfinite(coefficients[2]));

    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant = NAN, sqrt_discriminant = NAN;

    discriminant = b * b - 4.0 * a * c;

    if (check_zero(discriminant))
    {
        *x_1 = *x_2 = -b / (2 * a);//дискриминант равен 0
        *number_solutions = ONE_SOLUTION;
    }

    else if (discriminant < 0)
    {
        *number_solutions = NO_SOLUTION;//Дискриминант меньше 0 (нет корней)
        *x_1 = *x_2 = 0;
    }

    else
    {
        sqrt_discriminant = sqrt (discriminant);
        *x_1 = (-b - sqrt_discriminant ) / (2 * a);   //TODO make var
        *x_2 = (-b + sqrt_discriminant ) / (2 * a);
        *number_solutions = TWO_SOLUTION;
    }
}

void solve_linear (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions)
{
    assert(isfinite(coefficients[0]));
    assert(isfinite(coefficients[1]));
    assert(isfinite(coefficients[2]));

    double b = coefficients[1], c = coefficients[2];

    if (check_zero(b) && check_zero(c))
        {
        *number_solutions = INFINITELY;//в случае если все коэффиценты равны 0 (бесконечно много корней)
        *x_1 = *x_2 = 0;
        }

    else if (check_zero(b))
        {
        *number_solutions = NO_SOLUTION;//все коэффиценты кроме свободного члена равны 0 (нет корней)
        *x_1 = *x_2 = 0;
        }

    else
    {
        *x_1 = *x_2 = -c / b;//линейное уравнение
        *number_solutions = ONE_SOLUTION;

    }
}

double get_coefficent (int index)
{
    double coefficient = NAN;
    int symbol = 0;

    printf ("Введите коэффицент %c = ", 'A' + index);

    while(scanf ("%lf", &coefficient) != 1 || fabs(coefficient) > FLT_MAX)
    {
        printf("ОШИБКА! Введите значение коэффицента ещё раз!\n");

        while ((symbol = getchar()) != '\n')
            continue;

        if (isinf(coefficient)) // TODO is_inf
            printf ("ОШИБКА! Значение коэффицента %c слишком велико по абсолютной величине.\n", 'A' + index);

        printf ("Введите коэффицент %c = ", 'A' + index);
    }

    return coefficient;
}

int check_zero (double number)
{
    assert(isfinite(number));

    const double NEAR_ZERO = 0.000001;

    if (fabs(number) < NEAR_ZERO)
        return 1;
    else
        return 0;
}

int compare_number (double number_1, double number_2)
{
    if  ((isnan (number_1) && isnan (number_2)) || (!isnan (number_1) && !isnan (number_2) && check_zero (number_1 - number_2)))
        return 1;
    else
        return 0;

}

void test(void)
{
    FILE * file_pointer = 0;

    if ((file_pointer = fopen("data.txt", "r")) == NULL)
        printf("ОШИБКА! Не удалось открыть файл \"data.txt\"!\n");

    else
    {
        int number_tests = 0, index_test = 0;

        fscanf(file_pointer, "%d", &number_tests);

        for (index_test = 0; index_test < number_tests; index_test++)
        {
            double coefficients[3] = {NAN, NAN, NAN};
            enum solutions number_solutions_Regular = NOT_VALID;
            double x_1_Regular = NAN, x_2_Regular = NAN;

            fscanf(file_pointer, "%lg%lg%lg", &coefficients[0], &coefficients[1], &coefficients[2]);
            fscanf(file_pointer, "%lg%lg%d", &x_1_Regular, &x_2_Regular, &number_solutions_Regular);

            test_equasion (coefficients, x_1_Regular, x_2_Regular, number_solutions_Regular, index_test);
        }
        fclose(file_pointer);
    }
}

void test_equasion (double coefficients[], double x_1_Regular, double x_2_Regular, enum solutions number_solutions_Regular, int index_test)
{
    assert(isfinite(coefficients[0]));
    assert(isfinite(coefficients[1]));
    assert(isfinite(coefficients[2]));
    assert(isfinite(x_1_Regular));
    assert(isfinite(x_2_Regular));

    double x_1 = NAN, x_2 = NAN;
    enum solutions number_solutions = NOT_VALID;

    solve_equasion (coefficients, &x_1, &x_2, &number_solutions);

    if (!compare_number(x_1, x_1_Regular) || !compare_number(x_2, x_2_Regular) || number_solutions_Regular != number_solutions)
    {
        printf("ОШИБКА!\nТест %d провален! Коэффиценты: %f %f %f\n", index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
        printf("Ожидаеммые данные: %f %f %d\n", x_1_Regular, x_2_Regular, number_solutions_Regular);
        printf("Полученные данные: %f %f %d\n", x_1, x_2, number_solutions);
    }
    else
        printf("Тест %d пройден! Коэффиценты: %f %f %f\n", index_test + 1, coefficients[0], coefficients[1], coefficients[2]);
}
