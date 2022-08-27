#include <iostream>

template <typename T>
void ShowArray(const T array[], size_t array_size);

template <typename T>
void InitArray(T array[], size_t array_size);

template <typename T>
void BubbleSort(T array[], size_t array_size);

template <typename T>
void InsertSort(T array[], size_t array_size);

template <typename T>
void SelectSort(T array[], size_t array_size);

int main()
{
	const int size = 20;
	int array1[size];
	InitArray(array1, size);
	std::cout << "Array before Sort:\n";
	ShowArray(array1, size);
	InsertSort(array1, size);
	std::cout << "\nArray after InsertSort:\n";
	ShowArray(array1, size);



	return 0;
}

template <typename T>
void BubbleSort(T array[], size_t array_size)
{
	for (int i = 0; i < array_size - 1; ++i) {
		for (int j = array_size - 1; j > i; --j) {
			if (array[j] < array[j - 1]) {
				std::swap(array[j], array[j - 1]);
			}
		}
	}
}

template <typename T>
void ShowArray(const T array[], size_t array_size)
{
	for (int i = 0; i < array_size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void InitArray(T array[], size_t array_size)
{
	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 0; i < array_size; ++i) {
		array[i] = rand() % 100;
	}
}

template <typename T>
void InsertSort(T array[], size_t array_size)
{
	for (int i = 1; i < array_size; ++i) {
		int tmp = array[i];
		int j;
		for (j = i - 1; j >= 0 && array[j] > tmp; --j) {
			array[j + 1] = array[j];
		}
		array[j + 1] = tmp;
	}
}

template <typename T>
void SelectSort(T array[], size_t array_size)
{
	for (int i = 0; i < array_size; ++i) {
		for (int j = i; j < array_size; ++j) {
			if (array[i] > array[j]) {
				std::swap(array[i], array[j]);
			}
		}
	}
}
