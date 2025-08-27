#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Student
{
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct StudentCard
{
    int groop;
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

int CountStudents(std::string nameIn);

void WriteStudent(std::ofstream& binFile, const Student& student);

void TextToBinStruct(std::string nameIn, std::string nameOut);

void WriteStudentCard(std::ofstream& binFile, const StudentCard& studentCard);

void TextToBinStudentsCards(std::string nameIn, std::string nameOut);

#endif
