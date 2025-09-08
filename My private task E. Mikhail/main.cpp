#include "sort.h"

void PrintStudent(const Student& student)
{
    std::cout << "Курс: " << student.course
              << ", Группа: " << student.group
              << ", ФИО: " << student.fio
              << ", Оценки: "
              << student.marks[0] << " "
              << student.marks[1] << " "
              << student.marks[2] << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int mode{};
    std::cout << "Выберите режим:\n"
              << "1 - Ввод вручную и запись в файл\n"
              << "2 - Генерация случайных данных и запись в файл\n"
              << "3 - Чтение из файла и сортировка\n";
    std::cin >> mode;

    int dataType{};
    std::cout << "Выберите тип данных:\n"
              << "1 - int\n"
              << "2 - double\n"
              << "3 - char\n"
              << "4 - string\n"
              << "5 - Student\n";
    std::cin >> dataType;

    int algorithm{};
    std::cout << "Выберите алгоритм сортировки:\n"
              << "1 - Bubble Sort\n"
              << "2 - Quick Sort\n"
              << "3 - Selection Sort\n"
              << "4 - Insertion Sort\n";
    std::cin >> algorithm;

    int count{};
    std::cout << "Введите количество элементов: ";
    std::cin >> count;

    switch (dataType)
    {
    case 1: // int
    {
        int* array = new int[count]{};
        switch (mode)
        {
        case 1:
        {
            std::ofstream outputFile("data.txt");
            std::cout << "Введите " << count << " целых чисел:\n";
            for (int i{}; i < count; ++i)
            {
                std::cin >> array[i];
                outputFile << array[i] << " ";
            }
            outputFile.close();
            break;
        }
        case 2:
        {
            std::ofstream outputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                array[i] = std::rand() % 100;
                outputFile << array[i] << " ";
            }
            outputFile.close();
            std::cout << "Сгенерировано и сохранено в data.txt\n";
            break;
        }
        case 3:
        {
            std::ifstream inputFile("data.txt");
            for (int i{}; i < count; ++i) inputFile >> array[i];
            inputFile.close();

            if (algorithm == 1) BubbleSort(array, count, CompareInt);
            else if (algorithm == 2) QuickSort(array, 0, count - 1, CompareInt, count);
            else if (algorithm == 3) SelectionSort(array, count, CompareInt);
            else if (algorithm == 4) InsertionSort(array, count, CompareInt);

            std::cout << "\nОтсортированный массив:\n";
            PrintArray(array, count);
            break;
        }
        }
        delete[] array;
        break;
    }

    case 2: // double
    {
        double* array = new double[count]{};
        switch (mode)
        {
        case 1:
        {
            std::ofstream outputFile("data.txt");
            std::cout << "Введите " << count << " чисел с плавающей точкой:\n";
            for (int i{}; i < count; ++i)
            {
                std::cin >> array[i];
                outputFile << array[i] << " ";
            }
            outputFile.close();
            break;
        }
        case 2:
        {
            std::ofstream outputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                array[i] = static_cast<double>(std::rand() % 1000) / 10.0;
                outputFile << array[i] << " ";
            }
            outputFile.close();
            std::cout << "Сгенерировано и сохранено в data.txt\n";
            break;
        }
        case 3:
        {
            std::ifstream inputFile("data.txt");
            for (int i{}; i < count; ++i) inputFile >> array[i];
            inputFile.close();

            if (algorithm == 1) BubbleSort(array, count, CompareDouble);
            else if (algorithm == 2) QuickSort(array, 0, count - 1, CompareDouble, count);
            else if (algorithm == 3) SelectionSort(array, count, CompareDouble);
            else if (algorithm == 4) InsertionSort(array, count, CompareDouble);

            std::cout << "\nОтсортированный массив:\n";
            PrintArray(array, count);
            break;
        }
        }
        delete[] array;
        break;
    }

    case 3: // char
    {
        char* array = new char[count]{};
        switch (mode)
        {
        case 1:
        {
            std::ofstream outputFile("data.txt");
            std::cout << "Введите " << count << " символов:\n";
            for (int i{}; i < count; ++i)
            {
                std::cin >> array[i];
                outputFile << array[i] << " ";
            }
            outputFile.close();
            break;
        }
        case 2:
        {
            std::ofstream outputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                array[i] = 'A' + std::rand() % 26;
                outputFile << array[i] << " ";
            }
            outputFile.close();
            std::cout << "Сгенерировано и сохранено в data.txt\n";
            break;
        }
        case 3:
        {
            std::ifstream inputFile("data.txt");
            for (int i{}; i < count; ++i) inputFile >> array[i];
            inputFile.close();

            if (algorithm == 1) BubbleSort(array, count, CompareChar);
            else if (algorithm == 2) QuickSort(array, 0, count - 1, CompareChar, count);
            else if (algorithm == 3) SelectionSort(array, count, CompareChar);
            else if (algorithm == 4) InsertionSort(array, count, CompareChar);

            std::cout << "\nОтсортированная последовательность символов:\n";
            PrintArray(array, count);
            PrintExtra(array, count);
            break;
        }
        }
        delete[] array;
        break;
    }

    case 4: // string
    {
        std::string* array = new std::string[count]{};
        switch (mode)
        {
        case 1:
        {
            std::ofstream outputFile("data.txt");
            std::cout << "Введите " << count << " строк:\n";
            for (int i{}; i < count; ++i)
            {
                std::cin >> array[i];
                outputFile << array[i] << " ";
            }
            outputFile.close();
            break;
        }
        case 2:
        {
            std::ofstream outputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                array[i] = "str" + std::to_string(std::rand() % 100);
                outputFile << array[i] << " ";
            }
            outputFile.close();
            std::cout << "Сгенерировано и сохранено в data.txt\n";
            break;
        }
        case 3:
        {
            std::ifstream inputFile("data.txt");
            for (int i{}; i < count; ++i) inputFile >> array[i];
            inputFile.close();

            if (algorithm == 1) BubbleSort(array, count, CompareString);
            else if (algorithm == 2) QuickSort(array, 0, count - 1, CompareString, count);
            else if (algorithm == 3) SelectionSort(array, count, CompareString);
            else if (algorithm == 4) InsertionSort(array, count, CompareString);

            std::cout << "\nОтсортированный массив строк:\n";
            PrintArray(array, count);
            PrintExtra(array, count);
            break;
        }
        }
        delete[] array;
        break;
    }

    case 5: // Student
    {
        Student* array = new Student[count]{};
        switch (mode)
        {
        case 1:
        {
            std::ofstream outputFile("data.txt");
            std::cout << "Введите данные для " << count << " студентов:\n";
            for (int i{}; i < count; ++i)
            {
                std::cin >> array[i].course
                         >> array[i].group
                         >> array[i].fio
                         >> array[i].marks[0]
                         >> array[i].marks[1]
                         >> array[i].marks[2];
                outputFile << array[i].course << ' '
                           << array[i].group << ' '
                           << array[i].fio << ' '
                           << array[i].marks[0] << ' '
                           << array[i].marks[1] << ' '
                           << array[i].marks[2] << '\n';
            }
            outputFile.close();
            break;
        }
        case 2:
        {
            std::ofstream outputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                array[i].course = 1 + std::rand() % 4;
                array[i].group = 100 + std::rand() % 10;
                array[i].fio = "Stud" + std::to_string(i);
                array[i].marks[0] = 2 + std::rand() % 4;
                array[i].marks[1] = 2 + std::rand() % 4;
                array[i].marks[2] = 2 + std::rand() % 4;

                outputFile << array[i].course << ' '
                           << array[i].group << ' '
                           << array[i].fio << ' '
                           << array[i].marks[0] << ' '
                           << array[i].marks[1] << ' '
                           << array[i].marks[2] << '\n';
            }
            outputFile.close();
            std::cout << "Сгенерировано и сохранено в data.txt\n";
            break;
        }
        case 3:
        {
            std::ifstream inputFile("data.txt");
            for (int i{}; i < count; ++i)
            {
                inputFile >> array[i].course
                          >> array[i].group
                          >> array[i].fio
                          >> array[i].marks[0]
                          >> array[i].marks[1]
                          >> array[i].marks[2];
            }
            inputFile.close();

            if (algorithm == 1) BubbleSort(array, count, CompareStudent);
            else if (algorithm == 2) QuickSort(array, 0, count - 1, CompareStudent, count);
            else if (algorithm == 3) SelectionSort(array, count, CompareStudent);
            else if (algorithm == 4) InsertionSort(array, count, CompareStudent);

            std::cout << "\nОтсортированный список студентов:\n";
            for (int i{}; i < count; ++i) PrintStudent(array[i]);
            break;
        }
        }
        delete[] array;
        break;
    }

    default:
        std::cout << "Неверный выбор типа данных!" << std::endl;
    }

    return 0;
}
