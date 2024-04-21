#include <iostream>
#include <vector>
#include <cstdlib> // Para o uso de size_t

#define MAX_INSTANCES 5

class SerVivo {
public:
    virtual ~SerVivo() {
        std::cout << "Destrutor de SerVivo." << std::endl;
    }

    virtual void consultarStatus() const = 0;
};

class Animal : public SerVivo {
public:
    void consultarStatus() const override {
        std::cout << "Animal está dormindo." << std::endl;
    }
};

class Planta : public SerVivo {
public:
    void consultarStatus() const override {
        std::cout << "Planta está realizando fotossíntese." << std::endl;
    }
};

// Factory Method
SerVivo* crazyFactory(int type) {
    switch (type) {
        case 1:
            return new Animal();
        case 2:
            return new Planta();
        default:
            return nullptr;
    }
}

int main() {
    std::vector<SerVivo*> seresVivos;

    // Cria instâncias de Animal e Planta
    for (size_t i = 0; i < MAX_INSTANCES; ++i) {
        SerVivo* serVivo = crazyFactory(rand() % 2 + 1); // Aleatoriamente escolhe tipo 1 ou 2
        seresVivos.push_back(serVivo);
    }

    // Apresenta status de cada ser vivo
    for (SerVivo* ser : seresVivos) {
        ser->consultarStatus();
    }

    // Libera a memória
    for (SerVivo* ser : seresVivos) {
        delete ser;
    }

    return 0;
}
