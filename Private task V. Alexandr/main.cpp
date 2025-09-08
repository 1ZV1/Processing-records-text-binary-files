#include<iostream>
#include<algorithm>
#include <random>
#include <string>
#include <fstream>

void InputSize(int32_t& size);
void CheckSize(int32_t size);
void InputDataType(int32_t& dataType);
void CheckDataType(int32_t dataType);
void RandomGenerationDouble(double* array, int32_t size);
void RandomGenerationInt(double* array, int32_t size);
void InputMethod(double* array, int32_t size);
void InputString(std::string* array, int32_t size);
void ChooseMethods(int32_t& Method_Sort);
void InputMethods(int32_t& size);
void CheckMethods(int32_t size);
template<typename T>
void OutputArray(T* array, int32_t size);
template<typename T>
void BubbleSort(T* array, int32_t size);
template<typename T>
void ShakerSort(T* array, int32_t size);
template<typename T>
void CombSort(T* array, int32_t size);
template<typename T>
void InsertionSort(T* array, int32_t size);
template<typename T>
void SelectionSort(T* array, int32_t size);
template<typename T>
void QuickSort(T* array, int32_t size);
template<typename T>
void Merge(T* array, int32_t left, int32_t mid, int32_t right);
template<typename T>
void MergeSort(T* array, int32_t left, int32_t right);
template<typename T>
bool IsSorted(T* array, int32_t size);
template<typename T>
void BogoSort(T* array, int32_t size);
template<typename T>
void Sorting(T* array, int32_t size, int32_t Method_Sort);



int main()
{
	try
	{
		int32_t size{};
		InputSize(size);
		CheckSize(size);
		int32_t dataType{};
		InputDataType(dataType);
		CheckDataType(dataType);
		if (dataType == 0)
		{
			double* array = new double[size];
			int32_t Method_Sort{};
			InputMethod(array, size);
			ChooseMethods(Method_Sort);
			Sorting(array, size, Method_Sort);
			OutputArray(array, size);
			delete[] array;
		}
		else if (dataType == 1)
		{
			std::string* array = new std::string[size];
			int32_t Method_Sort{};
			InputString(array, size);
			ChooseMethods(Method_Sort);
			Sorting(array, size, Method_Sort);
			OutputArray(array, size);
			delete[] array;
		}

	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return 0;
	}
	return 0;
}


void InputSize(int32_t& size)
{
	std::cout << "Input size of array\n";
	std::cin >> size;
}

void CheckSize(int32_t size)
{
	if (size < 0 && size > 101)
	{
		throw std::runtime_error("Mistake in input size \n");
	}
}

void InputMethod(int32_t& Method_Sort)
{
	std::cout << "Input size of array\n";
	std::cin >> Method_Sort;
}

void CheckMethod(int32_t Method_Sort)
{
	if (Method_Sort < 0 && Method_Sort > 7)
	{
		throw std::runtime_error("Mistake in input Method \n");
	}
}

void InputDataType(int32_t& dataType)
{
	std::cout << "Select data type: 0 - numbers, 1 - strings\n";
	std::cin >> dataType;
}

void CheckDataType(int32_t dataType)
{
	if (!(dataType == 1 || dataType == 0))
	{
		throw std::runtime_error("Mistake in input dataType \n");
	}
}

void RandomGenerationInt(double* array, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>dist(-500, 1000);
	for (int32_t i{}; i < size; ++i)
	{
		array[i] = dist(gen);
		std::cout << array[i] << " ";
	}
}

void RandomGenerationDouble(double* array, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<>dist(-500, 1000);
	for (int32_t i{}; i < size; ++i)
	{
		array[i] = dist(gen);
		std::cout << array[i] << " ";
	}
}

