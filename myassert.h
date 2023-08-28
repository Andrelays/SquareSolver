/*!
\file
\brief Header файл с макросом MYASSERT и списком возможных ошибок
*/

#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

/// Макрос, используемый для нахождения логических ошибкок, похож на assert, но в случае ошибки завершает функцию, а не программу, печатает файл, строку, функцию, в которой произошла ошибка и номер ошибки
#define MYASSERT(condition, error_code, finish)                                                                     \
 do {                                                                                                               \
    if (!(condition))                                                                                               \
    {                                                                                                               \
        printf(MAGENTA "ВНЕЗАПНО: Логическая ошибка: Код ошибки: %d\n", error_code);                                \
        printf("Файл: %s\n" "Строка: %d\n" "Функция: %s\n" RESET_COLOR, __FILE__, __LINE__, __PRETTY_FUNCTION__);   \
                                                                                                                    \
        finish;                                                                                                     \
    }                                                                                                               \
}  while(0)

/// Список возможных ошибок, которые печатает MYASSERT
enum errors_code {
    NON_FINITE_NUM_PASSED_TO_FUNC   = 1,///< Указывает, что в функцию было передано не конечное число
    NULL_POINTER_PASSED_TO_FUNC     = 2,///< Указывает, что в функцию был передан 0 указатель
    EQUAL_POINTERS_PASSED_TO_FUNC   = 3 ///< Указывает, что в функцию были переданы равные указатели
};


#endif // MYASSERT_H_INCLUDED
