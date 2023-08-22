#include"TXLib.h"
#include<math.h>
#include<float.h>
#define NEAR_ZERO 0.000001
enum solutions {
    ONE_SOLUTION,
    TWO_SOLUTION,
    NO_SOLUTION,
    INFINITELY,
    NOT_VALID
};
void input_data (double coefficients[]); //функция ввода коэффицентов
void solve_equasion (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions); //функция решения квадратного уравнения
void output_data (double x_1, double x_2, enum solutions number_solutions);//функция вывода
double get_coefficent (int index);//функция проверки данных, чтения и очистки буфера
int check_zero (double number);//функция сравнивает значение double с 0

int main (void)
{
    double coefficients[3] {NAN, NAN, NAN}; // в массив поступают коэффиценты квадратного уравнения
    input_data (coefficients);
    enum solutions number_solutions = NOT_VALID;
    double x_1 = NAN, x_2 = NAN;
    solve_equasion (coefficients, &x_1, &x_2, &number_solutions);
    output_data(x_1, x_2, number_solutions);
    return 0;
}

void input_data (double coefficients[])
{
    int element = 0, index = 0;
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
        }while ((element = getch()) != 'y' && element != 'n');
    }while (element != 'y');
}

void solve_equasion (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions)
{
    assert(isfinite(coefficients[0]));
    assert(isfinite(coefficients[1]));
    assert(isfinite(coefficients[2]));
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant = NAN;
    if (!check_zero(a))//старший коэффицент не 0
    {
        discriminant = b * b - 4.0 * a * c;
        if (check_zero(discriminant))
        {
            *x_1 = *x_2 = -b / (2 * a);//дискриминант равен 0
            *number_solutions = ONE_SOLUTION;
        }
        else if (discriminant < 0)
            *number_solutions = NO_SOLUTION;//Дискриминант меньше 0 (нет корней)
        else
        {
            *x_1 = (-b - sqrt (discriminant)) / (2 * a);
            *x_2 = (-b + sqrt (discriminant)) / (2 * a);
            *number_solutions = TWO_SOLUTION;
        }
    }
    else if (check_zero(b) && check_zero(c))
        *number_solutions = INFINITELY;//в случае если все коэффиценты равны 0 (бесконечно много корней)
    else if (check_zero(b))
        *number_solutions = NO_SOLUTION;//все коэффиценты кроме свободного члена равны 0 (нет корней)
    else
    {
        *x_1 = *x_2 = -c / b;//линейное уравнение
        *number_solutions = ONE_SOLUTION;

    }
}

void output_data (double x_1, double x_2, enum solutions number_solutions)
{
    if (number_solutions == ONE_SOLUTION || number_solutions == TWO_SOLUTION)
    {
        assert(isfinite(x_1));
        assert(isfinite(x_2));
    }
    switch (number_solutions)
    {
    case INFINITELY:
        printf ("Уравнение имеет бесконечно много корней\n");
        break;
    case NO_SOLUTION:
        printf ("Действительных корней нет\n");
        break;
    case ONE_SOLUTION:
        printf ("Данное уравнение имеет 1 корень: %g", x_1);
        break;
    case TWO_SOLUTION:
        printf ("Данное уравнение имеет 2 корня: %g и %g", x_1, x_2);
        break;
    case NOT_VALID:
        printf("ОШИБКА! solutions number_solutions == NOT_VALID");
        break;
    default:
        printf("ОШИБКА! Получено неправильное значение");
    }
}

double get_coefficent (int index)
{
    double coefficient = NAN;
    int element = 0;
    printf ("Введите коэффицент %c = ", 'A' + index);
    while(scanf ("%lf", &coefficient) != 1 || fabs(coefficient) > FLT_MAX)
    {
        printf("ОШИБКА! Введите значение коэффицента ещё раз!\n");
        while ((element = getchar()) != '\n')
        continue;
        if (fabs(coefficient) > FLT_MAX)
            printf ("ОШИБКА! Значение коэффицента %c должно быть меньше %g по абсолютной величине.\n", 'A' + index, FLT_MAX);
        printf ("Введите коэффицент %c = ", 'A' + index);
    }
    return coefficient;
}

int check_zero (double number)
{
    assert(isfinite(number));
    if (fabs(number) < NEAR_ZERO)
        return 1;
    else
        return 0;
}