void InputMethod(double* array, int32_t size)
{
	int32_t Method_filling{};
	int32_t type_of_numbers;
	std::cout << "What kind of filling array will use\n";
	std::cout << "Random(0) or handmade(1) \n";
	std::cin >> Method_filling;
	if (Method_filling == 0)
	{
		std::cout << "Double(0) or integers(1)\n";
		std::cin >> type_of_numbers;
		if (type_of_numbers == 0)
		{

			RandomGenerationDouble(array, size);
			std::cout << '\n';

		}
		else
		{
			RandomGenerationInt(array, size);
			std::cout << '\n';
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "Input your elements\n";
		for (int32_t i{}; i < size; ++i)
		{
			std::cin >> array[i];
			std::cout << array[i] << " ";
		}
		std::cout << '\n';
	}
}

void InputString(std::string* array, int32_t size)
{
	std::cout << "Input your string\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int32_t i{}; i < size; ++i)
	{
		std::getline(std::cin, array[i]);
	}
	std::cout << '\n';
}

void ChooseMethods(int32_t& Method_Sort)
{
	std::cout << "Choose the sorting method\n\n";
	std::cout << "Bubble Sort  - 0\n";
	std::cout << "Cocktail Shaker Sort - 1\n";
	std::cout << "Comb Sort  - 2\n";
	std::cout << "Insertion Sort- 3\n";
	std::cout << "Selection Sort - 4\n";
	std::cout << "Quick Sort - 5\n";
	std::cout << "Merge Sort  - 6\n";
	std::cout << "BogoSort - 7\n";

	InputMethod(Method_Sort);
	CheckMethod(Method_Sort);

}

template<typename T>
void OutputArray(T* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << '\n';
}

template<typename T>
void BubbleSort(T* array, int32_t size)
{
	std::cout << "Start sort " << '\n';
	for (int32_t i{}; i < size - 1; ++i)
	{
		bool swapped = false;
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				swapped = true;
				std::cout << " Changed elements in positions " << j << " and " << (j + 1) << ": ";
				OutputArray(array, size);
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

template<typename T>
void ShakerSort(T* array, int32_t size)
{
	
	int32_t left{};
	int32_t right = size - 1;
	while (left < right)
	{
		for (int32_t i = left; i < right; ++i)
		{
			if (array[i] > array[i + 1])
			{
				std::swap(array[i], array[i + 1]);
			}
		}
		--right;

		for (int32_t i = right; i > left; --i)
		{
			if (array[i] < array[i - 1])
			{
				std::swap(array[i], array[i - 1]);
			}
		}
		++left; 
	}
}

template<typename T>
void CombSort(T* array, int32_t size)
{
	int32_t gap = size;
	bool swapped = true;

	while (gap > 1 || swapped)
	{
		gap = std::max(1, (gap * 10) / 13);
		swapped = false;

		for (int32_t i{}; i < size - gap; ++i)
		{
			if (array[i] > array[i + gap])
			{
				std::swap(array[i], array[i + gap]);
				swapped = true;
			}
		}
	}
}

template<typename T>
void InsertionSort(T* array, int32_t size)
{
	for (int32_t i{1}; i < size; ++i) 
	{
		T key = array[i];
		int32_t j = i - 1;	

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}


template<typename T>
void SelectionSort(T* array, int32_t size)
{
	for (int32_t i{}; i < size - 1; ++i)
	{
		int32_t min_idx = i;

		for (int32_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}               
		}
		std::swap(array[i], array[min_idx]);
	}
}

template<typename T>
void QuickSort(T* array, int32_t size)
{
	if (size <= 1)
	{
		return;
	}
	int32_t left{};
	int32_t right = size - 1;
	T pivot = array[size / 2];

	while (left <= right)
	{
		while (array[left] < pivot)
		{
			++left;
		}
		while (array[right] > pivot)
		{
			--right;
		}

		if (left <= right)
		{
			std::swap(array[left], array[right]);
			++left;
			--right;
		}
	}

	QuickSort(array, right + 1);
	QuickSort(array + left, size - left);
}

template<typename T>
void Merge(T* array, int32_t left, int32_t mid, int32_t right)
{
	int32_t size1 = mid - left + 1;
	int32_t size2 = right - mid;

	
	T* left_arr = new T[size1];
	T* right_arr = new T[size2];

	for (int32_t i{}; i < size1; i++)
	{
		left_arr[i] = array[left + i];
	}
	for (int32_t j{}; j < size2; j++)
	{
		right_arr[j] = array[mid + 1 + j];
	}


	int32_t i{};
	int32_t j{};
	int32_t k = left;

	while (i < size1 && j < size2)
	{
		if (left_arr[i] <= right_arr[j])
		{
			array[k] = left_arr[i];
			++i;
		}
		else
		{
			array[k] = right_arr[j];
			++j;
		}
		++k;
	}

	while (i < size1)
	{
		array[k] = left_arr[i];
		++i;
		++k;
	}

	while (j < size2)
	{
		array[k] = right_arr[j];
		++j;
		++k;
	}

	delete[] left_arr;
	delete[] right_arr;

	OutputArray(array + left, right - left + 1);
}

template<typename T>
void MergeSort(T* array, int32_t left, int32_t right)
{
	if (left < right)
	{
		int32_t mid = left + (right - left) / 2;

		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);

		Merge(array, left, mid, right);
	}
}


template<typename T>
bool IsSorted(T* array, int32_t size)
{
	for (int32_t i{}; i < size - 1; ++i)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

template<typename T>
void BogoSort(T* array, int32_t size)
{
	std::random_device rd;
	std::mt19937 g(rd());
	int32_t counter{};
	while (!IsSorted(array, size))
	{
		std::shuffle(array, array + size, g);
	}
}

template<typename T>
void Sorting(T* array, int32_t size, int32_t Method_Sort)
{
	switch (Method_Sort)
	{
	case 0:
		BubbleSort(array, size);
		break;
	case 1:
		ShakerSort(array, size);
		break;
	case 2:
		CombSort(array, size);
		break;
	case 3:
		InsertionSort(array, size);
		break;
	case 4:
		SelectionSort(array, size);
		break;
	case 5:
		QuickSort(array, size);
		break;
	case 6:
		MergeSort(array, 0, size - 1);
		break;
	case 7:
		BogoSort(array, size);
		break;
	}
}
