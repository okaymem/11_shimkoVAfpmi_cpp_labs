#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>

bool compareStudents(const Student& first, const Student& second) {
    if (first.name < second.name) {
        return true;
    }
    if (first.name > second.name) {
        return false;
    }
    return first.calculateAverage() > second.calculateAverage();
}

double Student::calculateAverage() const {
    if (marks.empty()) {
        return 0.0;
    }

    size_t sum = 0;
    for (const Mark& mark : marks) {
        sum += mark.grade;
    }
    return static_cast<double>(sum) / marks.size();
}

size_t Student::calculateSumOfGrades() const {
    size_t total = 0;
    for (const Mark& mark : marks) {
        total += mark.grade;
    }
    return total;
}

bool Student::hasBadGrades() const {
    for (const Mark& mark : marks) {
        if (mark.grade <= 3) {
            return true;
        }
    }
    return false;
}

bool Student::hasSubject(const std::string& subjectName) const {
    for (const Mark& mark : marks) {
        if (mark.subject == subjectName) {
            return true;
        }
    }
    return false;
}

std::map<size_t, Student> readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::map<size_t, Student> students;

    std::string lastName;
    size_t recordNumber;

    while (inputFile >> lastName) {
        Student currentStudent;

        std::string initials;
        inputFile >> initials;
        currentStudent.name = lastName + " " + initials;

        inputFile >> recordNumber;
        currentStudent.recordBookNumber = recordNumber;

        std::string subject;
        size_t grade;

        while (inputFile >> subject >> grade) {
            currentStudent.marks.push_back({subject, grade});
            if (inputFile.peek() == '\n'){
                break;
            }
        }

        students[currentStudent.recordBookNumber] = currentStudent;
    }

    return students;
}

void printByRecordBook(const std::map<size_t, Student>& students) {
    for (const auto& studentPair : students) {
        std::cout << studentPair.second.recordBookNumber << " " 
                  << studentPair.second.name << "\n";
    }
}

void printAlphabetical(const std::map<size_t, Student>& students) {
    std::vector<Student> studentList;
    for (const auto& studentPair : students) {
        studentList.push_back(studentPair.second);
    }

    std::sort(studentList.begin(), studentList.end(), compareStudents);

    size_t counter = 1;
    for (const auto& student : studentList) {
        std::cout << counter++ << ". " << student.name << ", " 
                  << student.recordBookNumber << ", " 
                  << student.calculateAverage() << "\n";
    }
}

void printByAverageRange(const std::map<size_t, Student>& students, 
                         double lower, double upper) {
    std::vector<Student> filteredStudents;

    for (const auto& studentPair : students) {
        double average = studentPair.second.calculateAverage();
        if (average >= lower && average <= upper){
            filteredStudents.push_back(studentPair.second);
        }
    }
    
    std::sort(filteredStudents.begin(), filteredStudents.end(),
            [](const auto& first, const auto& second) {
                return first.calculateAverage() > second.calculateAverage();
            });

    for (const auto& student : filteredStudents) {
        std::cout << student.name << " " << student.calculateAverage() << "\n";
    }
}

void printBySubject(const std::map<size_t, Student>& students,
                   const std::string& subject) {
    for (const auto& studentPair : students) {
        if (studentPair.second.hasSubject(subject)) {
            std::cout << studentPair.second.name << " (" 
                      << studentPair.second.recordBookNumber << ")\n";
        }
    }
}

void countSubjects(const std::map<size_t, Student>& students) {
    std::map<std::string, size_t> subjectCount;

    for (const auto& studentPair : students) {
        std::set<std::string> uniqueSubjects;
        for (const auto& mark : studentPair.second.marks) {
            uniqueSubjects.insert(mark.subject);
        }
        for (const auto& subject : uniqueSubjects) {
            subjectCount[subject]++;
        }
    }

    for (const auto& countPair : subjectCount) {
        std::cout << countPair.first << ": " << countPair.second << "\n";
    }
}

void calculateAverageBySubject(const std::map<size_t, Student>& students) {
    std::map<std::string, std::vector<size_t>> subjectGrades;

    for (const auto& studentPair : students) {
        for (const auto& mark : studentPair.second.marks) {
            subjectGrades[mark.subject].push_back(mark.grade);
        }
    }

    std::vector<std::pair<std::string, double>> averages;
    for (const auto& subjectPair : subjectGrades) {
        double average = std::accumulate(subjectPair.second.begin(), 
                                        subjectPair.second.end(), 0.0) 
                        / subjectPair.second.size();
        averages.push_back({subjectPair.first, average});
    }

    std::sort(averages.begin(), averages.end(),
            [](const auto& first, const auto& second) {
                return first.second > second.second;
            });

    for (const auto& averagePair : averages) {
        std::cout << averagePair.first << " " << averagePair.second << "\n";
    }
}

void printBestStudentsBySum(const std::map<size_t, Student>& students) {
    size_t maxSum = 0;
    for (const auto& studentPair : students) {
        maxSum = std::max(maxSum, studentPair.second.calculateSumOfGrades());
    }

    for (const auto& studentPair : students) {
        if (studentPair.second.calculateSumOfGrades() == maxSum) {
            std::cout << studentPair.second.name << "\n";
        }
    }
}

void printStudentsWithBadMarks(const std::map<size_t, Student>& students) {
    for (const auto& studentPair : students) {
        if (studentPair.second.hasBadGrades()) {
            std::cout << studentPair.second.name << "\n";
        }
    }
}

double inputDouble(const std::string& prompt) {
    double value;

    std::cout << prompt;
    std::cin >> value;

    while (!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Error, enter a number: ";
        std::cin >> value;
    }

    return value;
}