/*!
\file

\brief Header файл с прототипами функций, используемыми в тесте
*/

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "square_solver.h"

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
Функция, вызываемая в функции test_equasion. Вызывается для сравнения данных, считанных из файла с данными полученными после выполнения программы.
\param[in] x_1_correct Правильное значение 1 корня квадратного уравнения
\param[in] x_2_correct Правильное значение 2 корня квадратного уравнения
\param[in] number_solutions_correct Правильное значение количества корней
\param[in] x_1 Значение 1 корня, полученное после теста
\param[in] x_2 Значение 2 корня, полученное после теста
\param[in] number_solutions Количетсво корней, полученное после теста 
\return false, если данные не равны, иначе true
*/
bool compare_test_result (double x_1_correct, double x_2_correct, enum solutions number_solutions_correct, enum solutions number_solutions, double x_1, double x_2);

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

#endif // TEST_H_INCLUDED