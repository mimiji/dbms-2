#include "Header.h"

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
/**
 * \brief Функция удаления массива
 * \param Принимает указатель на массив
 */
void delete_values(char*& values);

int main()
{
	setlocale(LC_ALL, "Russian");

	int size = 0;
	cout << "Укажите размер массива: ";
	cin >> size;

	if (size <= 0)
	{
		cout << "Ошибка ввода размера!";
		return 1;
	}

	// Создаем массив
	char* values = input(size);
	// Выводим полученный массив
	cout << "Полученный массив:\n" << out_values(values, size);
	// Выводим максимальный элемент
	cout << "\nМаксимальный элемент массива: " << find_max(values, size) << endl;
	// Удаляем массив
	delete_values(values);

	return 0;
}

char* input(const size_t size)
{
	char* values = new char[size];

	const size_t min_range = 0;
	const size_t max_range = 26;

	random_device rd;
	mt19937 gen(rd());
	const uniform_int_distribution<> uniformIntDistribution(min_range, max_range);

	for (size_t i = 0; i < size; i++)
	{
		const size_t temp = uniformIntDistribution(gen);
		values[i] = temp + 'a';
	}

	return values;
}

string out_values(char* values, const size_t size)
{
	ostringstream tmpStream;
	for (size_t i = 0; i < size - 1; i++)
	{
		tmpStream << values[i] << "\t";
	}
	tmpStream << values[size - 1];

	return tmpStream.str();
}

char find_max(char* values, const size_t size)
{
	size_t maximum = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (values[i] > maximum)
			maximum = values[i];
	}

	return maximum;
}

void delete_values(char*& values)
{
	if (values != nullptr)
	{
		delete[] values;
		values = nullptr;
	}
}