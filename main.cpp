#include "function.h"

int main()
{
    try
    {
        TextToBinStruct("students.txt", "students.bin");
        TextToBinStudentsCards("students-marks.txt", "students-marks.bin");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}