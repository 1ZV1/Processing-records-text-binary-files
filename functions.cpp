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

void writeStudent(std::ofstream& fout, const Student& student)
{
    fout.write((const char*)(&student.id), sizeof(student.id));

    int length = static_cast<int>(student.surname.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.surname.c_str(), length);

    length = static_cast<int>(student.name.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.name.c_str(), length);

    length = static_cast<int>(student.patronymic.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.patronymic.c_str(), length);
}

void readStudent(std::ifstream& fin, Student& student)
{
    fin.read((char*)(&student.id), sizeof(student.id));

    int length;
    char* buffer;

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    student.surname = std::string(buffer, length);
    delete[] buffer;

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    student.name = std::string(buffer, length);
    delete[] buffer;

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    student.patronymic = std::string(buffer, length);
    delete[] buffer;
}

void textToBinaryStudents(const std::string& textFileName, const std::string& binaryFileName)
{
    std::ifstream textFile(textFileName);
    CheckInputFile(textFile);

    std::ofstream binaryFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binaryFile);

    std::string line;
    while (std::getline(textFile, line))
    {
        std::stringstream stringstream(line);
        Student student;
        std::string token;

        std::getline(stringstream, token, ';');
        student.id = std::stoi(token);

        std::getline(stringstream, student.surname, ';');
        std::getline(stringstream, student.name, ';');
        std::getline(stringstream, student.patronymic, ';');

        writeStudent(binaryFile, student);
    }

    textFile.close();
    binaryFile.close();
}

int countStudentsInTextFile(const std::string& textFileName)
{
    std::ifstream file(textFileName);
    CheckInputFile(file);
    int count{};
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            ++count;
        }
    }
    file.close();
    return count;
}

void BinToStudent(Student* students, int size, const std::string& binaryFileName)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    CheckInputFile(binFile);

    for (int i{}; i < size; ++i)
    {
        readStudent(binFile, students[i]);
    }

    binFile.close();
}

void writeStudentCard(std::ofstream& fout, const StudentCard& studentCard)
{
    fout.write((const char*)(&studentCard.group), sizeof(studentCard.group));

    fout.write((const char*)(&studentCard.id), sizeof(studentCard.id));

    int length = static_cast<int>(studentCard.firstSubject.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.firstSubject.c_str(), length);
    fout.write((const char*)(&studentCard.firstMark), sizeof(studentCard.firstMark));

    length = static_cast<int>(studentCard.secondSubject.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.secondSubject.c_str(), length);
    fout.write((const char*)(&studentCard.secondMark), sizeof(studentCard.secondMark));

    length = static_cast<int>(studentCard.thirdSubject.length());
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.thirdSubject.c_str(), length);
    fout.write((const char*)(&studentCard.thirdMark), sizeof(studentCard.thirdMark));

}

void readStudentCard(std::ifstream& fin, StudentCard& studentCard)
{
    fin.read((char*)(&studentCard.group), sizeof(studentCard.group));
    fin.read((char*)(&studentCard.id), sizeof(studentCard.id));

    int length;

    fin.read((char*)(&length), sizeof(length));
    char* buffer = new char[length + 1];
    fin.read(buffer, length);
    buffer[length] = '\0';
    studentCard.firstSubject = buffer;
    delete[] buffer;

    fin.read((char*)(&studentCard.firstMark), sizeof(studentCard.firstMark));

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length + 1];
    fin.read(buffer, length);
    buffer[length] = '\0';
    studentCard.secondSubject = buffer;
    delete[] buffer;

    fin.read((char*)(&studentCard.secondMark), sizeof(studentCard.secondMark));

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length + 1];
    fin.read(buffer, length);
    buffer[length] = '\0';
    studentCard.thirdSubject = buffer;
    delete[] buffer;

    fin.read((char*)(&studentCard.thirdMark), sizeof(studentCard.thirdMark));
}

void textToBinaryStudentsCards(const std::string& textFileName, const std::string& binaryFileName)
{
    std::ifstream textFile(textFileName);
    CheckInputFile(textFile);

    std::ofstream binaryFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binaryFile);

    std::string line;
    while (std::getline(textFile, line))
    {
        std::stringstream ss(line);
        StudentCard studentCard;
        std::string token;

        std::getline(ss, token, ';');
        studentCard.group = std::stoi(token);

        std::getline(ss, token, ';');
        studentCard.id = std::stoi(token);

        std::getline(ss, studentCard.firstSubject, ';');

        std::getline(ss, token, ';');
        studentCard.firstMark = std::stoi(token);

        std::getline(ss, studentCard.secondSubject, ';');

        std::getline(ss, token, ';');
        studentCard.secondMark = std::stoi(token);

        std::getline(ss, studentCard.thirdSubject, ';');

        std::getline(ss, token, ';');
        studentCard.thirdMark = std::stoi(token);

        writeStudentCard(binaryFile, studentCard);
    }

    textFile.close();
    binaryFile.close();
}

