#ifndef FUNCTION_H
#define FUNCTION_H

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

void CheckInputFile(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);

void WriteStudent(std::ofstream& fout, const Student& student);
void ReadStudent(std::ifstream& fin, Student& student);
void TextToBinaryStudents(const std::string& textFileName, const std::string& binaryFileName);
int CountStudentsInTextFile(const std::string& textFileName);
void BinToStudent(Student* students, int size, const std::string& binaryFileName);

void WriteStudentCard(std::ofstream& fout, const StudentCard& studentCard);
void ReadStudentCard(std::ifstream& fin, StudentCard& studentCard);
void TextToBinaryStudentsCards(const std::string& textFileName, const std::string& binaryFileName);
void BinToStudentCard(StudentCard* studentCards, int size, const std::string& binaryFileName);

void BinaryToAsciiText(const std::string& binaryFileName, const std::string& textFileName);

void TaskB(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskC(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskD(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void sortStudents(StudentCard* arr, int n, Student* students);
void TaskE(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskF(const std::string& binaryFileName, const std::string& binaryFileName2, const std::string& binaryFileName3);
void TaskG(Student* students, StudentCard* studentsCards, int size, int numberGroup, const std::string& binaryFileName);
void StudentCardSort(double arr[], int n, StudentCard* studentsCard, Student* students);
void TaskH(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void TaskI(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void PrintBinaryFile(const std::string& fileName);

#endif
