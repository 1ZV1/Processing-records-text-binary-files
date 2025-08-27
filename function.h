#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void CheckInputFile(std::ifstream& fin);

void CheckOutputFile(std::ofstream& fout);

int CountStudents(std::string nameIn);

void WriteStudent(std::ofstream& binFile, const Student& student);

void TextToBin(std::string nameIn, std::string nameOut);

struct Student
{
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
};

struct StudentCard
{
    int groop{};
    int cardNum{};
    std::string firstSubject {"MA"};
    int firstMark{};
    std::string secondSubject {"GEO"};
    int secondMark{};
    std::string thirdSubject {"PROG"};
    int thirdMark{};
};
#endif
