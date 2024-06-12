#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int diaNacimiento;
    int mesNacimiento;
    int anioNacimiento;
};

const int NUM_PERSONAS = 8;

int main() {
    Persona personas[NUM_PERSONAS];

    cout << "Ingrese los datos de " << NUM_PERSONAS << " personas:\n";
    for (int i = 0; i < NUM_PERSONAS; i++) {
        cout << "Persona " << i+1 << ":\n";
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Día de nacimiento: ";
        cin >> personas[i].diaNacimiento;
        cout << "Mes de nacimiento: ";
        cin >> personas[i].mesNacimiento;
        cout << "Año de nacimiento: ";
        cin >> personas[i].anioNacimiento;
    }

    int mesABuscar;
    do {
        cout << "\nIngrese el número de mes (0 para salir): ";
        cin >> mesABuscar;

        if (mesABuscar != 0) {
            cout << "\nPersonas que cumplen años en el mes " << mesABuscar << ":\n";
            for (int i = 0; i < NUM_PERSONAS; i++) {
                if (personas[i].mesNacimiento == mesABuscar) {
                    cout << personas[i].nombre << " (" << personas[i].diaNacimiento << "/" << personas[i].mesNacimiento << "/" << personas[i].anioNacimiento << ")\n";
                }
            }
        }
    } while (mesABuscar != 0);

    return 0;
}
