#include <iostream>
#include <random>
#include <sstream>

using namespace std;

/**
 * \brief Функция заполнения массива случайными значениями
 * \param Принимает размер длины массива
 * \return. Возвращает указатель на char
 */
char* input(const size_t size);

/**
 * \brief Функция вывода массива
 * \param Принимает указатель на массив и его размер
 */
string out_values(char* values, const size_t size);

/**
 * \brief Функция нахождения максимального элемента массива
 * \param Принимает указатель на массив и его размер
 * \return. Возвращает максимальный элемент массива
 */
char find_max(char* values, const size_t size);