#include <iostream>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    string direccion;
    string telefono;
    int edad;
};

Persona personas[50];
int numPersonas = 0;

void mostrarMenu() {
    cout << "\nMenú:\n";
    cout << "1. Mostrar la lista de todos los nombres\n";
    cout << "2. Mostrar las personas de una cierta edad\n";
    cout << "3. Mostrar las personas cuya inicial sea la que el usuario indique\n";
    cout << "4. Salir\n";
    cout << "Elija una opción (1-4): ";
}

void mostrarListaNombres() {
    cout << "\nLista de nombres:\n";
    for (int i = 0; i < numPersonas; i++) {
        cout << personas[i].nombre << "\n";
    }
}

void mostrarPersonasPorEdad() {
    int edadBuscada;
    cout << "\nIngrese la edad a buscar: ";
    cin >> edadBuscada;

    cout << "\nPersonas de " << edadBuscada << " años:\n";
    for (int i = 0; i < numPersonas; i++) {
        if (personas[i].edad == edadBuscada) {
            cout << personas[i].nombre << ", " << personas[i].direccion << ", " << personas[i].telefono << "\n";
        }
    }
}

void mostrarPersonasPorInicial() {
    char inicialBuscada;
    cout << "\nIngrese la inicial a buscar: ";
    cin >> inicialBuscada;

    cout << "\nPersonas cuya inicial es '" << inicialBuscada << "':\n";
    for (int i = 0; i < numPersonas; i++) {
        if (toupper(personas[i].nombre[0]) == toupper(inicialBuscada)) {
            cout << personas[i].nombre << ", " << personas[i].direccion << ", " << personas[i].telefono << "\n";
        }
    }
}

int main() {
    int opcion;
    string nombreTemporal;

    do {
        cout << "Ingrese los datos de las personas (presione Enter para terminar):\n";
        do {
            if (numPersonas >= 50) {
                cout << "Se ha alcanzado el límite de 50 personas. No se pueden agregar más.\n";
                break;
            }
            cout << "\nPersona " << (numPersonas + 1) << ":\n";
            cout << "Nombre: ";
            getline(cin, personas[numPersonas].nombre);
            if (personas[numPersonas].nombre.empty()) break;
            cout << "Dirección: ";
            getline(cin, personas[numPersonas].direccion);
            cout << "Teléfono: ";
            getline(cin, personas[numPersonas].telefono);
            cout << "Edad: ";
            cin >> personas[numPersonas].edad;
            cin.ignore(); // Ignorar el salto de línea
            numPersonas++;
        } while (!personas[numPersonas-1].nombre.empty());

        do {
            mostrarMenu();
            cin >> opcion;
            cin.ignore(); // Ignorar el salto de línea

            switch (opcion) {
                case 1:
                    mostrarListaNombres();
                    break;
                case 2:
                    mostrarPersonasPorEdad();
                    break;
                case 3:
                    mostrarPersonasPorInicial();
                    break;
                case 4:
                    cout << "¡Adiós!\n";
                    break;
                default:
                    cout << "Opción inválida. Intente de nuevo.\n";
                    break;
            }
        } while (opcion != 4);
    } while (opcion != 4);

    return 0;
}
