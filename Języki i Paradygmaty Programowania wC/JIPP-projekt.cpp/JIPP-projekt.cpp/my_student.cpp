#include "my_student.h"

#include <iostream>

using std::cout;
using std::endl;

MyStudent* createStudent(const char* name, int birthYear, StudyProgram program) {
    MyStudent* student = new MyStudent();
    student->name = new char[strlen(name) + 1];
    strcpy_s(student->name, strlen(name) + 1, name);
    student->birthYear = birthYear;
    student->program = program;
    return student;
}

void destroyStudent(void* data) {
	MyStudent* student = static_cast<MyStudent*>(data);
    delete[] student->name;
    delete student;
}

bool compareStudentsByYear(const MyStudent* student1, const MyStudent* student2) {
    return student1->birthYear < student2->birthYear;
}

void saveStudent(void* data, std::ofstream& file) {

    MyStudent* student = static_cast<MyStudent*>(data);

    int nameLength = strlen(student->name);
    file.write(reinterpret_cast<char*>(&nameLength), sizeof(int));
    file.write(student->name, nameLength);

    file.write(reinterpret_cast<char*>(&student->birthYear), sizeof(int));

    StudyProgram program = student->program;
    file.write(reinterpret_cast<char*>(&program), sizeof(StudyProgram));
}

void* loadStudent(std::ifstream& file) {
    int nameLength;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(int));

    if (file.eof()) {
        return nullptr;
    }

    MyStudent* newStudent = new MyStudent();
    newStudent->name = new char[nameLength + 1];
    file.read(newStudent->name, nameLength);
    newStudent->name[nameLength] = '\0';

    file.read(reinterpret_cast<char*>(&newStudent->birthYear), sizeof(int));
    file.read(reinterpret_cast<char*>(&newStudent->program), sizeof(StudyProgram));

    return newStudent;
}


void displayStudent(const MyStudent* student) {
    cout << "Nazwisko: " << student->name << endl;
    cout << "Rok urodzenia: " << student->birthYear << endl;
    cout << "Kierunek studiow: ";

    switch (student->program) {
    case StudyProgram::COMPUTER_SCIENCE:
        cout << "Informatyka";
        break;
    case StudyProgram::MATHEMATICS:
        cout << "Matematyka";
        break;
    case StudyProgram::PHYSICS:
        cout << "Fizyka";
        break;
    case StudyProgram::HISTORY:
        cout << "Historia";
        break;
    case StudyProgram::ENGLISH:
        cout << "Anglistyka";
        break;
    }

    cout << endl;
}