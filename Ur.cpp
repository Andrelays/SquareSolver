#include"TXLib.h"
#include<math.h>
#include<float.h>
#define SIZES 3
void inputf(double coefficients[]); //функция ввода коэффицентов
double computation_discriminant(double coefficients[]); //функция нахождения дискриминанта
int main(void)
{
    double discriminant;
    double coefficients[SIZES]; // в массив поступают коэффиценты квадратного уравнения
    coefficients[1] = coefficients[2] = coefficients[3] = 0;
    inputf(coefficients);
    double a = coefficients[0], b = coefficients[1], x_1, x_2;
    discriminant = computation_discriminant(coefficients);
    if (discriminant < 0)
        printf("Действительных корней нет!\n");
    else if (fabs(discriminant) < 0.000001)
    {
        x_1 = -b/(2*a);
        printf("Корень квадратного уравнения: %g\n", x_1);
    }
    else
    {
        x_1 = (-b - sqrt(discriminant))/(2 * a);
        x_2 = (-b + sqrt(discriminant))/(2 * a);
        printf("Корни квадратного уравнения: %g и %g\n", x_1, x_2);
    }
    return 0;
}
void inputf(double coefficients[])
{
    int el, i;
    printf("Введите коэффиценты квадратного уравнения вида: A*x^2+B*x+C = 0\n");
    printf("Коэффицентами могут быть числа с плавающей точкой, для отделения дробной части используйте \".\"\n");
    printf("Пример коэффицентов: 121 или 567.7 \n");
    do
    {
        for (i = 0; i < 3; i++)
        {
            do
            {
                printf("Введите коэффицент %c = ", 'A' + i);
                scanf("%lf", &coefficients[i]);
                if ((el = getchar()) != '\n')
                {
                    printf("ОШИБКА! Обнаружен символ \"%c\", который программа не может считать!\n", el);
                    printf("Возможно коэффицент сохранён неверно, проверьте правильность ввода!\n");
                    while((el = getchar()) != '\n')
                        continue;
                }
                printf("Коэффицент %c = %f\n", 'A' + i, coefficients[i]);
                do
                {
                    if (fabs(coefficients[i]) < 0.000001 && i == 0)
                    {
                        printf("ОШИБКА! Значение коэффицента A должно быть ненулевым числом, введите его ещё раз!\n");
                        break;
                    }
                    if (fabs(coefficients[i]) > FLT_MAX)
                    {
                        printf("ОШИБКА! Значение коэффицента %c должно быть меньше %g по абсолютной величине.", 'A' + i, FLT_MAX);
                        break;
                    }
                    printf("Eсли вы согласны с введёнными данными, нажмите <y>\n");
                    printf("Если вы хотите ввести данные ещё раз, нажмите <n>\n");
                }while ((el = getch()) != 'y' && el != 'n');
            }while(el != 'y');
        }
        printf("Квадратное уравнение: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);
        do
        {
            printf("Eсли вы согласны с введёнными данными, нажмите <y>\n");
            printf("Если вы хотите ввести данные ещё раз, нажмите <n>\n");
        }while ((el = getch()) != 'y' && el != 'n');
    }while(el != 'y');
}
double computation_discriminant(double coefficients[])
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant;
    discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return discriminant;
}
