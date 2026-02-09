#include "student.h"
#include <iostream>

int main() {
    auto students = readFromFile("students.txt");

    std::cout << "\nSorting by record book number\n";
    printByRecordBook(students);

    std::cout << "\nAlphabetical list + average score\n";
    printAlphabetical(students);

    std::cout << "\nAverage score in range\n";
    double lowerLimit = inputDouble("Enter lower limit: ");
    double upperLimit = inputDouble("Enter upper limit: ");

    if (lowerLimit > upperLimit) std::swap(lowerLimit, upperLimit);
    printByAverageRange(students, lowerLimit, upperLimit);

    std::cout << "\nStudents who took subject\n";
    std::string subject;
    std::cout << "Enter subject: ";
    std::cin >> subject;
    printBySubject(students, subject);

    std::cout << "\nHow many students took each subject\n";
    countSubjects(students);

    std::cout << "\nAverage grade for subjects\n";
    calculateAverageBySubject(students);

    std::cout << "\nStudents with the highest scores\n";
    printBestStudentsBySum(students);

    std::cout << "\nStudents with unsatisfactory grades\n";
    printStudentsWithBadMarks(students);

    return 0;
}