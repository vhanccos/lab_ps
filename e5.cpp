#include <iostream>
#include <string>
using namespace std;

struct Equipo {
    string nombre;
    int victorias;
    int derrotas;
};

struct Baloncesto : public Equipo {
    int perdidasBalon;
    int rebotes;
    string mejorAnotadorTriples;
    int triplesAnotador;
};

struct Futbol : public Equipo {
    int empates;
    int golesFavor;
    string goleador;
    int golesGoleador;
};

void ingresarDatosBaloncesto(Baloncesto &equipo) {
    cout << "Nombre del equipo de baloncesto: ";
    cin.ignore();
    getline(cin, equipo.nombre);
    cout << "Numero de victorias: ";
    cin >> equipo.victorias;
    cout << "Numero de derrotas: ";
    cin >> equipo.derrotas;
    cout << "Numero de perdidas de balon: ";
    cin >> equipo.perdidasBalon;
    cout << "Numero de rebotes cogidos: ";
    cin >> equipo.rebotes;
    cout << "Nombre del mejor anotador de triples: ";
    cin.ignore();
    getline(cin, equipo.mejorAnotadorTriples);
    cout << "Numero de triples del mejor anotador: ";
    cin >> equipo.triplesAnotador;
}

void ingresarDatosFutbol(Futbol &equipo) {
    cout << "Nombre del equipo de futbol: ";
    cin.ignore();
    getline(cin, equipo.nombre);
    cout << "Numero de victorias: ";
    cin >> equipo.victorias;
    cout << "Numero de derrotas: ";
    cin >> equipo.derrotas;
    cout << "Numero de empates: ";
    cin >> equipo.empates;
    cout << "Numero de goles a favor: ";
    cin >> equipo.golesFavor;
    cout << "Nombre del goleador del equipo: ";
    cin.ignore();
    getline(cin, equipo.goleador);
    cout << "Numero de goles del goleador: ";
    cin >> equipo.golesGoleador;
}

void mostrarDatosBaloncesto(const Baloncesto &equipo) {
    cout << "Nombre del equipo de baloncesto: " << equipo.nombre << endl;
    cout << "Numero de victorias: " << equipo.victorias << endl;
    cout << "Numero de derrotas: " << equipo.derrotas << endl;
    cout << "Numero de perdidas de balon: " << equipo.perdidasBalon << endl;
    cout << "Numero de rebotes cogidos: " << equipo.rebotes << endl;
    cout << "Mejor anotador de triples: " << equipo.mejorAnotadorTriples << endl;
    cout << "Numero de triples del mejor anotador: " << equipo.triplesAnotador << endl;
}

void mostrarDatosFutbol(const Futbol &equipo) {
    cout << "Nombre del equipo de futbol: " << equipo.nombre << endl;
    cout << "Numero de victorias: " << equipo.victorias << endl;
    cout << "Numero de derrotas: " << equipo.derrotas << endl;
    cout << "Numero de empates: " << equipo.empates << endl;
    cout << "Numero de goles a favor: " << equipo.golesFavor << endl;
    cout << "Goleador del equipo: " << equipo.goleador << endl;
    cout << "Numero de goles del goleador: " << equipo.golesGoleador << endl;
}

void listarMejoresAnotadoresTriples(const Baloncesto equipos[], int numEquipos) {
    cout << "\nListado de los mejores anotadores de triples de cada equipo:\n";
    for (int i = 0; i < numEquipos; ++i) {
        cout << "Equipo: " << equipos[i].nombre << ", Mejor anotador de triples: " << equipos[i].mejorAnotadorTriples << endl;
    }
}

void maximoGoleadorFutbol(const Futbol equipos[], int numEquipos) {
    int maxGoles = -1;
    string goleador;
    for (int i = 0; i < numEquipos; ++i) {
        if (equipos[i].golesGoleador > maxGoles) {
            maxGoles = equipos[i].golesGoleador;
            goleador = equipos[i].goleador;
        }
    }
    cout << "\nMaximo goleador de la liga de futbol: " << goleador << " con " << maxGoles << " goles.\n";
}

void equipoGanadorFutbol(const Futbol equipos[], int numEquipos) {
    int maxPuntos = -1;
    string equipoGanador;
    for (int i = 0; i < numEquipos; ++i) {
        int puntos = equipos[i].victorias * 3 + equipos[i].empates;
        if (puntos > maxPuntos) {
            maxPuntos = puntos;
            equipoGanador = equipos[i].nombre;
        }
    }
    cout << "Equipo ganador de la liga de futbol: " << equipoGanador << " con " << maxPuntos << " puntos.\n";
}

void equipoGanadorBaloncesto(const Baloncesto equipos[], int numEquipos) {
    int maxVictorias = -1;
    string equipoGanador;
    for (int i = 0; i < numEquipos; ++i) {
        if (equipos[i].victorias > maxVictorias) {
            maxVictorias = equipos[i].victorias;
            equipoGanador = equipos[i].nombre;
        }
    }
    cout << "Equipo ganador de la liga de baloncesto: " << equipoGanador << " con " << maxVictorias << " victorias.\n";
}

int main() {
    int numEquiposBaloncesto, numEquiposFutbol;

    cout << "Ingrese el numero de equipos de baloncesto: ";
    cin >> numEquiposBaloncesto;
    cout << "Ingrese el numero de equipos de futbol: ";
    cin >> numEquiposFutbol;

    Baloncesto equiposBaloncesto[numEquiposBaloncesto];
    Futbol equiposFutbol[numEquiposFutbol];

    for (int i = 0; i < numEquiposBaloncesto; ++i) {
        cout << "\nIngresando datos para el equipo de baloncesto " << i + 1 << endl;
        ingresarDatosBaloncesto(equiposBaloncesto[i]);
    }

    for (int i = 0; i < numEquiposFutbol; ++i) {
        cout << "\nIngresando datos para el equipo de futbol " << i + 1 << endl;
        ingresarDatosFutbol(equiposFutbol[i]);
    }

    cout << "\nDatos de los equipos de baloncesto:\n";
    for (int i = 0; i < numEquiposBaloncesto; ++i) {
        mostrarDatosBaloncesto(equiposBaloncesto[i]);
        cout << "-----------------------------\n";
    }

    cout << "\nDatos de los equipos de futbol:\n";
    for (int i = 0; i < numEquiposFutbol; ++i) {
        mostrarDatosFutbol(equiposFutbol[i]);
        cout << "-----------------------------\n";
    }

    listarMejoresAnotadoresTriples(equiposBaloncesto, numEquiposBaloncesto);
    maximoGoleadorFutbol(equiposFutbol, numEquiposFutbol);
    equipoGanadorFutbol(equiposFutbol, numEquiposFutbol);
    equipoGanadorBaloncesto(equiposBaloncesto, numEquiposBaloncesto);

    return 0;
}
