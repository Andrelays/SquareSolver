/*!
\file

\brief Header файл с прототипами функций, включениями и перечислениями
*/

#ifndef SQUARESOLVER_H_INCLUDED
#define SQUARESOLVER_H_INCLUDED

#include "TXLib.h"
#include "colors.h"
#include "myassert.h"
#include <math.h>
#include <float.h>

/// Набор возможного количества корней у уравнения
enum solutions {
    ONE_SOLUTION    = 1,///< Указывает, что уравнение имеет 1 корень
    TWO_SOLUTION    = 2,///< Указывает, что уравнение имеет 2 кореня
    NO_SOLUTION     = 3,///< Указывает, что уравнение не имеет корней
    INFINITELY      = 4,///< Указывает, что уравнение имеет бесконечное количество кореней
    NOT_VALID       = -1///< Указывает, что уравнение имеет неправильное значение количества корней
};



/// Набор возможных вариантов сравнений 2 чисел
enum compare {
    LESS            = 0,///< Указывает, что 1 число меньше, чем 2
    EQUAL           = 1,///< Указывает, что 1 число равно 2
    MORE            = 2,///< Указывает, что 1 число больше, чем 2
    NOT_COMPARE     = -1///< Указывает, что числа 1 и 2 нельзя сравнить
};

/*!
Релизная версия программы: принимает три числа с плавающей точкой и решает квадратное уравнение, считая их коэффициентами квадратного уравнения.
*/
void release();

/*!
Функция ввода коэффицентов квадратного уравнения, которая вызывает функции get_coefficent и confirm_input. Ввод будет продолжаться, пока пользователь не подтвердит его. Вводимые коэффиценты должны быть числа с плавающей точкой, если ввод не верный, то программа попросит пользователя ввести данные ещё раз. После ввода каждого коэффицента буфер ввода очищается.   
\param[out] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
*/
void input_data (double coefficients[]); //функция ввода коэффицентов

/*!
Функция решения квадратного уравнения, принимает 3 коэффицента квадратного уравнения и записывает корни по указателям x_1 и x_2.Проверяет линейное уравнение или квадратное, после чего вызывает соответствующие функции, которые решают это уравнение. Если уравнение не имеет корней или имеет бесконечно много корней, то по указателям записывается 0. Если квадратное уравнение имеет 1 корень, то этот корень записывается по обоим указателям. Возвращаемое знанчение функции - количество корней квадратного уравнения.  
\param[in] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[out] *x_1 Указатель на 1 корень квадратного уравнения
\param[out] *x_2 Указатель на 2 корень квадратного уравнения
\return Количество корней квадратного уравнения 
*/
solutions solve_equasion (const double coefficients[], double * x_1, double * x_2); //функция решения квадратного уравнения

/*!
Функция вывода корней квадратного уравнения и их количества, если количество корней квадратного уравнения NOT_VALID, то программа сообщит об этом.  
\param[in] x_1 Первый корень квадратного уравнения
\param[in] x_2 Второй корень квадратного уравнения
\param[in] number_solutions Количество корней квадратного уравнения
*/
void output_data (double x_1, double x_2, enum solutions number_solutions);//функция вывода

/*!
Функция решения квадратного уравнения, принимает 3 коэффицента квадратного уравнения и записывает корни по указателям x_1 и x_2. Если уравнение не имеет корней, то по указателям записывается 0. Если квадратное уравнение имеет 1 корень, то этот корень записывается по обоим указателям. Возвращаемое знанчение функции - количество корней квадратного уравнения.  
\param[in] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[out] *x_1 Указатель на 1 корень квадратного уравнения
\param[out] *x_2 Указатель на 2 корень квадратного уравнения
\return Количество корней квадратного уравнения 
*/
solutions solve_square (const double coefficients[], double * x_1, double * x_2);

/*!
Функция решения линейного уравнения, принимает 3 коэффицента уравнения и записывает корни по указателям x_1 и x_2. Если уравнение не имеет корней или бесконечно много корней, то по указателям записывается 0, иначе оно имеет 1 корень, который записывается по обоим указателям. Возвращаемое знанчение функции - количество корней уравнения.  
\param[in] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения, старший коэффицент которого 0
\param[out] *x_1 Указатель на 1 корень квадратного уравнения
\param[out] *x_2 Указатель на 2 корень квадратного уравнения
\return Количество корней уравнения 
*/
solutions solve_linear (const double coefficients[], double * x_1, double * x_2);

