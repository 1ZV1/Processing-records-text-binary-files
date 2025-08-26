#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

template <typename T>
T* CreateArray(int32_t sizeArr)
{
    if (sizeArr <= 0)
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T* array = new T[sizeArr] {};
    return array;
}

void CheckInputFile(std::ifstream& fin) {
    if(!fin.is_open())
    {
        throw "Binary file couldn't be opened!\n";
    }
    if(fin.fail())
    {
        throw "Input binary file error!\n";
    }
    if(fin.bad())
    {
        throw "Critical error with binary file!\n";
    }
    if(fin.peek() == EOF)
    {
        throw "Binary file is empty!\n";
    }
}

void CheckOutputFile(std::ofstream& fout) {
    if(!fout.is_open())
    {
        throw "Binary file couldn't be opened for writing!\n";
    }
    if(fout.fail())
    {
        throw "Output binary file error!\n";
    }
    if(fout.bad())
    {
        throw "Critical error with output binary file!\n";
    }
}

template<typename T>
size_t CountFile(std::ifstream& fin)
{
    size_t counter{};
    T num{};
    while (fin >> num)
    {
        ++counter;
    }
    return counter;
}

template<typename T>
void FillArr(std::ifstream& fin, T* arr, size_t sizeArr)
{
    fin.clear();
    fin.seekg(0);
    for(size_t i{}; i < sizeArr; ++i)
    {
        fin >> arr[i];
    }
}

template<typename T>
void FileOutputArr(std::ostream& fout, T* arr, size_t sizeArr)
{
    for(size_t i{}; i < sizeArr; ++i)
    {
        fout << arr[i] << ' ';
    }
    fout <<'\n';
}

void TextToBinaryFile(std::ifstream& finText, std::string& foutBin)
{

}


int main()
{
    std::ifstream fin("students.txt");
    try
    {
        CheckInputFile(fin);
        fin.close();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}