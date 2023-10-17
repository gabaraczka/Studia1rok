#pragma once

#include <fstream>

enum StudyProgram {
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    HISTORY,
    ENGLISH
};

struct MyStudent {
    char* name;
    int birthYear;
    StudyProgram program;
};

MyStudent* createStudent(const char* name, int birthYear, StudyProgram program);
void destroyStudent(void* student);
bool compareStudentsByYear(const MyStudent* student1, const MyStudent* student2);
void saveStudent(void* data, std::ofstream& file);
void* loadStudent(std::ifstream& file);
void displayStudent(const MyStudent* student);
