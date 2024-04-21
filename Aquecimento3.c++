#include <iostream>
#include <vector>
#include <cstdlib> // Para o uso de size_t

#define MAX_INSTANCES 5

class Forno {
public:
    virtual ~Forno() {
        std::cout << "Destrutor de Forno." << std::endl;
    }

    virtual void consultarStatus() const = 0;
};

class FornoEletrico : public Forno {
public:
    void consultarStatus() const override {
        std::cout << "Forno Elétrico está desligado." << std::endl;
    }
};

class FornoGas : public Forno {
public:
    void consultarStatus() const override {
        std::cout << "Forno a Gás está desligado." << std::endl;
    }
};

// Factory Method
Forno* crazyFactory(int type) {
    switch (type) {
        case 1:
            return new FornoEletrico();
        case 2:
            return new FornoGas();
        default:
            return nullptr;
    }
}

int main() {
    std::vector<Forno*> fornos;

    // Cria instâncias de FornoEletrico e FornoGas
    for (size_t i = 0; i < MAX_INSTANCES; ++i) {
        Forno* forno = crazyFactory(rand() % 2 + 1); // Aleatoriamente escolhe tipo 1 ou 2
        fornos.push_back(forno);
    }

    // Apresenta status de cada forno
    for (Forno* forno : fornos) {
        forno->consultarStatus();
    }

    // Libera a memória
    for (Forno* forno : fornos) {
        delete forno;
    }

    return 0;
}
