#include <iostream>
#include <vector>
#include <string>


enum EstadoPago {
    MOROSO,
    ATRASADO,
    PAGADO
};


struct Cliente {
    std::string nombre;
    int unidadesSolicitadas;
    double precioPorUnidad;
    EstadoPago estado;
};


std::string estadoToString(EstadoPago estado) {
    switch (estado) {
        case MOROSO: return "Moroso";
        case ATRASADO: return "Atrasado";
        case PAGADO: return "Pagado";
        default: return "Desconocido";
    }
}


void mostrarFactura(const Cliente& cliente) {
    double total = cliente.unidadesSolicitadas * cliente.precioPorUnidad;


    std::cout << "Cliente: " << cliente.nombre << std::endl;
    std::cout << "Unidades solicitadas: " << cliente.unidadesSolicitadas << std::endl;
    std::cout << "Precio por unidad: $" << cliente.precioPorUnidad << std::endl;
    std::cout << "Estado: " << estadoToString(cliente.estado) << std::endl;
    std::cout << "Total a pagar: $" << total << std::endl;
    std::cout << "-----------------------------" << std::endl;
}


int main() {
    std::vector<Cliente> clientes;
    int numClientes;


    std::cout << "Ingrese el numero de clientes: ";
    std::cin >> numClientes;


    for (int i = 0; i < numClientes; ++i) {
        Cliente cliente;
        int estado;


        std::cout << "Ingrese el nombre del cliente: ";
        std::cin >> cliente.nombre;
       
        std::cout << "Ingrese el numero de unidades solicitadas: ";
        std::cin >> cliente.unidadesSolicitadas;


        std::cout << "Ingrese el precio por unidad: ";
        std::cin >> cliente.precioPorUnidad;


        std::cout << "Ingrese el estado del cliente (0: Moroso, 1: Atrasado, 2: Pagado): ";
        std::cin >> estado;
        cliente.estado = static_cast<EstadoPago>(estado);


        clientes.push_back(cliente);
    }


    std::cout << "-----------------------------" << std::endl;
    std::cout << "FACTURACION DE CLIENTES" << std::endl;
    std::cout << "-----------------------------" << std::endl;


    for (const auto& cliente : clientes) {
        mostrarFactura(cliente);
    }


    return 0;
}
