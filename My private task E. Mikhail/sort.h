#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Student 
{
    int course{};
    int group{};
    std::string fio{};
    int marks[3]{};
};

inline std::ostream& operator<<(std::ostream& outputStream, const Student& student) 
{
    outputStream << "{" << student.course << "," << student.group << "," << student.fio << "," 
                 << student.marks[0] << "," << student.marks[1] << "," << student.marks[2] << "}";
    return outputStream;
}

bool CompareInt(const int& first, const int& second);
bool CompareDouble(const double& first, const double& second);
bool CompareChar(const char& first, const char& second);
bool CompareString(const std::string& first, const std::string& second);
bool CompareStudent(const Student& first, const Student& second);

template <typename T>
void PrintArray(T array[], int size) 
{
    for (int index{}; index < size; ++index) 
    {
        std::cout << array[index] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PrintExtra(T array[], int size) 
{
    // заглушка
    // (void)array; 
    // (void)size; 
}

inline void PrintExtra(char array[], int size) 
{
    std::cout << "Строка: ";
    for (int index{}; index < size; ++index) 
    {
        std::cout << array[index];
    }
    std::cout << std::endl;
}

inline void PrintExtra(std::string array[], int size) 
{
    std::cout << "Соединённая строка: ";
    for (int index{}; index < size; ++index) 
    {
        if (index) 
        {
            std::cout << ' ';
        }
        std::cout << array[index];
    }
    std::cout << std::endl;
}

inline void PrintExtra(Student array[], int size) 
{
    std::cout << "\nДетальный список студентов:\n";
    for (int index{}; index < size; ++index) 
    {
        std::cout << "  (курс=" << array[index].course << ", гр=" << array[index].group << ") "
                  << array[index].fio << "  (" << array[index].marks[0] << "," 
                  << array[index].marks[1] << "," << array[index].marks[2] << ")\n";
    }
}

template <typename T>
void BubbleSort(T array[], int size, bool (*compare)(const T&, const T&)) 
{
    std::cout << "\nПошаговое выполнение Bubble Sort:\n";
    for (int outerIndex{}; outerIndex < size - 1; ++outerIndex) 
    {
        for (int innerIndex{}; innerIndex < size - outerIndex - 1; ++innerIndex) 
        {
            if (compare(array[innerIndex], array[innerIndex + 1])) 
            {
                T temporary = array[innerIndex]; 
                array[innerIndex] = array[innerIndex + 1]; 
                array[innerIndex + 1] = temporary;
            }
        }
        std::cout << "Итерация " << outerIndex + 1 << ": ";
        PrintArray(array, size);
        PrintExtra(array, size);
    }
}

template <typename T>
int Partition(T array[], int low, int high, bool (*compare)(const T&, const T&), int size) 
{
    T pivot = array[high];
    int index = low - 1;

    for (int j = low; j < high; ++j) 
    {
        if (compare(pivot, array[j])) 
        {
            ++index;
            T temporary = array[index]; 
            array[index] = array[j]; 
            array[j] = temporary;
        }
    }

    T temporary = array[index + 1]; 
    array[index + 1] = array[high]; 
    array[high] = temporary;

    std::cout << "Разделение (pivot=" << pivot << "): ";
    PrintArray(array, size);
    PrintExtra(array, size);

    return index + 1;
}

template <typename T>
void QuickSort(T array[], int low, int high, bool (*compare)(const T&, const T&), int size) 
{
    if (low < high) 
    {
        int partitionIndex = Partition(array, low, high, compare, size);
        QuickSort(array, low, partitionIndex - 1, compare, size);
        QuickSort(array, partitionIndex + 1, high, compare, size);
    }
}

template <typename T>
void SelectionSort(T array[], int size, bool (*compare)(const T&, const T&))
{
    std::cout << "\nПошаговое выполнение Selection Sort:\n";
    for (int i{0}; i < size - 1; ++i)
    {
        int minIndex{i};
        for (int j{i + 1}; j < size; ++j)
        {
            if (compare(array[minIndex], array[j]))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            T tempElement{array[i]};
            array[i] = array[minIndex];
            array[minIndex] = tempElement;
        }

        std::cout << "Итерация " << i + 1 << ": ";
        PrintArray(array, size);
        PrintExtra(array, size);
    }
}

template <typename T>
void InsertionSort(T array[], int size, bool (*compare)(const T&, const T&))
{
    std::cout << "\nПошаговое выполнение Insertion Sort:\n";
    for (int i{1}; i < size; ++i)
    {
        T key{array[i]};
        int j{i - 1};

        while (j >= 0 && compare(array[j], key))
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;

        std::cout << "Итерация " << i << ": ";
        PrintArray(array, size);
        PrintExtra(array, size);
    }
}
