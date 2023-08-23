#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include"TXLib.h"
#include<math.h>
#include<float.h>
enum solutions {
    ONE_SOLUTION    = 1,
    TWO_SOLUTION    = 2,
    NO_SOLUTION     = 3,   // TODO
    INFINITELY      = 4,
    NOT_VALID       = -1
};
void release(void);

void input_data (double coefficients[]); //функция ввода коэффицентов
void solve_equasion (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions); //функция решения квадратного уравнения
void output_data (double x_1, double x_2, enum solutions number_solutions);//функция вывода
void solve_square (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions);
void solve_linear (const double coefficients[], double * x_1, double * x_2, enum solutions * number_solutions);
double get_coefficent (int index);//функция проверки данных, чтения и очистки буфера
int check_zero (double number);//функция сравнивает значение double с 0
int compare_number (double number_1, double number_2);

void test (void);
void test_equasion (double coefficients[], double x_1_Regular, double x_2_Regular, enum solutions number_solutions_Regular, int index_test);

#endif // HEADER_H_INCLUDED
