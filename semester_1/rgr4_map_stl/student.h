#pragma once

#include <string>
#include <vector>
#include <map>

struct Mark {
    std::string subject;
    size_t grade;
};

struct Student {
    std::string name;
    size_t recordBookNumber;
    std::vector<Mark> marks;

    double calculateAverage() const;
    size_t calculateSumOfGrades() const;
    bool hasBadGrades() const;
    bool hasSubject(const std::string& subjectName) const;
};

std::map<size_t, Student> readFromFile(const std::string& filename);

void printByRecordBook(const std::map<size_t, Student>& students);
void printAlphabetical(const std::map<size_t, Student>& students);
void printByAverageRange(const std::map<size_t, Student>& students, double lower, double upper);
void printBySubject(const std::map<size_t, Student>& students, const std::string& subject);
void countSubjects(const std::map<size_t, Student>& students);
void calculateAverageBySubject(const std::map<size_t, Student>& students);
void printBestStudentsBySum(const std::map<size_t, Student>& students);
void printStudentsWithBadMarks(const std::map<size_t, Student>& students);
double inputDouble(const std::string& prompt);
bool compareStudents(const Student& first, const Student& second);