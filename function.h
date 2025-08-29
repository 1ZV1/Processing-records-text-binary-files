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

void writeStudent(std::ofstream& fout, const Student& student);
void readStudent(std::ifstream& fin, Student& student);
void textToBinaryStudents(const std::string& textFileName, const std::string& binaryFileName);
int countStudentsInTextFile(const std::string& textFileName);
void BinToStudent(Student* students, int size, const std::string& binaryFileName);

void writeStudentCard(std::ofstream& fout, const StudentCard& studentCard);
void readStudentCard(std::ifstream& fin, StudentCard& studentCard);
void textToBinaryStudentsCards(const std::string& textFileName, const std::string& binaryFileName);
void BinToStudentCard(StudentCard* studentCards, int size, const std::string& binaryFileName);

void binaryToAsciiText(const std::string& binaryFileName, const std::string& textFileName);

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

#endif
