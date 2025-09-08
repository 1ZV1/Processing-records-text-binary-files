#include "function.h"

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

void CheckTextFile(std::ifstream& fin)
{
    if(!fin.is_open())
    {
        throw std::runtime_error("Text file couldn't be opened!");
    }
    if(fin.fail())
    {
        throw std::runtime_error("Input text file error!");
    }
    if(fin.bad())
    {
        throw std::runtime_error("Critical error with text file!");
    }
}

void WriteStudent(std::ofstream& fout, const Student& student)
{
    fout.write((const char*)(&student.id), sizeof(student.id));
    int length = (int)student.surname.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.surname.c_str(), length);
    length = (int)student.name.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.name.c_str(), length);
    length = (int)student.patronymic.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(student.patronymic.c_str(), length);
}

void ReadStudent(std::ifstream& fin, Student& student)
{
    fin.read((char*)(&student.id), sizeof(student.id));
    int length;
    char* buffer;
    
    fin.read((char*)(&length), sizeof(length));
    
    buffer = new char[length];
    fin.read(buffer, length);
    student.surname.assign(buffer, length);
    delete[] buffer;
    
    fin.read((char*)(&length), sizeof(length));
    
    buffer = new char[length];
    fin.read(buffer, length);
    student.name.assign(buffer, length);
    delete[] buffer;
    
    fin.read((char*)(&length), sizeof(length));
    
    buffer = new char[length];
    fin.read(buffer, length);
    student.patronymic.assign(buffer, length);
    delete[] buffer;
}

void TextToBinaryStudents(const std::string& textFileName, const std::string& binaryFileName)
{
    std::ifstream textFile(textFileName);
    CheckTextFile(textFile);
    std::ofstream binaryFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binaryFile);
    std::string line;
    while (std::getline(textFile, line))
    {
        if(line.empty())
        {
            continue;
        }
        std::stringstream stringStream(line); Student student; std::string token;
        std::getline(stringStream, token, ';'); student.id = std::stoi(token);
        std::getline(stringStream, student.surname, ';');
        std::getline(stringStream, student.name, ';');
        std::getline(stringStream, student.patronymic, ';');
        WriteStudent(binaryFile, student);
    }
}

int CountStudentsInTextFile(const std::string& textFileName)
{
    std::ifstream file(textFileName); CheckTextFile(file);
    int count{};
    std::string line;
    while(std::getline(file,line))
    {
        if(!line.empty())
        {
            ++count;
        }
    } 
    return count;
}

void BinToStudent(Student* students, int size, const std::string& binaryFileName)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    CheckInputFile(binFile);
    for(int i{}; i < size ; ++i)
    {
        ReadStudent(binFile, students[i]);
    }
}

void StudentsBinToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    Student student;
    while(binFile.peek()!=EOF)
    {
        ReadStudent(binFile, student);
        txtFile << student.id << ";" << student.surname << ";" << student.name << ";" << student.patronymic << "\n";
    }
}

void WriteStudentCard(std::ofstream& fout, const StudentCard& studentCard)
{
    fout.write((const char*)(&studentCard.group), sizeof(studentCard.group));
    fout.write((const char*)(&studentCard.id), sizeof(studentCard.id));
    int length = (int)studentCard.firstSubject.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.firstSubject.c_str(), length);
    fout.write((const char*)(&studentCard.firstMark), sizeof(studentCard.firstMark));
    length = (int)studentCard.secondSubject.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.secondSubject.c_str(), length);
    fout.write((const char*)(&studentCard.secondMark), sizeof(studentCard.secondMark));
    length = (int)studentCard.thirdSubject.length();
    fout.write((const char*)(&length), sizeof(length));
    fout.write(studentCard.thirdSubject.c_str(), length);
    fout.write((const char*)(&studentCard.thirdMark), sizeof(studentCard.thirdMark));
}

void ReadStudentCard(std::ifstream& fin, StudentCard& studentCard)
{
    fin.read((char*)(&studentCard.group), sizeof(studentCard.group));
    fin.read((char*)(&studentCard.id), sizeof(studentCard.id));

    int length;
    char* buffer;

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    studentCard.firstSubject = std::string(buffer, length);
    delete[] buffer;

    fin.read((char*)(&studentCard.firstMark), sizeof(studentCard.firstMark));

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    studentCard.secondSubject = std::string(buffer, length);
    delete[] buffer;

    fin.read((char*)(&studentCard.secondMark), sizeof(studentCard.secondMark));

    fin.read((char*)(&length), sizeof(length));
    buffer = new char[length];
    fin.read(buffer, length);
    studentCard.thirdSubject = std::string(buffer, length);
    delete[] buffer;

    fin.read((char*)(&studentCard.thirdMark), sizeof(studentCard.thirdMark));
}

