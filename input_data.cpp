/*!
\file
\brief Файл с функциями, использующимися для ввода коэффицентов квадратного уравнения
*/

#include "square_solver.h"

void input_data (double coefficients[])
{
    MYASSERT(coefficients != NULL, NULL_POINTER_PASSED_TO_FUNC, return);

    int consent = 0, index = 0;  
    printf ("Enter the coefficients of a quadratic equation of the form: A*x^2+B*x+C = 0\n");
    printf ("Coefficients can be floating point numbers. Example of coefficients: 121 or 567.7 \n");
    do
    {
        for (index = 0; index < 3; index++)
        {
            coefficients[index] = get_coefficent (index);
            printf ("Coefficient %c = %g\n", 'A' + index, coefficients[index]);
        }

        printf ("The quadratic equation: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);

        consent = confirm_input();

    } while (consent != 'y');
}

double get_coefficent (int index)
{
    double coefficient = NAN;

    printf ("Enter the coefficient %c = ", 'A' + index);

    while (scanf ("%lf", &coefficient) != 1 || isinf(coefficient))
    {
        printf("MISTAKE! Enter the coefficient value again!\n");

        flush_buffer ();

        if (isinf(coefficient)) 
            printf ("MISTAKE! The value of the %c coefficient is too large in absolute value.\n", 'A' + index);

        printf ("Enter the coefficient %c = ", 'A' + index);
    }

    return coefficient;
}

int confirm_input ()
{
    int consent = 0;
    do
    {
        printf ("If you agree with the entered data, click <y>\n");
        printf ("If you want to enter the data again, click <n>\n");
    } while ((consent = getch()) != 'y' && consent != 'n');

    return consent;
}

void flush_buffer ()
{
    int symbol = 0;

    while ((symbol = getchar()) != '\n' && symbol != EOF)
        continue;
}
