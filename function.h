#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstring>

// Структуры
struct Student {
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct StudentCard {
    int group;
    int id;
    std::string firstSubject;
    int firstMark;
    std::string secondSubject;
    int secondMark;
    std::string thirdSubject;
    int thirdMark;
};

// Объявления функций
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

void B(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void C(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void D(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void sortStudents(StudentCard* arr, int n, Student* students);
void E(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void F(const std::string& binaryFileName, const std::string& binaryFileName2, const std::string& binaryFileName3);
void G(Student* students, StudentCard* studentsCards, int size, int numberGroup, const std::string& binaryFileName);
void StudentCardSort(double arr[], int n, StudentCard* studentsCard, Student* students);
void H(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);
void I(Student* students, StudentCard* studentsCards, int size, const std::string& binaryFileName);

#endif
