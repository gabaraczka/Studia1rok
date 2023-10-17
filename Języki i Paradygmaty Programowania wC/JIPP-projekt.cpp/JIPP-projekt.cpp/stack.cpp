#include "stack.h"

#include <string>
#include "error_handling.h"


Stack::Stack(void (*func)(void*)) {
    top = nullptr;
    f_elementDestructor = func;
}

Stack::~Stack() {
    clear();
}

void Stack::push(void* newData) {
    StackNode* newNode = new StackNode();
    newNode->data = newData;
    newNode->next = top;
    top = newNode;
}

void* Stack::pop() {
    if (isEmpty()) {
        return nullptr;
    }

    StackNode* poppedNode = top;
    void* poppedData = poppedNode->data;
    top = top->next;

    delete poppedNode;
    return poppedData;
}


bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::clear() {
	while (!isEmpty()) {
		void* poppedData = pop();
        f_elementDestructor(poppedData);
	}
}

void Stack::saveToFile(const char* filename, void (*func)(void*, std::ofstream&)) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        displayError("Nie mo¿na otworzyæ pliku do zapisu.");
        return;
    }

    StackNode* current = top;
    while (current != nullptr) {
        func(current->data, file);
        current = current->next;
    }

    file.close();
}

void Stack::loadFromFile(const char* filename, void* (*func)(std::ifstream&)) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        displayError("Nie mo¿na otworzyæ pliku do odczytu.");
        return;
    }

	clear();

    Stack reversedStack = Stack(f_elementDestructor);
    while (true) {
        
        void* data = func(file);
        if (data == nullptr)
            break;

        reversedStack.push(data);
    }

    while (true) {

        void* data = reversedStack.pop();
		if (data == nullptr)
			break;

        push(data);
    }

    file.close();
}
