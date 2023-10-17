#include "interface.h"

#include <iostream>

using std::cout;
using std::endl;

void displayStackElements(Stack& stack) {
    cout << "Elementy stosu:" << endl;

    Stack tempStack = Stack(destroyStudent);
    void* data;
    while ((data = stack.pop()) != nullptr) {
        MyStudent* student = static_cast<MyStudent*>(data);
        displayStudent(student);
        tempStack.push(data);
    }

    while ((data = tempStack.pop()) != nullptr) {
        stack.push(data);
    }
}



void displayMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Dodaj element do stosu" << endl;
    cout << "2. Usun element ze stosu" << endl;
    cout << "3. Wyswietl elementy stosu" << endl;
    cout << "4. Zapisz elementy stosu do pliku" << endl;
    cout << "5. Wczytaj elementy stosu z pliku" << endl;
    cout << "6. Wyjscie" << endl;
    cout << "Wybierz opcje: ";
}
