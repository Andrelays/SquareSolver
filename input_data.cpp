/*!
\file
\brief Файл с функциями, использующимися для ввода коэффицентов квадратного уравнения
*/

#include "SquareSolver.h"

void input_data (double coefficients[])
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    int consent = 0, index = 0;  // TODO naming-
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

        consent = confirm_input();

    } while (consent != 'y');
}

double get_coefficent (int index)
{
    double coefficient = NAN;

    printf ("Введите коэффицент %c = ", 'A' + index);

    while (scanf ("%lf", &coefficient) != 1 || isinf(coefficient))
    {
        printf("ОШИБКА! Введите значение коэффицента ещё раз!\n");

        flush_buffer ();

        if (isinf(coefficient)) // TODO is_inf-
            printf ("ОШИБКА! Значение коэффицента %c слишком велико по абсолютной величине.\n", 'A' + index);

        printf ("Введите коэффицент %c = ", 'A' + index);
    }

    return coefficient;
}

int confirm_input ()
{
    int consent = 0;
    do
    {
        printf ("Eсли вы согласны с введёнными данными, нажмите <y>\n");
        printf ("Если вы хотите ввести данные ещё раз, нажмите <n>\n");
    } while ((consent = getch()) != 'y' && consent != 'n');

    return consent;
}

void flush_buffer ()
{
    int symbol = 0;

    while ((symbol = getchar()) != '\n')
        continue;
}
