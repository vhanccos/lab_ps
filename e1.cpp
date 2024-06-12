#include <iostream>
#include <chrono>
#include <ctime>




struct Fecha {
    int dia;
    int mes;
    int anio;
};


// Función para convertir una estructura Fecha a un objeto std::chrono::system_clock::time_point
std::chrono::system_clock::time_point convertirAFecha(const Fecha& fecha) {
    std::tm tm = {};
    tm.tm_mday = fecha.dia;
    tm.tm_mon = fecha.mes - 1; // En std::tm los meses van de 0 a 11
    tm.tm_year = fecha.anio - 1900; // En std::tm los años se cuentan desde 1900


    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}


// Función para calcular la diferencia en días entre dos fechas
int diasEntreFechas(const Fecha& fecha1, const Fecha& fecha2) {
    auto f1 = convertirAFecha(fecha1);
    auto f2 = convertirAFecha(fecha2);


    auto duracion = std::chrono::duration_cast<std::chrono::seconds>(f2 - f1).count();
    return duracion / (60 * 60 * 24);
}


int main() {
    Fecha fecha1, fecha2;


    std::cout << "Ingrese la primera fecha (dd mm aaaa): ";
    std::cin >> fecha1.dia >> fecha1.mes >> fecha1.anio;


    std::cout << "Ingrese la segunda fecha (dd mm aaaa): ";
    std::cin >> fecha2.dia >> fecha2.mes >> fecha2.anio;


    int diferenciaDias = diasEntreFechas(fecha1, fecha2);


    std::cout << "El numero de dias entre las dos fechas es: " << diferenciaDias << std::endl;


    return 0;
}
