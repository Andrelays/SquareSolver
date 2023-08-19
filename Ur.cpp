#include"TXLib.h"
#include<math.h>
#include<float.h>
#define NEAR_ZERO 0.000001
void input_data (double coefficients[]); //функция ввода коэффицентов
void solve_equasion (const double coefficients[], double * x_1, double * x_2, int * flag); //функция решения квадратного уравнения
int main (void)
{
    double coefficients[3]; // в массив поступают коэффиценты квадратного уравнения
    coefficients[0] = coefficients[1] = coefficients[2] = 0;
    input_data (coefficients);
    int flag = 0; // значение будет изменено в случае отрицательного дискриминанта или если несколько коэффицентов равны 0
    double x_1 = 0, x_2 = 0;
    solve_equasion (coefficients, &x_1, &x_2, &flag);
    if (flag == 2)
        printf ("Уравнение имеет бесконечно много корней\n");
    else if (flag == 1)
        printf ("Действительных корней нет\n");
    else if (fabs(x_1 - x_2) < NEAR_ZERO)
        printf ("Данное уравнение имеет 1 корень: %g", x_1);
    else
        printf ("Данное уравнение имеет 2 корня: %g и %g", x_1, x_2);
    return 0;
}
void input_data (double coefficients[])
{
    int element, index;
    printf ("Введите коэффиценты квадратного уравнения вида: A*x^2+B*x+C = 0\n");
    printf ("Коэффицентами могут быть числа с плавающей точкой. Пример коэффицентов: 121 или 567.7 \n");
    do
    {
        for (index = 0; index < 3; index++)
        {
            printf ("Введите коэффицент %c = ", 'A' + index);
            scanf ("%lf", &coefficients[index]);
            if ((element = getchar()) != '\n')
            {
                printf ("ОШИБКА! Обнаружен символ \"%c\", который программа не может считать!\n", element);
                printf ("Возможно коэффицент сохранён неверно, проверьте правильность ввода!\n");
                while ((element = getchar()) != '\n')
                    continue;
            }
            if (fabs(coefficients[index]) > FLT_MAX)
            {
                printf ("ОШИБКА! Значение коэффицента %c должно быть меньше %g по абсолютной величине.\n", 'A' + index, FLT_MAX);
                coefficients[index] = 0;
            }
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
void solve_equasion (const double coefficients[], double * x_1, double * x_2, int * flag)
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant;
    if (fabs(a) > NEAR_ZERO)//старший коэффицент не 0
    {
        discriminant = b * b - 4.0 * a * c;
        if (discriminant < 0)
            *flag = 1;//Дискриминант меньше 0 (нет корней)
        else if (fabs(discriminant) < NEAR_ZERO)
            *x_1 = *x_2 = -b / (2 * a);//дискриминант равен 0
        else
        {
            *x_1 = (-b - sqrt (discriminant)) / (2 * a);
            *x_2 = (-b + sqrt (discriminant)) / (2 * a);
        }
    }
    else if (fabs(b) < NEAR_ZERO && fabs(c) < NEAR_ZERO)
        *flag = 2;//в случае если все коэффиценты равны 0 (бесконечно много корней)
    else if (fabs(b) < NEAR_ZERO)
        *flag = 1;//все коэффиценты кроме свободного члена равны 0 (нет корней)
    else
        *x_1 = *x_2 = -c / b;//линейное уравнение
}
