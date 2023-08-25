#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "TXLib.h"
#include "colors.h"
#include <math.h>
#include <float.h>

#define MYASSERT(condition)                                                                                         \
{                                                                                                                   \
    if (!(condition))                                                                                               \
    {                                                                                                               \
        printf(MAGENTA "��������: ���������� ������: �������, ��� %s.\n", condition);                               \
        printf("����: %s\n" "������: %d\n" "�������: %s\n" RESET_COLOR, __FILE__, __LINE__, __PRETTY_FUNCTION__);   \
    }                                                                                                               \
}

enum solutions {
    ONE_SOLUTION    = 1,
    TWO_SOLUTION    = 2,
    NO_SOLUTION     = 3,   // TODO-
    INFINITELY      = 4,
    NOT_VALID       = -1
};

enum compare {
    LESS            = 0,
    EQUAL           = 1,
    MORE            = 2,
    NOT_COMPARE     = -1
};

void release(void);

void input_data (double coefficients[]); //������� ����� ������������
solutions solve_equasion (const double coefficients[], double * x_1, double * x_2); //������� ������� ����������� ���������
void output_data (double x_1, double x_2, enum solutions number_solutions);//������� ������
solutions solve_square (const double coefficients[], double * x_1, double * x_2);
solutions solve_linear (const double coefficients[], double * x_1, double * x_2);
double get_coefficent (int index);//������� �������� ������, ������ � ������� ������
bool check_zero (double number);//������� ���������� �������� double � 0
int compare_number (double number_1, double number_2);
int confirm_input (void);
FILE * check_isopen (const char file_name[]);

void test (void);
void test_equasion (double coefficients[], double x_1_Regular, double x_2_Regular, enum solutions number_solutions_Regular, int index_test);


#endif // HEADER_H_INCLUDED
