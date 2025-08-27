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

    int count{};
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
    if (size == 0)
    {
        return nullptr;
    }

    std::ifstream textFile(nameIn);
    CheckInputFile(textFile);

    Student* students = new Student[size];
    std::string line;
    int index{};

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

    size_t surnameLength = student.surname.length();
    binFile.write((char*)(&surnameLength), sizeof(surnameLength));
    binFile.write(student.surname.c_str(), surnameLength);

    size_t nameLength = student.name.length();
    binFile.write((char*)(&nameLength), sizeof(nameLength));
    binFile.write(student.name.c_str(), nameLength);

    size_t patronymicLength = student.patronymic.length();
    binFile.write((char*)(&patronymicLength), sizeof(patronymicLength));
    binFile.write(student.patronymic.c_str(), patronymicLength);
}

void TextToBinStruct(std::string nameIn, std::string nameOut)
{
    int size;
    Student* students = ReadStudentsFromText(nameIn, size);

    if (students == nullptr)
    {
        std::cout << "No students found in the text file!" << '\n';
        return;
    }

    std::ofstream binFile(nameOut, std::ios::binary);
    CheckOutputFile(binFile);

    binFile.write((char*)(&size), sizeof(size));
    for (int i{}; i < size; ++i)
    {
        WriteStudent(binFile, students[i]);
    }
    binFile.close();
    delete[] students;
}

StudentCard* ReadStudentsCardFromText(std::string nameIn, int& size)
{
    size = CountStudents(nameIn);
    if (size == 0)
    {
        return nullptr;
    }

    std::ifstream textFile(nameIn);
    CheckInputFile(textFile);

    StudentCard* studentCards = new StudentCard[size];
    std::string line;
    int index{};

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
                studentCards[index].groop = std::stoi(token);
                break;
            case 1:
                studentCards[index].id = std::stoi(token);
                break;
            case 2:
                studentCards[index].firstSubject = token;
                break;
            case 3:
                studentCards[index].firstMark = std::stoi(token);
                break;
            case 4:
                studentCards[index].secondSubject = token;
                break;
            case 5:
                studentCards[index].secondMark = std::stoi(token);
                break;
            case 6:
                studentCards[index].thirdSubject = token;
                break;
            }

            line.erase(0, pos + 1);
            field++;
        }
        if (field == 7)
        {
            studentCards[index].thirdMark = std::stoi(line);
        }

        index++;
    }

    textFile.close();
    return studentCards;
}

void WriteStudentCard(std::ofstream& binFile, const StudentCard& studentCard)
{
    binFile.write((char*)(&studentCard.groop), sizeof(studentCard.groop));

    binFile.write((char*)(&studentCard.id), sizeof(studentCard.id));

    size_t firstSubjectLength = studentCard.firstSubject.length();
    binFile.write((char*)(&firstSubjectLength), sizeof(firstSubjectLength));
    binFile.write(studentCard.firstSubject.c_str(), firstSubjectLength);

    binFile.write((char*)(&studentCard.firstMark), sizeof(studentCard.firstMark));

    size_t secondSubjectLength = studentCard.secondSubject.length();
    binFile.write((char*)(&secondSubjectLength), sizeof(secondSubjectLength));
    binFile.write(studentCard.secondSubject.c_str(), secondSubjectLength);

    binFile.write((char*)(&studentCard.secondMark), sizeof(studentCard.secondMark));

    size_t thirdSubjectLength = studentCard.thirdSubject.length();
    binFile.write((char*)(&thirdSubjectLength), sizeof(thirdSubjectLength));
    binFile.write(studentCard.thirdSubject.c_str(), thirdSubjectLength);

    binFile.write((char*)(&studentCard.thirdMark), sizeof(studentCard.thirdMark));
}

void TextToBinStudentsCards(std::string nameIn, std::string nameOut)
{
    int size;
    StudentCard* studentsCards = ReadStudentsCardFromText(nameIn, size);

    if (studentsCards == nullptr)
    {
        std::cout << "No one student card!" << '\n';
        return;
    }

    std::ofstream binFile(nameOut, std::ios::binary);
    CheckOutputFile(binFile);

    binFile.write((char*)(&size), sizeof(size));
    for (int i{}; i < size; ++i)
    {
        WriteStudentCard(binFile, studentsCards[i]);
    }

    binFile.close();
    delete[] studentsCards;
}
