#include "function.h"

int main()
{
    try
    {
        textToBinaryStudents("students.txt", "students.bin");
        binaryToAsciiText("students.bin", "studentsOutPut.txt");
        textToBinaryStudentsCards("students-marks.txt", "students-mark.bin");
        int studentSize = countStudentsInTextFile("students.txt");
        Student* students = new Student[studentSize];
        BinToStudent(students, studentSize, "students.bin");

        std::cout << "Students data:\n";
        for (int i{}; i < studentSize; ++i)
        {
            std::cout << "ID: " << students[i].id
                      << "; Surname: " << students[i].surname
                      << "; Name: " << students[i].name
                      << "; Patronymic: " << students[i].patronymic << '\n';
        }

        int cardSize = countStudentsInTextFile("students-marks.txt");
        StudentCard* studentsCards = new StudentCard[cardSize];
        BinToStudentCard(studentsCards, cardSize, "students-mark.bin");

        std::cout << "\nStudent Cards data:\n";
        for (int i{}; i < cardSize; ++i) {
            std::cout << "Group: " << studentsCards[i].group
                      << "; ID: " << studentsCards[i].id
                      << "; First Subject: " << studentsCards[i].firstSubject
                      << "; First Mark: " << studentsCards[i].firstMark
                      << "; Second Subject: " << studentsCards[i].secondSubject
                      << "; Second Mark: " << studentsCards[i].secondMark
                      << "; Third Subject: " << studentsCards[i].thirdSubject
                      << "; Third Mark: " << studentsCards[i].thirdMark << '\n';
        }

        int size = studentSize;
        B(students, studentsCards, size, "b.bin");
        binaryToAsciiText("b.bin", "b.txt");

        C(students, studentsCards, size, "c.bin");
        binaryToAsciiText("c.bin", "c.txt");

        D(students, studentsCards, size, "d.bin");
        binaryToAsciiText("d.bin", "d.txt");

        E(students, studentsCards, size, "e.bin");
        binaryToAsciiText("e.bin", "e.txt");

        F("students.bin", "e.bin", "f.bin");
        binaryToAsciiText("f.bin", "f.txt");

        int numberGroup{};
        std::cout << "Input Number group: ";
        std::cin >> numberGroup;
        G(students, studentsCards, size, numberGroup, "g.bin");
        binaryToAsciiText("g.bin", "g.txt");

        H(students, studentsCards, size, "h.bin");
        binaryToAsciiText("h.bin", "h.txt");

        I(students, studentsCards, size, "i.bin");
        binaryToAsciiText("i.bin", "i.txt");

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
