#include"TXLib.h"
#include<math.h>
#include<float.h>
#define NEAR_ZERO 0.000001
enum solutions {natural_number, no_solution, infinitely};
void input_data (double coefficients[]); //функция ввода коэффицентов
void solve_equasion (const double coefficients[], double * x_1, double * x_2, int * number_solutions); //функция решения квадратного уравнения
void output_data (double x_1, double x_2, int number_solutions);//функция вывода
double get_coefficent (int index);//функция проверки данных, чтения и очистки буфера
int check_zero (double number);//функция сравнивает значение double с 0
int main (void)
{
    double coefficients[3] {NAN, NAN, NAN}; // в массив поступают коэффиценты квадратного уравнения
    input_data (coefficients);
    int number_solutions = natural_number; // значение будет изменено в случае отрицательного дискриминанта или если несколько коэффицентов равны 0
    double x_1 = 0, x_2 = 0;
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
void solve_equasion (const double coefficients[], double * x_1, double * x_2, int * number_solutions)
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant;
    if (!check_zero(a))//старший коэффицент не 0
    {
        discriminant = b * b - 4.0 * a * c;
        if (check_zero(discriminant))
            *x_1 = *x_2 = -b / (2 * a);//дискриминант равен 0
        else if (discriminant < 0)
            *number_solutions = no_solution;//Дискриминант меньше 0 (нет корней)
        else
        {
            *x_1 = (-b - sqrt (discriminant)) / (2 * a);
            *x_2 = (-b + sqrt (discriminant)) / (2 * a);
        }
    }
    else if (check_zero(b) && check_zero(c))
        *number_solutions = infinitely;//в случае если все коэффиценты равны 0 (бесконечно много корней)
    else if (check_zero(b))
        *number_solutions = no_solution;//все коэффиценты кроме свободного члена равны 0 (нет корней)
    else
        *x_1 = *x_2 = -c / b;//линейное уравнение
}
void output_data (double x_1, double x_2, int number_solutions)
{
    if (number_solutions == infinitely)
        printf ("Уравнение имеет бесконечно много корней\n");
    else if (number_solutions == no_solution)
        printf ("Действительных корней нет\n");
    else if (check_zero(x_1 - x_2))
        printf ("Данное уравнение имеет 1 корень: %g", x_1);
    else
        printf ("Данное уравнение имеет 2 корня: %g и %g", x_1, x_2);
}
double get_coefficent (int index)
{
    double coefficient = NAN;
    int element = 0;
    while(isnan(coefficient) || fabs(coefficient) > FLT_MAX)
    {
        printf ("Введите коэффицент %c = ", 'A' + index);
        scanf ("%lf", &coefficient);
        if ((element = getchar()) != '\n')
        {
            printf ("ОШИБКА! Обнаружен символ \"%c\", который программа не может считать!\n", element);
            printf ("Возможно коэффицент сохранён неверно, проверьте правильность ввода!\n");
            while ((element = getchar()) != '\n')
            continue;
        }
        if (fabs(coefficient) > FLT_MAX)
            printf ("ОШИБКА! Значение коэффицента %c должно быть меньше %g по абсолютной величине.\n", 'A' + index, FLT_MAX);
    }
    return coefficient;
}
int check_zero (double number)
{
    if (fabs(number) < NEAR_ZERO)
        return 1;
    else
        return 0;
}