/*!
Функция считывания вводимых данных, их проверки и чистки буфера. Для чистки буфера вызывается функция flush_buffer. Вводимые коэффиценты должны быть числа с плавающей точкой, если ввод не верный, то программа попросит пользователя ввести данные ещё раз. После ввода каждого коэффицента буфер ввода очищается.   
\param[out] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
*/
double get_coefficent (int index);

/*!
Функция сравнения числа типа double с 0, если оно близко к 0, то возвращается true, иначе возвращается false.   
\param[in] number Число типа double, которое сравнивается с 0
\return true, если число 0 с точностью 1e-6, иначе false 
*/
bool check_zero (double number);//функция сравнивает значение double с 0

/*!
Функция сравнения двух чисел типа double, её особенность заключается в том, что если оба числа NAN, то она считает их равными и возвращает EQUAL. Если их нельзя сравнить между собой, например одно из них NAN, а другое нет, то возвращает NOT_COMPARE. Иначе она возвращает LESS, если 1 число меньше, чем 2 или MORE, в противном случае.  
\param[in] number_1 Число типа double, которое сравнивается с другим
\param[in] number_2 Число типа double, которое сравнивается с другим
\return enum compare. Если 2 числа равны, то возвращается EQUAL, если 1 число меньше, чем 2, то LESS или MORE, в противном случае. Если их нельзя сравнить между собой, то возвращается NOT_COMPARE  
*/
enum compare compare_number (double number_1, double number_2);

/*!
Функция подтверждения ввода, используется внутри функции input_data. Для подтверждения ввода необходимо ввести 'y', для того, чтобы ввести данные заново нужно ввести 'n'. Использует небуферизированный ввод. Будет работать до момента, пока пользователь не введёт 'y' или 'n'.
\return ANSI код 'y' или 'n' 
*/
int confirm_input ();

/*!
Функция очистки буфера ввода, испоьзуется внутри функции input_data.  
*/
void flush_buffer ();

/*!
Функция открывает файл, имя которого передаётся, как строка и проверяет, что он открылся без ошибок, после чего возвращает на него указатель.
\param[in] file_name[] Имя файла, который необходимо открыть.
\return Указатель на файл 
*/
FILE * check_isopen (const char file_name[]);

/*!
Функция, вызываемая в main.cpp, чтобы протестировать программу для решения квадратных уравнений, вызывает функции check_isopen, test_equasion и read_test.
*/
void test ();

/*!
Функция, вызываемая в функции test. Вызывает функцию solve_equasion, которая решает квадратное уравнения и возвращает решение, после чего функция сравнивает полученные данные с правильными и в зависимости совпали они или нет, вызывает функции print_test_failed или print_test_passed.
\param[in] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[in] x_1_correct Правильное значение 1 корня квадратного уравнения
\param[in] x_2_correct Правильное значение 2 корня квадратного уравнения
\param[in] number_solutions_correct Правильное значение количества корней
\param[in] index_test Индекс проходящего теста
*/
void test_equasion (const double coefficients[], double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, int index_test);

/*!
Функция, вызываемая в функции test. Читает данные (правильное значение 1 корня, правильное значение 2 корня и коэффицента крвадратного уравнения)из файла и возвращает их.
\param[out] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[out] *x_1_correct Правильное значение 1 корня квадратного уравнения
\param[out] *_2_correct Правильное значение 2 корня квадратного уравнения
\param[in] file_pointer Указатель на файл
*/
solutions read_test (double coefficients[], double * x_1_correct, double * x_2_correct, FILE * file_pointer);

/*!
Функция, вызываемая в функции test_equasion. Вызывается в случае, если тест провален, печатает данные проваленого теста, его номер, коэффиценты и ожидаемые данные.
\param[out] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[out] x_1_correct Правильное значение 1 корня квадратного уравнения
\param[out] x_2_correct Правильное значение 2 корня квадратного уравнения
\param[out] number_solutions_correct Правильное значение количества корней
\param[out] index_test Индекс проходящего теста
\param[out] x_1 Значение 1 корня, полученное после теста
\param[out] x_2 Значение 2 корня, полученное после теста
\param[out] number_solutions Количетсво корней, полученное после теста 
*/
void print_test_failed (const double coefficients[], double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, int index_test, enum solutions number_solutions, double x_1, double x_2);

/*!
Функция, вызываемая в функции test_equasion. Вызывается в случае, если тест прошёл успешно, печатает его номер и коэффиценты.
\param[out] coefficients[] Массив, содержащий 3 коэффицента крвадратного уравнения
\param[out] index_test Индекс проходящего теста
*/
void print_test_passed (const double coefficients[], int index_test);


#endif // SQUARESOLVER_H_INCLUDED