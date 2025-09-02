#include "function.h"

int main()
{
    try
    {
        TextToBinaryStudents("students.txt", "students.bin");
        BinaryToAsciiText("students.bin", "students-output.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");

        TextToBinaryStudentsCards("students-marks.txt", "students-mark.bin");
        BinaryToAsciiText("students-mark.bin", "students-mark-output.txt");
        PrintBinaryFile("students.bin");

        int studentSize = CountStudentsInTextFile("students.txt");
        int cardSize = CountStudentsInTextFile("students-marks.txt");

        if (studentSize != cardSize)
        {
            std::cout << "The number of students and cards does not coincide!";
            return 1;
        }

        Student* students = new Student[studentSize];
        BinToStudent(students, studentSize, "students.bin");

        StudentCard* studentsCards = new StudentCard[cardSize];
        BinToStudentCard(studentsCards, cardSize, "students-mark.bin");

        int size = studentSize;

        TaskB(students, studentsCards, size, "task-b.bin");
        BinaryToAsciiText("task-b.bin", "task-b.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        
        TaskC(students, studentsCards, size, "task-c.bin");
        BinaryToAsciiText("task-c.bin", "task-c.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        
        TaskD(students, studentsCards, size, "task-d.bin");
        BinaryToAsciiText("task-d.bin", "task-d.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        
        TaskE(students, studentsCards, size, "task-e.bin");
        BinaryToAsciiText("task-e.bin", "task-e.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        
        TaskF("students.bin", "task-e.bin", "task-f.bin");
        BinaryToAsciiText("task-f.bin", "task-f.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        
        int numberGroup{};
        std::cout << "\nInput Number group: ";
        std::cin >> numberGroup;

        TaskG(students, studentsCards, size, numberGroup, "task-g.bin");
        BinaryToAsciiText("task-g.bin", "task-g.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");

        TaskH(students, studentsCards, size, "task-h.bin");
        BinaryToAsciiText("task-h.bin", "task-h.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");

        TaskI(students, studentsCards, size, "task-i.bin");
        BinaryToAsciiText("task-i.bin", "task-i.txt");
        std::cout <<"\nPrint .bin file in 16 calculation system:\n";
        PrintBinaryFile("students.bin");
        delete[] students;
        delete[] studentsCards;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
