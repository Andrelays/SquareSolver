#include"TXLib.h"
#include<math.h>
#include<float.h>
#define SIZES 3
void inputf(double coefficients[]); //������� ����� ������������
double computation_discriminant(double coefficients[]); //������� ���������� �������������
int main(void)
{
    double discriminant;
    double coefficients[SIZES]; // � ������ ��������� ����������� ����������� ���������
    coefficients[1] = coefficients[2] = coefficients[3] = 0;
    inputf(coefficients);
    double a = coefficients[0], b = coefficients[1], x_1, x_2;
    discriminant = computation_discriminant(coefficients);
    if (discriminant < 0)
        printf("�������������� ������ ���!\n");
    else if (fabs(discriminant) < 0.000001)
    {
        x_1 = -b/(2*a);
        printf("������ ����������� ���������: %g\n", x_1);
    }
    else
    {
        x_1 = (-b - sqrt(discriminant))/(2 * a);
        x_2 = (-b + sqrt(discriminant))/(2 * a);
        printf("����� ����������� ���������: %g � %g\n", x_1, x_2);
    }
    return 0;
}
void inputf(double coefficients[])
{
    int el, i;
    printf("������� ����������� ����������� ��������� ����: A*x^2+B*x+C = 0\n");
    printf("������������� ����� ���� ����� � ��������� ������, ��� ��������� ������� ����� ����������� \".\"\n");
    printf("������ ������������: 121 ��� 567.7 \n");
    do
    {
        for (i = 0; i < 3; i++)
        {
            do
            {
                printf("������� ���������� %c = ", 'A' + i);
                scanf("%lf", &coefficients[i]);
                if ((el = getchar()) != '\n')
                {
                    printf("������! ��������� ������ \"%c\", ������� ��������� �� ����� �������!\n", el);
                    printf("�������� ���������� ������� �������, ��������� ������������ �����!\n");
                    while((el = getchar()) != '\n')
                        continue;
                }
                printf("���������� %c = %f\n", 'A' + i, coefficients[i]);
                do
                {
                    if (fabs(coefficients[i]) < 0.000001 && i == 0)
                    {
                        printf("������! �������� ����������� A ������ ���� ��������� ������, ������� ��� ��� ���!\n");
                        break;
                    }
                    if (fabs(coefficients[i]) > FLT_MAX)
                    {
                        printf("������! �������� ����������� %c ������ ���� ������ %g �� ���������� ��������.", 'A' + i, FLT_MAX);
                        break;
                    }
                    printf("E��� �� �������� � ��������� �������, ������� <y>\n");
                    printf("���� �� ������ ������ ������ ��� ���, ������� <n>\n");
                }while ((el = getch()) != 'y' && el != 'n');
            }while(el != 'y');
        }
        printf("���������� ���������: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);
        do
        {
            printf("E��� �� �������� � ��������� �������, ������� <y>\n");
            printf("���� �� ������ ������ ������ ��� ���, ������� <n>\n");
        }while ((el = getch()) != 'y' && el != 'n');
    }while(el != 'y');
}
double computation_discriminant(double coefficients[])
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant;
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return discriminant;
}
