#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstring>

struct Student
{
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct BadStudent
{   
    std::string surname;
    int group;
    int id;
};

struct StudentCard
{
    int group;
    int id;
    std::string firstSubject;
    int firstMark;
    std::string secondSubject;
    int secondMark;
    std::string thirdSubject;
    int thirdMark;
};

struct StudentAvg
{
    int index;
    double average;
};

void CheckInputFile(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);
void CheckTextFile(std::ifstream& fin);

void WriteStudent(std::ofstream& fout, const Student& student);
void ReadStudent(std::ifstream& fin, Student& student);
void TextToBinaryStudents(const std::string& textFileName, const std::string& binaryFileName);
int CountStudentsInTextFile(const std::string& textFileName);
void BinToStudent(Student* students, int size, const std::string& binaryFileName);
void StudentsBinToTxt(const std::string& binFileName, const std::string& txtFileName);

void WriteStudentCard(std::ofstream& fout, const StudentCard& studentCard);
void ReadStudentCard(std::ifstream& fin, StudentCard& studentCard);
void TextToBinaryStudentsCards(const std::string& textFileName, const std::string& binaryFileName);
void BinToStudentCard(StudentCard* studentCards, int size, const std::string& binaryFileName);
void StudentCardsBinToTxt(const std::string& binFileName, const std::string& txtFileName);

void TaskB(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskC(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskD(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
BadStudent* FillBadStudentList(const std::string& binaryFileName,const int outSize);
void SortBadStudent(BadStudent* badStudent, int outSize);
void WriteBadStudentsToBinFile(const std::string& fileName, BadStudent* students, int size);
void TaskE(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskF(const std::string& beforeSortBin, const std::string& afterSortBin, const std::string& outputTxtFile);
void TaskG(Student* students, StudentCard* studentsCards, int size, int numberGroup, const std::string& binaryFileName);
void TaskH(Student* students, StudentCard* cards, int size, int groupNum, const std::string& fileName);
void TaskI(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);

void TaskBToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskCToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskDToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskEToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskGToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskHToTxt(const std::string& binFileName, const std::string& txtFileName);
void TaskIToTxt(const std::string& binFileName, const std::string& txtFileName);

