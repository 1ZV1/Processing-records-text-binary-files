#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

template <typename T>
T* CreateArray(int32_t sizeArr);

void CheckInputFile(std::ifstream& fin);

void CheckOutputFile(std::ofstream& fout);

template<typename T>
size_t CountFile(std::ifstream& fin);

template<typename T>
void FillArr(std::ifstream& fin, T* arr, size_t sizeArr);

template<typename T>
void FileOutputArr(std::ostream& fout, T* arr, size_t sizeArr);

void TextToBinaryFile(std::ifstream& finText, std::string& foutBin);

#endif