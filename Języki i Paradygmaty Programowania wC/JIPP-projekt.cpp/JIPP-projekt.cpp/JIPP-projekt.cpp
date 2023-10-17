#include "interface.h"
#include "error_handling.h"

#include <iostream>

using  std::cin;
using  std::cout;

int main() {
    Stack stack = Stack(destroyStudent);

    while (true) {
        displayMenu();

        int option;
        cin >> option;

        switch (option) {
        case 1: {
            char name[100];
            int birthYear;
            int program;

            cout << "Podaj nazwisko: ";
            cin.ignore();
            cin.getline(name, 100);

            cout << "Podaj rok urodzenia: ";
            cin >> birthYear;

            cout << "Podaj kierunek studiow (0-Informatyka, 1-Matematyka, 2-Fizyka, 3-Historia, 4-Anglistyka): ";
            cin >> program;

            MyStudent* student = createStudent(name, birthYear, static_cast<StudyProgram>(program));
            stack.push(student);

            displayMessage("Dodano studenta do stosu.");
            break;
        }
        case 2: {
            MyStudent* student = static_cast<MyStudent*>(stack.pop());
            if (student != nullptr) {
                displayMessage("Usunieto studenta ze stosu:");
                displayStudent(student);
                destroyStudent(student);
            }
            else {
                displayError("Stos jest pusty.");
            }
            break;
        }
        case 3:
            displayStackElements(stack);
            break;
        case 4: {
            char filename[100];
            cout << "Podaj nazwe pliku: ";
            cin.ignore();
            cin.getline(filename, 100);
            stack.saveToFile(filename, saveStudent);
            break;
        }
        case 5: {
            char filename[100];
            cout << "Podaj nazwe pliku: ";
            cin.ignore();
            cin.getline(filename, 100);
            stack.loadFromFile(filename, loadStudent);
            break;
        }
        case 6:
            displayMessage("Program zakonczyl dzialanie.");
            return 0;
        default:
            displayError("Nieprawidlowa opcja. Wybierz ponownie.");
            break;
        }
    }
}
