#include"function.h"

void CheckInputFile(std::ifstream& fin)
{
    if(!fin.is_open())
    {
        throw std::runtime_error("Binary file couldn't be opened!");
    }
    if(fin.fail())
    {
        throw std::runtime_error("Input binary file error!");
    }
    if(fin.bad())
    {
        throw std::runtime_error("Critical error with binary file!");
    }
    if(fin.peek() == EOF)
    {
        throw std::runtime_error("Binary file is empty!");
    }
}

void CheckOutputFile(std::ofstream& fout)
{
    if(!fout.is_open())
    {
        throw std::runtime_error("Binary file couldn't be opened for writing!");
    }
    if(fout.fail())
    {
        throw std::runtime_error("Output binary file error!");
    }
    if(fout.bad())
    {
        throw std::runtime_error("Critical error with output binary file!");
    }
}

int CountStudents(std::string nameIn)
{
    std::ifstream textFile(nameIn);
    CheckInputFile(textFile);

    int count = 0;
    std::string line;
    while (std::getline(textFile, line))
    {
        if (!line.empty() && line.find(';') != std::string::npos)
        {
            count++;
        }
    }

    textFile.close();
    return count;
}

Student* ReadStudentsFromText(std::string nameIn, int& size)
{
    size = CountStudents(nameIn);
    if (size == 0) {
        return nullptr;
    }

    std::ifstream textFile(nameIn);
    CheckInputFile(textFile);

    Student* students = new Student[size];
    std::string line;
    int index = 0;

    while (std::getline(textFile, line) && index < size)
        {
        if (line.empty() || line.find(';') == std::string::npos)
        {
            continue;
        }
        size_t pos{};
        int field{};
        std::string token;

        while ((pos = line.find(';')) != std::string::npos)
        {
            token = line.substr(0, pos);
            switch (field)
            {
                case 0:
                    students[index].id = std::stoi(token);
                    break;
                case 1:
                    students[index].surname = token;
                    break;
                case 2:
                    students[index].name = token;
                    break;
            }

            line.erase(0, pos + 1);
            field++;
        }
        if (field == 3)
        {
            students[index].patronymic = line;
        }

        index++;
    }

    textFile.close();
    return students;
}

void WriteStudent(std::ofstream& binFile, const Student& student)
{
    binFile.write((char*)(&student.id), sizeof(student.id));

    size_t surnameLength = student.surname.size();
    binFile.write((char*)(&surnameLength), sizeof(surnameLength));
    binFile.write(student.surname.c_str(), surnameLength);

    size_t nameLength = student.name.size();
    binFile.write((char*)(&nameLength), sizeof(nameLength));
    binFile.write(student.name.c_str(), nameLength);

    size_t patronymicLength = student.patronymic.size();
    binFile.write((char*)(&patronymicLength), sizeof(patronymicLength));
    binFile.write(student.patronymic.c_str(), patronymicLength);
}

void TextToBin(std::string nameIn, std::string nameOut)
{
    int size;
    Student* students = ReadStudentsFromText(nameIn, size);

    if (students == nullptr)
    {
        std::cout << "No students found in the text file." << std::endl;
        return;
    }

    std::ofstream binFile(nameOut, std::ios::binary);
    CheckOutputFile(binFile);

    binFile.write((char*)(&size), sizeof(size));
    for (int i = 0; i < size; ++i)
    {
        WriteStudent(binFile, students[i]);
    }

    binFile.close();
    delete[] students;
}