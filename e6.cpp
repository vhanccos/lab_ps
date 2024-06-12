#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string apellido;
    int edad;
};

int main() {
    Persona p;

    cout << "Ingrese el nombre: ";
    getline(cin, p.nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, p.apellido);

    cout << "Ingrese la edad: ";
    cin >> p.edad;

    cout << "\nLos datos ingresados son:\n";
    cout << p.nombre << ", " << p.apellido << ", " << p.edad << endl;

    return 0;
}
