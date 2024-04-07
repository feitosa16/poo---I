#include <iostream>
#include <cmath>

class Potencia {
public:
    // Calcula potência para int base e int expoente
    double calcula(int base, int expoente) {
        std::cout << "Invocado: calcula(int, int)" << std::endl;
        return std::pow(base, expoente);
    }

    // Calcula potência para int base e double expoente
    double calcula(int base, double expoente) {
        std::cout << "Invocado: calcula(int, double)" << std::endl;
        return std::pow(base, expoente);
    }

    // Calcula potência para double base e double expoente
    double calcula(double base, double expoente) {
        std::cout << "Invocado: calcula(double, double)" << std::endl;
        return std::pow(base, expoente);
    }
};

int main() {
    Potencia* potencia = new Potencia();

    std::cout << "Resultado: " << potencia->calcula(2, 3) << std::endl;
    std::cout << "Resultado: " << potencia->calcula(2, 3.5) << std::endl;
    std::cout << "Resultado: " << potencia->calcula(2.5, 3.5) << std::endl;

    delete potencia;
    return 0;
}
