#pragma once

#include <fstream>

struct StackNode {
    void* data;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;
    void (*f_elementDestructor)(void*);

public:
    Stack(void (*func)(void*));
    ~Stack();

    void push(void* newData);
    void* pop();
    bool isEmpty();
    void clear();

    void saveToFile(const char* filename, void (*func)(void*, std::ofstream&));
    void loadFromFile(const char* filename, void* (*func)(std::ifstream&));
};



