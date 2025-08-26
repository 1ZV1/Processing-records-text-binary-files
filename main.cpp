#include"function.h"

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