void TextToBinaryStudentsCards(const std::string& textFileName, const std::string& binaryFileName)
{
    std::ifstream textFile(textFileName);
    CheckTextFile(textFile);
    std::ofstream binaryFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binaryFile);
    std::string line;
    while(std::getline(textFile,line))
    {
        if(line.empty())
        {
            continue;
        }
        std::stringstream stringStream(line);
        StudentCard card;
        std::string token;
        std::getline(stringStream, token, ';'); card.group = std::stoi(token);
        std::getline(stringStream, token, ';'); card.id = std::stoi(token);
        std::getline(stringStream, card.firstSubject, ';');
        std::getline(stringStream, token, ';'); card.firstMark = std::stoi(token);
        std::getline(stringStream, card.secondSubject, ';');
        std::getline(stringStream, token, ';'); card.secondMark = std::stoi(token);
        std::getline(stringStream, card.thirdSubject, ';');
        std::getline(stringStream, token, ';'); card.thirdMark = std::stoi(token);
        WriteStudentCard(binaryFile, card);
    }
}

void BinToStudentCard(StudentCard* studentCards, int size, const std::string& binaryFileName)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    CheckInputFile(binFile);
    for(int i{} ; i < size ; ++i)
    {
        ReadStudentCard(binFile, studentCards[i]);
    }
}

void StudentCardsBinToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    StudentCard card;
    while(binFile.peek()!=EOF)
    {
        ReadStudentCard(binFile, card);
        txtFile << card.group << " " << card.id << " " << card.firstSubject << " " << card.firstMark << " "
                << card.secondSubject << " " << card.secondMark << " " << card.thirdSubject << " " << card.thirdMark << "\n";
    }
}

void TaskB(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary); CheckOutputFile(binFile);
    for(int i{} ; i < size ; i++)
    {
        std::string line = std::to_string(studentsCards[i].group) +
            " " + std::to_string(studentsCards[i].id) + " " +
            students[i].surname + " " +
            studentsCards[i].firstSubject + " " + std::to_string(studentsCards[i].firstMark) + " " +
            studentsCards[i].secondSubject + " " + std::to_string(studentsCards[i].secondMark) + " " +
            studentsCards[i].thirdSubject + " " + std::to_string(studentsCards[i].thirdMark) + "\n";
        binFile.write(line.c_str(), line.size());
    }
}

void TaskBToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    std::string line;
    while(std::getline(binFile,line))
    {
        txtFile << line << "\n";
    }
}

void TaskC(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binFile);
    for (int i{}; i < size; i++)
    {
        double average = (studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark) / 3.0;
        std::string line = std::to_string(studentsCards[i].group) + " " + std::to_string(studentsCards[i].id)
        + " " + students[i].surname + " " + std::to_string(average) + "\n";
        binFile.write(line.c_str(), line.size());
    }
}

void TaskCToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    std::string line;
    while (std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void WriteBadStudentsToBinFile(const std::string& fileName, BadStudent* students, int size)
{
    std::ofstream binFile(fileName, std::ios::binary);

    for (int i {}; i < size; ++i)
    {
        std::string line = students[i].surname + " " + std::to_string(students[i].group) + " " + std::to_string(students[i].id) + "\n";
        binFile.write(line.c_str(), line.size());
    }
}

BadStudent* FillBadStudentList(const std::string& binaryFileName,const int outSize)
{
    std::ifstream binFile(binaryFileName, std::ios::binary);
    BadStudent* badStudents = new BadStudent[outSize];
    int i{};
    std::string line;
    while (std::getline(binFile, line) && i < outSize)
    {
        std::istringstream iss(line);
        iss >> badStudents[i].surname 
            >> badStudents[i].group 
            >> badStudents[i].id;
        ++i;
    }

    return badStudents;
}

void TaskD(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary);
    CheckOutputFile(binFile);
    for (int i{}; i < size; ++i)
    {
        double average{(studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark)/ 3.0};
        if (average < 4)
        {
            std::string line = students[i].surname  + " " + std::to_string(studentsCards[i].group) + " " + std::to_string(studentsCards[i].id) + "\n";
            binFile.write(line.c_str(), line.size());
        }
    }
}

void SortBadStudent(BadStudent* badStudent, int outSize)
{
    for (int i{}; i < outSize - 1; ++i)
    {
        for (int j{}; j < outSize - i - 1; ++j)
        {
            bool swapNeeded = false;
            if (badStudent[j].group > badStudent[j + 1].group)
            {
                swapNeeded = true;
            }
            else if (badStudent[j].group == badStudent[j + 1].group && badStudent[j].surname > badStudent[j + 1].surname)
            {
                swapNeeded = true;
            }

            if (swapNeeded)
            {
                BadStudent temp = badStudent[j];
                badStudent[j] = badStudent[j + 1];
                badStudent[j + 1] = temp;
            }
        }
    }
}

void TaskDToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    std::string line; 
    while(std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskEToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    std::string line;
    while (std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskDToTxtMod(std::ifstream& binFile, std::ofstream& txtFile)
{
    std::string line; 
    while(std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskEToTxtMod(std::ifstream& binFile, std::ofstream& txtFile)
{
    std::string line;
    while(std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskF(const std::string& beforeSortBin, const std::string& afterSortBin, const std::string& outputTxtFile)
{
    std::ofstream txtFile(outputTxtFile);
    CheckOutputFile(txtFile);
    std::ifstream binFileBeforeSort(beforeSortBin,std::ios::binary );
    CheckOutputFile(txtFile);
    std::ifstream binFileAfterSort(afterSortBin,std::ios::binary);
    CheckOutputFile(txtFile);
    txtFile << "������������ (�� ����������):\n";
    TaskDToTxtMod(binFileBeforeSort, txtFile); 
    txtFile << "\n������������ (����� ����������):\n";
    TaskEToTxtMod(binFileAfterSort, txtFile);
}



void TaskG(Student* students, StudentCard* cards, int size, int groupNum, const std::string& fileName)
{
    int* groupIndices = new int[size];
    int count{};
    
    for (int i{}; i < size; ++i)
    {
        if (cards[i].group == groupNum)
        {
            groupIndices[count++] = i;
        }
    }
    
    for (int i{}; i < count - 1; ++i)
    {
        for (int j{}; j < count - i - 1; ++j)
        {
            if (students[groupIndices[j]].surname > students[groupIndices[j + 1]].surname)
            {
                std::swap(groupIndices[j], groupIndices[j + 1]);
            }
        }
    }
    
    std::ofstream fout(fileName, std::ios::binary);
    CheckOutputFile(fout);

    for (int i{}; i < count; ++i)
    {
        int idx = groupIndices[i];
        std::string line = std::to_string(cards[idx].group) + " " +
                          std::to_string(cards[idx].id) + " " +
                          students[idx].surname + " " +
                          cards[idx].firstSubject + ":" + std::to_string(cards[idx].firstMark) + " " +
                          cards[idx].secondSubject + ":" + std::to_string(cards[idx].secondMark) + " " +
                          cards[idx].thirdSubject + ":" + std::to_string(cards[idx].thirdMark) + "\n";
        
        fout.write(line.c_str(), line.size());
    }
    
    delete[] groupIndices;
}

void TaskGToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    
    std::string line;
    while (std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskH(Student* students, StudentCard* cards, int size, int groupNum, const std::string& fileName)
{
    StudentAvg* studentAvgs = new StudentAvg[size];
    int count{};    
    
    for (int i{}; i < size; ++i)
    {
        if (cards[i].group == groupNum)
        {
            double avg{(cards[i].firstMark + cards[i].secondMark + cards[i].thirdMark) / 3.0};
            studentAvgs[count].index = i;
            studentAvgs[count].average = avg;
            count++;
        }
    }
    
    for (int i{}; i < count - 1; ++i)
    {
        for (int j{}; j < count - i - 1; ++j)
        {
            if (studentAvgs[j].average < studentAvgs[j + 1].average)
            {
                std::swap(studentAvgs[j], studentAvgs[j + 1]);
            }
        }
    }
    
    std::ofstream fout(fileName, std::ios::binary);
    CheckOutputFile(fout);

    for (int i{}; i < count; ++i)
    {
        int idx = studentAvgs[i].index;
        std::string line = std::to_string(cards[idx].group) + " " +
                          std::to_string(cards[idx].id) + " " +
                          students[idx].surname + " " +
                          cards[idx].firstSubject + ":" + std::to_string(cards[idx].firstMark) + " " +
                          cards[idx].secondSubject + ":" + std::to_string(cards[idx].secondMark) + " " +
                          cards[idx].thirdSubject + ":" + std::to_string(cards[idx].thirdMark) + " " +
                          "Avg:" + std::to_string(studentAvgs[i].average) + "\n";
        
        fout.write(line.c_str(), line.size());
    }
    
    delete[] studentAvgs;
}

void TaskHToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary);
    CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName);
    CheckOutputFile(txtFile);
    std::string line;
    while(std::getline(binFile, line))
    {
        txtFile << line << "\n";
    }
}

void TaskI(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName)
{
    std::ofstream binFile(binaryFileName, std::ios::binary); CheckOutputFile(binFile);
    for (int i{}; i < size; ++i)
    {
        double average{(studentsCards[i].firstMark + studentsCards[i].secondMark + studentsCards[i].thirdMark)/ 3.0};
        if (average >= 8)
        {
            std::string line = students[i].surname  + " " + std::to_string(studentsCards[i].group) + " " + std::to_string(studentsCards[i].id) + "\n";
            binFile.write(line.c_str(), line.size());
        }
    }
}

void TaskIToTxt(const std::string& binFileName, const std::string& txtFileName)
{
    std::ifstream binFile(binFileName, std::ios::binary); CheckInputFile(binFile);
    std::ofstream txtFile(txtFileName); CheckOutputFile(txtFile);
    std::string line; while (std::getline(binFile, line)) txtFile << line << "\n";
}

