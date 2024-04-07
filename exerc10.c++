#include <iostream>
#include <vector>
#include <string>

class Forno {
public:
    virtual void getStatus() const {
        std::cout << "Forno genérico cozinhando" << std::endl;
    }

    virtual ~Forno() {}
};

class FornoEletrico : public Forno {
public:
    void getStatus() const override {
        std::cout << "Forno elétrico cozinhando" << std::endl;
    }
};

class FornoAGas : public Forno {
public:
    void getStatus() const override {
        std::cout << "Forno a gás cozinhando" << std::endl;
    }
};

class FornoALenha : public Forno {
public:
    void getStatus() const override {
        std::cout << "Forno à lenha cozinhando" << std::endl;
    }
};

int main() {
    std::vector<Forno*> fornos;

    fornos.push_back(new FornoEletrico());
    fornos.push_back(new FornoAGas());
    fornos.push_back(new FornoALenha());

    for (Forno* forno : fornos) {
        forno->getStatus();
    }

    // Desalocando a memória
    for (Forno* forno : fornos) {
        delete forno;
    }

    return 0;
}
