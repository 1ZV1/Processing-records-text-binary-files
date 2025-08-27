#include "function.h"

int main()
{
    try
    {
        Student* student = TextToBinStruct("students.txt", "students.bin");
        StudentCard* StudentsCards = TextToBinStudentsCards("students-marks.txt", "students-marks.bin");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}