#include <iostream>
#include "my_poligon.h"

using std::cout;
using std::endl;

int main() {

    cout << "  Kolokwium zaliczeniowe  - wariant 1 -  Gabriela Rączka  " << endl << endl; 

    // stwozrenie trojkata
    MyPoint* points1 = new MyPoint[3];

    points1[0] = MyPoint("A", 1.0, 1.0);
    points1[1] = MyPoint("B", 3.0, 1.0);
    points1[2] = MyPoint("C", 1.0, 4.0);
    MyPoligon* poligon1 = new MyPoligon("Triangle ABC", points1, 3);

    // wyswietlenie danych trójkata
    cout << "Poligon name: " << poligon1->getName() << endl;
    cout << " Number of points: " << poligon1->getNumPoints() <<endl;
    MyPoint* points1_copy = poligon1->getPoints();
        for (size_t i = 0; i < poligon1->getNumPoints() ; i++) {
            cout << points1_copy[i].getName() <<": (" << points1_copy[i].getX() << ", " << points1_copy[i].getY() << ")" << endl;
        }
    cout << endl;

    //   zwalnianie pamięci dla trójkąta
    delete[] points1;

    delete poligon1;


    // tworzene czworokąta

    MyPoint* points2 = new MyPoint[4];
    points2[0] = MyPoint("A", -10.0, -10.0);
    points2[1] = MyPoint("B", 3.0, -10.0);
    points2[2] = MyPoint("C", 3.0, 3.0);
    points2[3] = MyPoint("D", -10.0, 3.0);

    MyPoligon* poligon2 = new MyPoligon("Quadrilteral ABCD", points2, 4);


    //wyświetlenie danych o czworokacie
    cout << "Poligon name: " << poligon2->getName() <<endl ;
    cout << "Number of pionts: " << poligon2->getNumPoints() << endl;
    MyPoint* points2_copy = poligon2->getPoints();
        for (size_t i = 0; i  < poligon2->getNumPoints(); i++) {
            cout << points2_copy[i].getName() << ": (" << points2_copy[i].getX() << ", "<< points2_copy[i].getY() << ")" << endl;
        }
    cout << endl;

    // zwalnianie pamięci dla czworokąta
    delete[] points2;
    delete poligon2;

    return 0;

} 

    
