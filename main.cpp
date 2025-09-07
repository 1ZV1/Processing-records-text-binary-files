#include "function.h"

int main()
{
    try
    {
        TextToBinaryStudents("students.txt", "students.bin");
        StudentsBinToTxt("students.bin", "students-output.txt");

        TextToBinaryStudentsCards("students-marks.txt", "students-mark.bin");
        StudentCardsBinToTxt("students-mark.bin", "students-mark-output.txt");

        int studentSize = CountStudentsInTextFile("students.txt");
        int cardSize = CountStudentsInTextFile("students-marks.txt");

        if (studentSize != cardSize)
        {
            std::cout << "The number of students and cards does not coincide!\n";
            return 1;
        }

        Student* students = new Student[studentSize];
        BinToStudent(students, studentSize, "students.bin");

        StudentCard* studentsCards = new StudentCard[cardSize];
        BinToStudentCard(studentsCards, cardSize, "students-mark.bin");

        int size = studentSize;

        TaskB(students, studentsCards, size, "task-b.bin");
        TaskBToTxt("task-b.bin", "task-b.txt");
        TaskBToTxt("task-b.bin","task-b-output.txt");

        TaskC(students, studentsCards, size, "task-c.bin");
        TaskCToTxt("task-c.bin", "task-c.txt");

        TaskD(students, studentsCards, size, "task-d.bin");
        TaskDToTxt("task-d.bin", "task-d.txt");

        int sizeBadStudent = CountStudentsInTextFile("task-d.bin");
        BadStudent* badStudent = FillBadStudentList("task-d.bin", sizeBadStudent);
    
        SortBadStudent(badStudent, sizeBadStudent); 
        WriteBadStudentsToBinFile("task-e.bin", badStudent, sizeBadStudent);
        TaskEToTxt("task-e.bin", "task-e.txt");
        delete[] badStudent;

        TaskF("task-d.bin", "task-e.bin", "task-f.txt");

        int numberGroup{};
        std::cout << "\nInput Number group: ";
        std::cin >> numberGroup;

        TaskG(students, studentsCards, size, numberGroup, "task-g.bin");
        TaskGToTxt("task-g.bin", "task-g.txt");

        TaskH(students, studentsCards, size, numberGroup, "task-h.bin");
        TaskHToTxt("task-h.bin", "task-h.txt");

        TaskI(students, studentsCards, size, "task-i.bin");
        TaskIToTxt("task-i.bin", "task-i.txt");

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
