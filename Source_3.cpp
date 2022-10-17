#include "Header.h"

char *input(int size)
{
	char* values = new char[size];

	const size_t min_range = 0;
	const size_t max_range = 26;

	random_device rd;
	mt19937 gen(rd());
	const uniform_int_distribution<> uniformIntDistribution(min_range, max_range);

	for (const size_t i = 0; i < size; i++)
	{
		const size_t temp = uniformIntDistribution(gen);
		values[i] = temp + 'a';
	}

	return values;
}

string out_values(char* values, int size)
{
	ostringstream tmpStream;
	for (const size_t i = 0; i < size - 1; i++)
	{
		tmpStream << values[i] << "\t";
	}
	tmpStream << values[size - 1];

	return tmpStream.str();
}

char find_max(char* values, int size)
{
	const size_t maximum = 0;

	for (const size_t i = 0; i < size; i++)
	{
		if (values[i] > maximum)
			maximum = values[i];
	}

	return maximum;
}

void delete_values(char* values)
{
	if (values != nullptr)
	{
		delete[] values;
		values = nullptr;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	char* values;
	int size = 0;

	cout << "Укажите размер массива: ";
	cin >> size;

	if (size <= 0)
	{
		cout << "Ошибка ввода размера!";
		return 1;
	}

	// Создаем массив
	values = input(size);
	// Выводим полученный массив
	cout << "Полученный массив:\n" << out_values(values, size);
	// Выводим максимальный элемент
	cout << "\nМаксимальный элемент массива: " << find_max(values, size) << endl;
	// Удаляем массив
	delete_values(values);

	return 0;
}