void BinToStudentCard(StudentCard* studentCards, int size, const std::string& binaryFileName)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    CheckInputFile(binFile);

    for (int i = 0; i < size; ++i)
    {
        readStudentCard(binFile, studentCards[i]);
    }

    binFile.close();
}

void binaryToAsciiText(const std::string& binaryFileName, const std::string& textFileName)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(textFileName);
    CheckOutputFile(txtFile);
    char byte;
    int count{};
    while (binFile.get(byte))
    {
        if (std::isprint(static_cast<unsigned char>(byte)))
        {
            txtFile << byte;
        }
        count++;
    }

    binFile.close();
    txtFile.close();
}


void B (Student* students, StudentCard* studentsCards,int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    for (int i{0}; i < size; i++)
    {
        size_t surnameLength = students[i].surname.length();
        binFile.write((char*)(&surnameLength), sizeof(surnameLength));
        binFile.write(students[i].surname.c_str(), surnameLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        size_t firstSubjectLength = studentsCards[i].firstSubject.length();
        binFile.write((char*)(&firstSubjectLength), sizeof(firstSubjectLength));
        binFile.write(studentsCards[i].firstSubject.c_str(), firstSubjectLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        std::string markStr = std::to_string(studentsCards[i].firstMark);
        size_t len = markStr.length();
        binFile.write((char*)&len, sizeof(len));
        binFile.write(markStr.c_str(), len);

        binFile.write((char*)(&Probel), sizeof(Probel));

        size_t secondSubjectLength = studentsCards[i].secondSubject.length();
        binFile.write((char*)(&secondSubjectLength), sizeof(secondSubjectLength));
        binFile.write(studentsCards[i].secondSubject.c_str(), secondSubjectLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        std::string markStr2 = std::to_string(studentsCards[i].secondMark);
        size_t len2 = markStr2.length();
        binFile.write((char*)&len2, sizeof(len2));
        binFile.write(markStr2.c_str(), len2);

        binFile.write((char*)(&Probel), sizeof(Probel));

        size_t thirdSubjectLength = studentsCards[i].thirdSubject.length();
        binFile.write((char*)(&thirdSubjectLength), sizeof(thirdSubjectLength));
        binFile.write(studentsCards[i].thirdSubject.c_str(), thirdSubjectLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        std::string markStr3 = std::to_string(studentsCards[i].thirdMark);
        size_t len3 = markStr3.length();
        binFile.write((char*)&len3, sizeof(len3));
        binFile.write(markStr3.c_str(), len3);

        binFile.write((char*)(&Probel), sizeof(Probel));
    }
    binFile.close();
}


void C (Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    for (int i{ 0 }; i < size; i++)
    {
        size_t surnameLength = students[i].surname.length();
        binFile.write((char*)(&surnameLength), sizeof(surnameLength));
        binFile.write(students[i].surname.c_str(), surnameLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        double average = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;

        std::string markStr = std::to_string(average);
        size_t len = markStr.length();
        binFile.write((char*)&len, sizeof(len));
        binFile.write(markStr.c_str(), len);

        binFile.write((char*)(&Probel), sizeof(Probel));

    }
    binFile.close();
}


void D (Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    for (int i{ 0 }; i < size; i++)
    {
        double average = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;
        if (average < 4.0)
        {
            size_t surnameLength = students[i].surname.length();
            binFile.write((char*)(&surnameLength), sizeof(surnameLength));
            binFile.write(students[i].surname.c_str(), surnameLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string groupStr = std::to_string(studentsCards[i].group);
            size_t len = groupStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(groupStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string idStr = std::to_string(studentsCards[i].id);
            len = idStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(idStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

            binFile.write("\n", 1);
        }

    }
    binFile.close();
}


void sortStudents(StudentCard* arr, int n, Student* students )
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].group > arr[j + 1].group)
            {
                std::swap(arr[j], arr[j + 1]);
                std::swap(students[j], students[j + 1]);
            }
            else if (arr[j].group == arr[j + 1].group && strcmp(students[j].surname.c_str(), students[j + 1].surname.c_str()) > 0)
            {
                std::swap(arr[j], arr[j + 1]);
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}


void E(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    sortStudents(studentsCards, countStudentsInTextFile("students.txt"), students);
    for (int i{ 0 }; i < size; i++)
    {
        double average = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;
        if (average < 4.0)
        {
            size_t surnameLength = students[i].surname.length();
            binFile.write((char*)(&surnameLength), sizeof(surnameLength));
            binFile.write(students[i].surname.c_str(), surnameLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string groupStr = std::to_string(studentsCards[i].group);
            size_t len = groupStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(groupStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string idStr = std::to_string(studentsCards[i].id);
            len = idStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(idStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));
            binFile.write("\n", 1);
        }

    }


    binFile.close();
}


void F( const std::string& binaryFileName, const std::string& binaryFileName2, const std::string& binaryFileName3)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    std::ifstream binFile2(binaryFileName2, std::ios::binary);
    std::ofstream binFile3(binaryFileName3, std::ios::binary);

    char ch;
    while (binFile.get(ch))
    {
        binFile3.put(ch);
    }

    binFile3.put('\n');

    while (binFile2.get(ch))
    {
        binFile3.put(ch);
    }


    binFile2.close();
    binFile.close();
    binFile3.close();
}


void G(Student* students, StudentCard* studentsCards, int size, int numberGroup, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    sortStudents(studentsCards, countStudentsInTextFile("students.txt"), students);
    for (int i{0}; i < size; i++)
        if (studentsCards[i].group == numberGroup)
        {
            size_t surnameLength = students[i].surname.length();
            binFile.write((char*)(&surnameLength), sizeof(surnameLength));
            binFile.write(students[i].surname.c_str(), surnameLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            size_t firstSubjectLength = studentsCards[i].firstSubject.length();
            binFile.write((char*)(&firstSubjectLength), sizeof(firstSubjectLength));
            binFile.write(studentsCards[i].firstSubject.c_str(), firstSubjectLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string markStr = std::to_string(studentsCards[i].firstMark);
            size_t len = markStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(markStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

            size_t secondSubjectLength = studentsCards[i].secondSubject.length();
            binFile.write((char*)(&secondSubjectLength), sizeof(secondSubjectLength));
            binFile.write(studentsCards[i].secondSubject.c_str(), secondSubjectLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string markStr2 = std::to_string(studentsCards[i].secondMark);
            size_t len2 = markStr2.length();
            binFile.write((char*)&len2, sizeof(len2));
            binFile.write(markStr2.c_str(), len2);

            binFile.write((char*)(&Probel), sizeof(Probel));

            size_t thirdSubjectLength = studentsCards[i].thirdSubject.length();
            binFile.write((char*)(&thirdSubjectLength), sizeof(thirdSubjectLength));
            binFile.write(studentsCards[i].thirdSubject.c_str(), thirdSubjectLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string markStr3 = std::to_string(studentsCards[i].thirdMark);
            size_t len3 = markStr3.length();
            binFile.write((char*)&len3, sizeof(len3));
            binFile.write(markStr3.c_str(), len3);

            binFile.write((char*)(&Probel), sizeof(Probel));
            binFile.write("\n", 1);
        }
}


void StudentCardSort(double arr[], int n, StudentCard* studensCard, Student* students)
{
    for (int i{}; i < n - 1; i++)
    {
        for (int j{}; j < n - i - 1; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                std::swap(arr[j], arr[j+1]);
                std::swap(studensCard[j], studensCard[j + 1]);
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}


void H(Student* students, StudentCard* studentsCards, int size,  const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    double *average = new double[size];
    for(int i{0}; i < size; i++)
    {
        average[i] = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;
    }
    StudentCardSort(average, size, studentsCards, students);
    for (int i{ 0 }; i < size; i++)
    {
        size_t surnameLength = students[i].surname.length();
        binFile.write((char*)(&surnameLength), sizeof(surnameLength));
        binFile.write(students[i].surname.c_str(), surnameLength);

        binFile.write((char*)(&Probel), sizeof(Probel));

        std::string markStr = std::to_string(average[i]);
        size_t len = markStr.length();
        binFile.write((char*)&len, sizeof(len));
        binFile.write(markStr.c_str(), len);

        binFile.write((char*)(&Probel), sizeof(Probel));
    }
}


void I(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    char Probel = ' ';
    for (int i{ 0 }; i < size; i++)
    {
        double average = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;
        if (average >= 8.0)
        {
            size_t surnameLength = students[i].surname.length();
            binFile.write((char*)(&surnameLength), sizeof(surnameLength));
            binFile.write(students[i].surname.c_str(), surnameLength);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string groupStr = std::to_string(studentsCards[i].group);
            size_t len = groupStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(groupStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

            std::string idStr = std::to_string(studentsCards[i].id);
            len = idStr.length();
            binFile.write((char*)&len, sizeof(len));
            binFile.write(idStr.c_str(), len);

            binFile.write((char*)(&Probel), sizeof(Probel));

        }

    }
    binFile.close();
}
